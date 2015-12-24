# BDD-Converter.pl Version 1.0
#
# by Drew Diamantoukos
#
# Usage: `perl BDD-Converter.pl < name-of-bdd-file`
# Output: A cpp file with the name as the-first-line-of-the-bdd-file.cpp
#
# To more rapidly generate Catch Unit Testing files using Behavior Driven Design syntax.
# Uses a custom filetype, bdd, to allow a programmer to write a simple specification with the BDD syntax.

use strict;
use warnings;
use String::Util qw(trim);

my $line;
my $filename = <STDIN>;

# Check for whitespace in filename.
if ( $filename =~ /\h/ ) {
    printf "Error: 1st line must contain the filename as a single word with no whitespace. %s does not match.\n", $filename;
    exit;
}

# Remove newline.
chomp($filename);
$filename = $filename . ".cpp";

printf "Creating new file '%s'\n", $filename;

unless(open FILE, '>'.$filename) {
	die "\nUnable to create $filename\n";
}

my %num_tabs = (
	SCENARIO 	=> 0,
	GIVEN    	=> 1,
	WHEN 	 	=> 2,
	AND_WHEN 	=> 2,
	THEN        => 3,
	AND_THEN 	=> 3,
);

my $cur_indent_level = -1; 
my $prev_indent_level = -1,
my $brackets_remaining = 0;

while(<STDIN>) {
	my ($label, $description) = split /[\s]+/, trim($_), 2;
	if ($label and $description) {
		if ($label !~ "(SCENARIO|GIVEN|WHEN|AND_WHEN|THEN|AND_THEN)") {
			die "\nLabel '$label' must be either SCENARIO, GIVEN, WHEN, AND_WHEN, THEN, or AND_THEN.\n";
		}

		chomp($description);

		$prev_indent_level = $cur_indent_level;
		$cur_indent_level = $num_tabs{$label};

		# 
		if ($prev_indent_level >= $cur_indent_level) {
			my $indent_diff = $prev_indent_level - $cur_indent_level;
			printTabs($prev_indent_level + 1);
			print FILE "\n";
			for (my $i = 0; $i <= $indent_diff; $i++) {
				printTabs($prev_indent_level - $i);
				print FILE "}\n";
				$brackets_remaining--;
			}
		} 

		if ($label ne "SCENARIO") {
			print FILE "\n";
		}

		printTabs($cur_indent_level);
		
		my $line_end = ") {\n";
		if ($label eq "SCENARIO") {
			my $tags;
			($description, $tags) = split /[[]+/, $description, 2;
			$tags = "[" . $tags;
			$line_end = ", \"$tags\"" . $line_end;
			$description = trim($description);
		}

		print FILE "$label( \"$description\"" . $line_end;
		$brackets_remaining++;
	}
	else {
		die "\nUnable to parse line: $_\n";
	}
}

printTabs($cur_indent_level + 1);
print FILE "\n";
for (my $i = 0; $i < $brackets_remaining; $i++) {
	printTabs($cur_indent_level - $i);
	print FILE "}\n";
}
close FILE;

unless(open FILE, '>>'.$filename) {
	die "\nUnable to open $filename for final touches!\n";
}

truncate(FILE, (stat $filename)[7] - 2);

close FILE;

print "Done!\n";

sub printTabs {
	for (my $i = 0; $i < $_[0]; ++$i) {
		print FILE "\t";
	}
}
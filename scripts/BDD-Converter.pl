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

my $indent_level = -1;

while(<STDIN>) {
	my ($label, $description) = split /[\s]+/, trim($_), 2;
	if ($label and $description) {
		if ($label !~ "(SCENARIO|GIVEN|WHEN|AND_WHEN|THEN|AND_THEN)") {
			die "\nLabel '$label' must be either SCENARIO, GIVEN, WHEN, AND_WHEN, THEN, or AND_THEN.\n";
		}

		chomp($description);

		for (my $i=0; $i < $num_tabs{$label}; ++$i) {
			print FILE "\t"
		}

		$indent_level = $num_tabs{$label};

		my $line_end = ") {\n";
		if ($label eq "SCENARIO") {
			my $tags;
			($description, $tags) = split /[[]+/, $description, 2;
			$tags = "[" . $tags;
			$line_end = ", \"$tags\"" . $line_end;
			$description = trim($description);
		}

		print FILE "$label( \"$description\"" . $line_end;
	}
	else {
		die "\nUnable to parse line: $_\n";
	}
}

close FILE;

unless(open FILE, '>>'.$filename) {
	die "\nUnable to open $filename for final touches!\n";
}

truncate(FILE, (stat $filename)[7] - 2);

close FILE;

print "Done!\n";
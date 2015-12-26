# Gutterati Style Guide

## Goal
To try and keep code and documentation both clean and consistent with a standard set of conventions.
This will also help in areas like scripting, code analysis, reports and more.

### Language Agnostic Rules
* Use "TO-DO:" (minus quotes) to mark something that will need attention in the future.
* For bracket style, we will be using a mix of [K&R Style](https://en.wikipedia.org/wiki/Indent_style#K.26R_style)  and [Stroustrup Style](https://en.wikipedia.org/wiki/Indent_style#Variant:_Stroustrup). Namely, using most of the bracket styling of K&R with the Stroustrup version of if-else statements and small functions defined in the same line.

    For example:
    
    ```c++
    while (friends.standingInLine() == true) {
        this.cry(yourTears);
    }

    if (this.isBold()) {
        this.say("Would you be mine?");
    }
    else {
        this.continueDowner();
    }

    class Tale
    {
        private:
            bool m_isHeady;

        public:
            bool getIsHeady() { return m_isHeady; } // Note the 1-space padding between the curly brackets.
    };
    ```

* Indentation is 4 spaces wide, no tab characters to prevent editor conflicts/weirdness.

### C++ Rules
* We will be using Doxygen to auto-generate reference material for the majority of the code base. Further, we are using the JavaDoc style for comments.
    * As a result, this should be at the top of all files that hope to leverage it:
    ```c++
        /** 
         *  @file
         *  @brief Brief description of the file.
         *  More detailed information will go here if necessary.
         **/
    ```
    * And here is a method:
    ```c++
        /**
         * @brief Brief description of the method.
         *
         * More detailed info can go here.
         * @param weeks_here How many weeks I've still been here.
         **/
        int takeSlowTrain(int weeks_here)
    ```
* Filenames and classes Will have each word start with a upper-case letter, like GutteratiTestMain.cpp.
* Functions/methods/etc will be camel case.
* Member fields of a class will be prefixed with "m_" (Minus quotes).

### Project Documentation Rules
* Filenames will be all lower-case with a dash ('-') to separate words. For instance, his file is 'style-guide.md'

## Suggestions
As always, I'm welcome to suggestions on alternative styles, corrections, etc.

## TO-DO: Formatting Program
In the future I will be investigating ways to further help code formatting, for example the clang formatting tool or cpplint.
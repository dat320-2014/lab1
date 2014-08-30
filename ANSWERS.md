##Important Instructions

Please preserve the structure of this file, as it will subjected to *partial*
automatic analysis. **Only insert your answers by replacing the text `YOUR ANSWER HERE`; do not delete anything else.** 

Please use [markdown](https://help.github.com/articles/markdown-basics) formating to typeset code and Unix commands with the backtick character, for example, `ls -la`, or if you want to write code blocks, each line should be indented with four spaces, as done in the code below:

    #include <stdio.h>
    
    int main(void) {
    	printf("Hello, world!\n");
    	return 0;
    }


##Exercises from the online Unix tutorial

###Exercise 1a

Make another directory inside the `unixstuff` directory called `backups`

**Answer:** *$cd unixstuff $mkdir backups*

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** *$cd changes the directory to a chosen path, $ls lists content in working directory, $pwd prints working directory path*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** *$cp science.txt science.bak*

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** *$mkdir tempstuff $rmdir tempstuff*

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** *$cat > list2 ->then type content -> $cat list2*

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** *% cat list1 list2 | grep p | sort*

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** *$chmod go-rwx science.txt -> $chmod u-rw backups*

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** *-r (recursive) removes a directory and all its content. ex: $rm -r foobar*
1. What is the command used to display the manual pages for any command?
  - **Answer:** *$man [commandName] -> ex: man cat*
1. What command will show the first 5 lines of an input file?
  - **Answer:** *$head -5 [fileName]*
1. What command can be used to rename a file?
  - **Answer:** *$mv [fileOld] [fileNew] *
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** *$ls -a*
1. What will the command `cat -n file` do?
  - **Answer:** *number all output lines*
1. What will the command `echo -n hello` do?
  - **Answer:** *it will not output the trailing newline*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** *$who*
1. How do you change password on your account?
  - **Answer:** *$passwd*
1. How can you list a file in reverse order?
  - **Answer:** *$ls -r*
1. What does the `less` command do?
  - **Answer:** *The command less writes the contents of a file to the screen one page at a time. ex: $less science.txt*
1. With `less` how do you navigate?
  - **Answer:** *arrowkey up and down to show next/previous line, enter to show next line, space to show next page, shift+q to quit reading*
1. What command will display the running processes of the current user?
  - **Answer:** *$ps*
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** *$ ps | sort -rk 1,1 | head -n 2*

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** *assuming the file has a name: enter command mode and type $:w -> assuming the file does not have a name: enter command mode and type $:w [fileName]*
1. What command/key is used to start entering text?
  - **Answer:** *'i' to enter insert mode, 'ESC' to exit insert mode.*
1. What are the different modes the editor can be in?
  - **Answer:** *INSERT and COMMAND*
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *:# line number # of the file*
1. What will `dd` command do (in command-mode)?
  - **Answer:** *it deletes the whole line where the cursor is*
1. How do you undo the most recent changes?
  - **Answer:** *type 'u', typing 'ctrl+r' is redo*
1. How do you move back one word?
  - **Answer:** *type 'b' to move back one word at a time, type 'w' to move forward one word at a time.*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** *$gcc hello.c -c ->this makes an object file. An object file is a temporary step in the development of a larger program. One may create several object files for later use and then combine them together as an .exe file. An object file is not a final product but a step along the way.*
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** *$gcc listing2 -DDEBUG -o listing 2 ->When run listing2 will run what is inside #ifdef and #endif, thus printing to console 'some smart debug comment \n Hello, world!'. 
  We use the same command on listing 3 but we change the code to include:
      #ifdef
	      debug = 1;
	  #endif
this will ensure that the debug code is run properly.*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *With use of control structures, the debug code is hidden and not available for others. In listing3 the debug code is open for all to read. In this way one can hide debug code with use of control structures.*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *$gcc hello.c -Wl, -Map=hello.map -o hello.exe ->The -Map flag is responsible for the creation of the map file.*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *The top of the MAP file contains the module name, the timestamp indicating the link of the project, and the preferred load address. After the header comes the section information that shows which sections the linker brought in from the various OBJ and LIB files. After the section information, you get the public function information.
The important parts of the public function information are the function names and the information in the Rva+Base column, which is the starting address of the function.
The public function part is followed by the line information After this, you will get the export information if your project contains exported functions and you included "/".*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *To generate these files, you have to change the returns to: return 0, return 1, return :*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *
    $gcc hello.c -save-temps-o hello
	$vim hello.c {forandrer doubles til floats}
	$gcc hello.c -save-temps-o hello
	 //Gives equal assembly code as before.*
1. How does `make` know if a file must be recompiled?
  - **Answer:** *make checks the last modified date*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *When executed, make reads the makefile and sets up a table of file dependencies and processing rules for the desired target file. It then examines the dates on each file to see which have been changed since the target file was last made. If a file has been changed, the other files dependent on it are re-	 made, starting at the lowest level and proceeding up until the final target file is correctly remade.
  
in short: $make -f mymakefile*

1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** * #include guard, sometimes called a macro guard, is a particular construct used to avoid the problem of double inclusion when dealing with the include directive.
  
  File 'grandfather.h'
    ifndef GRANDFATHER_H
    define GRANDFATHER_H
 
    struct foo {
     int member;
    };
 
    endif /* GRANDFATHER_H */

File 'father.h'
    include "grandfather.h"
	
File 'child.c'
    include "grandfather.h"
    include "father.h"	
	
Here, the 1st. inclusion of "grandfather.h" causes the macro GRANDFATHER_H to be defined. Then, when "child.c" includes "grandfather.h" the second time, the #ifndef test returns false, and the preprocessor skips down to the #endif, thus avoiding the second definition of struct foo. The program compiles correctly.
	*

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
	}



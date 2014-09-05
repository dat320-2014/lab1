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

**Answer:** * `mkdir unixstuff/backups` *

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** * `cd` - Change current directory to your HOME directory; `ls` - list a directory contents; `pwd` - print name of current/working directory;*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** * `cp science.txt science.bak` *

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** * `mkdir tempstuff`; `rmdir tempstuff` *

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** *
    `cat > list2`
    orange
    plum
    mango
    grapefruit
    `cat list2`
    orange
    plum
    mango
    grapefruit
    *

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** * `cat list1 list2 | grep p | sort` *

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** * `chmod go-rwx science.txt` *

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** * `rm -r dirname` `-r` remove directories and their contents recursively *
1. What is the command used to display the manual pages for any command?
  - **Answer:** * `man COMANDNAME` or `COMANDNAME --help` *
1. What command will show the first 5 lines of an input file?
  - **Answer:** * `head -5 filename` *
1. What command can be used to rename a file?
  - **Answer:** * `rm filename` *
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** * ` ls -a` *
1. What will the command `cat -n file` do?
  - **Answer:** *Number all output lines*
1. What will the command `echo -n hello` do?
  - **Answer:** * `-n` do not output the trailing newline*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** * `who` *
1. How do you change password on your account?
  - **Answer:** * `passwd` then enter current password, then new pass *
1. How can you list a file in reverse order?
  - **Answer:** * `sort -r filename` *
1. What does the `less` command do?
  - **Answer:** *Write a file to a screen by a page at a time*
1. With `less` how do you navigate?
  - **Answer:** *You can navigate with arrows, pgup, pgdn and spase;
  e  ^E  j  ^N  CR  -  Forward  one line   (or N lines).
  y  ^Y  k  ^K  ^P  -  Backward one line   (or N lines).
  f  ^F  ^V  SPACE  -  Forward  one window (or N lines).
  b  ^B  ESC-v      -  Backward one window (or N lines).
  z                 -  Forward  one window (and set window to N).
  w                 -  Backward one window (and set window to N).
  ESC-SPACE         -  Forward  one window, but don't stop at end-of-file.
  d  ^D             -  Forward  one half-window (and set half-window to N).
  u  ^U             -  Backward one half-window (and set half-window to N).
  ESC-)  RightArrow -  Left  one half screen width (or N positions).
  ESC-(  LeftArrow  -  Right one half screen width (or N positions).
  F                    Forward forever; like "tail -f".
  *
1. What command will display the running processes of the current user?
  - **Answer:** * ` ps -U user -u user u` *
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** * ` ps aux --sort=-pcpu ` *

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** * in COMMAND mode `:w filename` *
1. What command/key is used to start entering text?
  - **Answer:** *in COMMAMD mode `i` *
1. What are the different modes the editor can be in?
  - **Answer:** * COMMAND or INSERT mode *
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *in COMMAMD mode  :4 *
1. What will `dd` command do (in command-mode)?
  - **Answer:** *delete the whole line thet cursor is at*
1. How do you undo the most recent changes?
  - **Answer:** * `u` *
1. How do you move back one word?
  - **Answer:** * CTRL + left arrow*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** * `gcc -c hello.c -o hello.o` *
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** * `gcc -DDEBUG Listing_2.c -o Listing_2` by this way you defined variable `DEBUG`. After that compelator include debugging part to executable file. In Listing 3 debugging part are always in executable file, but you should define variable `debug` during runing the program*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *Listing_2 is an example of "Conditional debugging": it's mean that you should define a variable during compilation.
    listing_3 - example of "Selectable debugging": it's mean that you should define a variable during runing the program*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *gcc listing2.c -o listing2 -Wl,-Map=listing2.map*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *YOUR ANSWER HERE*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *
    #include <stdio.h>
    int w;           /* .bss     */
    int i = 1;       /* .data    */
    const int S = 3; /* .rodata  */
    int main(void)
    {
        printf("Hello, world!\n");
        return 0;
    }
*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** * ` gcc -O2 -S -c hello.c ` *
1. How does `make` know if a file must be recompiled?
  - **Answer:** *if the executable file is older then any of source files, than it should be recompiled*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** * `make -f mymakefile` *
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** * `#include file.h`  used to avoid the problem of double inclusion when dealing with the include directive. *

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
	}



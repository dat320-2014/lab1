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

**Answer:** mkdir backups

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** ls -al 
cd unixstuff 
pwd 
cd ~ 
cd ~/unixstuff/backups 

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** cp science.txt science.bak

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** mkdir tempstuff 
rmdir tempstuff

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** cat > list2
orange
plum
mango
grapefruit
^D
cat list2

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** cat list1 list2 | grep p | sort

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** chmod go -w science.txt
ls -l
chmod 0777 backups

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** rm -rf 
1. What is the command used to display the manual pages for any command?
  - **Answer:** man command
1. What command will show the first 5 lines of an input file?
  - **Answer:** head -5 file
1. What command can be used to rename a file?
  - **Answer:** mv
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** ls -a
1. What will the command `cat -n file` do?
  - **Answer:** view content of file with numbered lines
1. What will the command `echo -n hello` do?
  - **Answer:** display hello but not on a seperate line
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** who
1. How do you change password on your account?
  - **Answer:** passwd (or passwd user)
1. How can you list a file in reverse order?
  - **Answer:** tac file
1. What does the `less` command do?
  - **Answer:** The command less writes the contents of a file onto the screen a page at a time.
1. With `less` how do you navigate?
  - **Answer:** Press the [space-bar] if you want to see another page, and type [q] if you want to quit reading.
1. What command will display the running processes of the current user?
  - **Answer:** ps x
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** top

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** :w
1. What command/key is used to start entering text?
  - **Answer:** i
1. What are the different modes the editor can be in?
  - **Answer:** command mode, insert mode, command line mode
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** :4
1. What will `dd` command do (in command-mode)?
  - **Answer:** delete line
1. How do you undo the most recent changes?
  - **Answer:** press u
1. How do you move back one word?
  - **Answer:** b

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** gcc -c 
		the object file contains the machine code for the input file, the object file does not contain addresses of external functions and needs to be linked to be able to run. The object file can be compared to a library.  
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** listing 2 debug enabled: gcc -D DEBUG input.c -o filename
                listing 2 debug disabled: gcc input.c -o filename
                listing 3 debug enabled: compile normally with gcc input.c -o output, but set int debug = 1; in the code
                listing 3 debug disabled: comiple normally with gcc input.c -o output 

1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** 
pros using #ifdef DEBUG:
debug code is dropped from executable unless debug flag is set by compiler making the executable smaller
cons:
you have no way to extract/display debug info at runtime using a debugger

pros using int debug = 0:
debug code is accessible at runtime unless the gcc -O flag is used
cons:
unnessesary data makes the file size larger


1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** gcc -o filename -Wl,-Map=mapname.map input.c
		the linker ld produces the map file
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** from man ld:
           A link map provides information about the link,
           including the following:
           ·   Where object files are mapped into memory.
           ·   How common symbols are allocated.
           ·   All archive members included in the link, with a mention of the symbol which caused the
               archive member to be brought in.
           ·   The values assigned to symbols.
.text contains the code
.data contains global tables, variables, etc
.bss contains uninitialized arrays, variables etc
.rodata contains strings
.comment & .note contains comments put by the linker/compiler
.stab & .stabstr contains debugging symbols etc


1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** 
#include <stdio.h>
/* These are both global vars going into .data */
int uninitialized_int; //.bss
char string[]="somestring"; //.rodata



int main(void)
{
printf("Hello, world!\n");
return 0;
}


1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** 
double  moves the data with movsd and multiplies with mulsd 
float moves the data with movss and multiplies with mulss
Other than that the functions looks exactly the same

mulsd: MULSD xmm1, xmm2/m64 Multiply the low double-precision floating-point value in xmm2/mem64 by low double-precision floating-point value in xmm1.
mulss: MULSS xmm1, xmm2/m32 Multiply the low single-precision floating-point value in xmm2/mem by the low single-precision floating-point value in xmm1.
source: 
http://www.jaist.ac.jp/iscenter-new/mpc/altix/altixdata/opt/intel/vtune/doc/users_guide/mergedProjects/analyzer_ec/mergedProjects/reference_olh/mergedProjects/instructions/instruct32_hh/vc211.htm
http://www.jaist.ac.jp/iscenter-new/mpc/altix/altixdata/opt/intel/vtune/doc/users_guide/mergedProjects/analyzer_ec/mergedProjects/reference_olh/mergedProjects/instructions/instruct32_hh/vc212.htm

In other words: double uses 64bit integers while float uses 32bit
1. How does `make` know if a file must be recompiled?
  - **Answer:** it checks the file modification date
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** make -f mymakefile
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** an include guard is a way to prevent files to get included more than once.
its implemented using special pre-processor code:

#ifndef SOMEFILE_H
#define SOMEFILE_H
...
#endif

The way it works is that it checks if SOMEFILE_H is defined, and if its not run the code between #define and #endif. If the file is included twice, SOMEFILE_H will already be defined when running the 2nd inclusion, causing the code below not the be compiled twice. 


##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
	/* Requires pointers */

    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
	/* There is a library for doing this */	
}



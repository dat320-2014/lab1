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

**Answer:** cd unixstuff/backups
		pwd: /home/stud/brynjulf/unixstuff/backups

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** cp science.txt science.bak . 

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** mkdir tempstuff
		rmdir tempstuff

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** cat > list 2
		orange
		plum
		mango
		grapefruit

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** cat list1 list2 | grep p | sort 
		plum
		grapefruit

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** chmod go-rw science.txt
		chmod go-rwx backups

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** dir
1. What is the command used to display the manual pages for any command?
  - **Answer:** man
1. What command will show the first 5 lines of an input file?
  - **Answer:** head -5 filename
1. What command can be used to rename a file?
  - **Answer:** mv filename newfilename 
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** -a 
1. What will the command `cat -n file` do?
  - **Answer:** output the lines with line numbers
1. What will the command `echo -n hello` do?
  - **Answer:** displays hello before newline 
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** ls ~/.. 
1. How do you change password on your account?
  - **Answer:** passwd 
1. How can you list a file in reverse order?
  - **Answer:** sort -r 
1. What does the `less` command do?
  - **Answer:** allows for faster reading/navigating in a file than vi would
1. With `less` how do you navigate?
  - **Answer:** w - next window, z - previous window etc etc 
1. What command will display the running processes of the current user?
  - **Answer:** ps 
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** top

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** `w` 
1. What command/key is used to start entering text?
  - **Answer:** `i` 
1. What are the different modes the editor can be in?
  - **Answer:** insert, command
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** `:4` or `:set 4`
1. What will `dd` command do (in command-mode)?
  - **Answer:** deletes the whole line at the cursor 
1. How do you undo the most recent changes?
  - **Answer:** `u` 
1. How do you move back one word?
  - **Answer:** `b` 

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** `gcc -c hello.c -o hello.o` ,the compiler creates an object file for each source file, before linking them together, into the final executable
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** Enabling debugging in listing 2 is done by passing -DDEBUG in command line, in listing 3 the debug is enabled at runtime
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *YOUR ANSWER HERE*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** `gcc file.c -Wl,-Map file.map`, map link
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** .data = initialized, .bss = unitialized, .rodata = constants
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** `int data = 5;``
  - 		`int bss;`
  - 		`const int rodata = 1;`
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** pushq, movq, movss and muvss, float is 32-bit whereas double is 64-bit
1. How does `make` know if a file must be recompiled?
  - **Answer:** It uses the makefile data base and the last-modification times of the files to determine if it needs to be recompiled
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** `make -f mymakefile`
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** `#ifndef`, used to avoid double inclusions

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
	}



##Impo://help.github.com/articles/markdown-basics)tant Instructions

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

**Answer:** *`mkdir unixstuff/backups`*

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** *I have explored my file system, I used `cd` for moving to another directory, `ls` for listing the current directory and `pwd` to printing the name of current directory*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** *`cp science.txt science.bak`*

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** *`mkdir tempstuff` `rmdir tempstuff`*

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** 

    cat > list2
    orange
    plum
    mango
    grapefruit
    ^D
    less list2

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** *`cat list1 list2 | grep 'p' | sort`*

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** *`chmod 644 science.txt` `chmod 711 backups`*

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** *`rmdir`*
1. What is the command used to display the manual pages for any command?
  - **Answer:** *`man command`*
1. What command will show the first 5 lines of an input file?
  - **Answer:** *`head -5 file`*
1. What command can be used to rename a file?
  - **Answer:** *`mv oldname newname`*
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** *`ls -a`*
1. What will the command `cat -n file` do?
  - **Answer:** *Print the content of file into the terminal, every line will be enumered.*
1. What will the command `echo -n hello` do?
  - **Answer:** *Print "hello" into terminal without new line.*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** *`who`*
1. How do you change password on your account?
  - **Answer:** *`passwd`*
1. How can you list a file in reverse order?
  - **Answer:** *`ls -r`*
1. What does the `less` command do?
  - **Answer:** *Serve to read file in terminal.*
1. With `less` how do you navigate?
  - **Answer:** *Space-bar, arrows.*
1. What command will display the running processes of the current user?
  - **Answer:** *`ps`*
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** *`top`*

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** *`:w`*
1. What command/key is used to start entering text?
  - **Answer:** *`i`*
1. What are the different modes the editor can be in?
  - **Answer:** *Insert mode, command mode, visual mode.*
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *`:4` or `4G`*
1. What will `dd` command do (in command-mode)?
  - **Answer:** *Delete a line.*
1. How do you undo the most recent changes?
  - **Answer:** *`u`*
1. How do you move back one word?
  - **Answer:** *`b`*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** *`gcc -c file.c -o file.o` The .o file is not an executable file, it is just an objective file. There can be more objective files, which built then the final executable file (they are linked together). Executable file is ready to execute. :)*
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** *For Listing2: `gcc file.c -DDEBUG -o outputfile`. Turn on/off: just with this parameter (-DDEBUG).  For Listing3 there is the common command: `gcc file.c -o outputfile`. Turn on/off: Set the variable debug to 1/0.*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *Listing 2: Pros: If the debug is off, during the preprocessing will be the code whit debugging "remove" (part #ifdef DEBUG #endif will apear in the code only if the debug is on), so it will be faster (no conditions during executing the program); to turn /off/on debugging we do not change the code, just add an parameter to command. Cons: We cannot turn on debugging only for a part of code.

  Listing 3: Pros: We can set parts of code which we can debug (e.x.: only tle last function...). Cons: To turn on/off we need to change the code. If debugging is off, there will still be the conditions in the code --> slower.*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *`gcc file.c -Wl, -Map file.map -o outputfile` Linker (ld).*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *Informations about memory --> content (e.x strings) will be written in the section .data, constants will be in the .rodata (read only) or the uninitialized data will be in the .bss section and in the map file is the info about where in memory it is.*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *I have added:
    
    ...
    #define CONSTANT 42 //.rodata
    ...
    int i; //.bss
    char string[] = "Hello!"; //.data

1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *Assembly instructions (for double): `mov`, `push`, `movsd`, `mulsd`. Assemly instruction (for float): `mov`, `push`, `movss`, `mulss`. Double is twice larger then float (32 bit vs. 64 bit), the instruction `movss` moves 32 bit, `movsd` moves 64 bit.*
1. How does `make` know if a file must be recompiled?
  - **Answer:** *According to date - if the .c file is newer ther the .o file, then it must be recompiled.*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *`make -f mymakefile`*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** 
  
    #ifndef FILE.H
    #define FILE.H
    	/*some body*/
    #endif	 

It protects to include the files in a circle (first need to include the second, the second need to include the first...) --> error while compiling.*

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
	}



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

**Answer:** *mkdir unixstuff\backups*

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** *cd unixstuff*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** *cat science.txt>science.bak*

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** *mkdir tempstuff
rmdir -r tempstuff*

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** *"orange">list2
"plum">>list2
"mango">>list2
"grapefruit">>list2
cat list2*

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** *YOUR ANSWER HERE*

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** *YOUR ANSWER HERE*

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** *rm -r dirname removes directories.*
1. What is the command used to display the manual pages for any command?
  - **Answer:** *man commandname brings up the manual for a command.*
1. What command will show the first 5 lines of an input file?
  - **Answer:** *head -5 filename displays the first 5 lines of a file.*
1. What command can be used to rename a file?
  - **Answer:** *mv filename newfname renames a file.*
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** *ls -a shows the hidden files together with everything else.*
1. What will the command `cat -n file` do?
  - **Answer:** *cat -n filename prints the file, with linenumbers.*
1. What will the command `echo -n hello` do?
  - **Answer:** *echo -n "hello" will print "hello" to standard output, with no new line.*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** *who displays all online users.*
1. How do you change password on your account?
  - **Answer:** *passwd is used to change the password.*
1. How can you list a file in reverse order?
  - **Answer:** *cat -n filename>tmp.txt
sort -rn tmp.txt
rm tmp.txt*
1. What does the `less` command do?
  - **Answer:** *less searches for a pattern in a file.*
1. With `less` how do you navigate?
  - **Answer:** *you use /searchword to search and n to go to the next hit.*
1. What command will display the running processes of the current user?
  - **Answer:** *ps displays your processes.*
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** *top displays the processes using most CPU.*

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** *esc:w [filename] saves the file without quitting.*
1. What command/key is used to start entering text?
  - **Answer:** *the i key can be used to enter text.*
1. What are the different modes the editor can be in?
  - **Answer:** *command mode and insert mode.*
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *:4 will take the cursor to line 4*
1. What will `dd` command do (in command-mode)?
  - **Answer:** *dd will erease the curent line.*
1. How do you undo the most recent changes?
  - **Answer:** *u or :u undo the most recent changes*
1. How do you move back one word?
  - **Answer:** *b moves back one word.*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** *gcc -c hello.c will generate compiled but unlinked object files from the sources, whereas a full compile will link everything together in an excecutable file.*
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** *gcc -g hello.c compiles with debug mode enabled in the compiler. For the two programs, however, Listing 2 needs to have the DEBUG tag defined, while Listing 3 needs to have the debug variable set to something else than zero.*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *For Listing 2, debug code is left out already during compilation and will not be present unless compiled with debug enabled. For Listing 3, debug code will be included in the program code after compilation, but it will not be excecuted unless the flag is specified. The method of Listing 2 is great for saving space, but the method of Listing 3 allows for code that's easier to read along with more flexible debug intergration.*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *gcc -o hello -Wl,-Map=hello.map hello.c, the linker makes this file.*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *The map file defines where libraries, variables and code will be allocated in memory. You have the stack for stack based functions, dataareas for constants and variables, and code area for code.*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *tried adding variables, but program wouldn't recognize the globally defined string*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *The x86 instruction set has instructions for integer multiplication, but not for floating point multiplication (unless a numeric x87 coproccessor is used. Since the 486DX these coprocessors have been intergrated in the main CPU)*
1. How does `make` know if a file must be recompiled?
  - **Answer:** *it's predefined. Libraries does not need to be recompiled.*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *make -f mymakefile*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** *To prevent several inclusions of a library. This saves space and prevents linking conflicts.*

##Library Task

Insert your code between the brackets `{}`:

	void main( int argc, char *argv[] )
	{
		argv = char[argc];
		for(int i=0; i<argc; i++)
        	{
			argv[i] = rand(MIN, MAX);
        	}
		double sum = tab_sort_sum(argv, argc);
		for(int i=0; i<argc; i++)
        	{
			printf(argv[i],"\n");
		}
		printf(sum,"\n");
	}
    
	double tab_sort_sum( double *tab, int tab_size )
	{
		tab = qsort(tab);
		double sum = 0;
		for(int i=0; i<tab_size; i++)
		{
			sum = sum + tab[i];
		}
		return sum;
	}



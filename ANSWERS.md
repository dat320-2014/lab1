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

**Answer:** *mkdir unixstuff/backup*

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** *pwd  cd.. , ls , cd.. , ls , cd ~*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** *cp science.txt science.bak*

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** *mkdir tempstuff , rmdir tempstuff*

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** *cat > list2 , orange, plum, mango, grapefruit , ctrl + d , cat list2*
*

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** *cat list1 list2 | grep p | sort*

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** *chmod a+rw backup , chmod go-rwx science.txt , ls -l*

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** *rmdir "directory"*
1. What is the command used to display the manual pages for any command?
  - **Answer:** *man command*
1. What command will show the first 5 lines of an input file?
  - **Answer:** *head -5 "filename"*
1. What command can be used to rename a file?
  - **Answer:** *mv (old file) (new file)*
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** *ls -a*
1. What will the command `cat -n file` do?
  - **Answer:** *output file content on screen and number every line*
1. What will the command `echo -n hello` do?
  - **Answer:** *not show the result of typing "hello" in the prompt (not show the command not found reply)*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** *who*
1. How do you change password on your account?
  - **Answer:** *passwd*
1. How can you list a file in reverse order?
  - **Answer:** *tac "file"*
1. What does the `less` command do?
  - **Answer:** *output content of file on screen one screen at a time*
1. With `less` how do you navigate?
  - **Answer:** *space bar to turn page and q to quit*
1. What command will display the running processes of the current user?
  - **Answer:** *ps*
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** *ps -eo pcpu,pid,user,args | sort -k 1 -r | head -6*

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** *:w*
1. What command/key is used to start entering text?
  - **Answer:** *i*
1. What are the different modes the editor can be in?
  - **Answer:** *insert and command*
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *$ 4*
1. What will `dd` command do (in command-mode)?
  - **Answer:** *delete the line where the cursor is*
1. How do you undo the most recent changes?
  - **Answer:** *u*
1. How do you move back one word?
  - **Answer:** *b*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** *gcc -O -c hello.c , the hello.o file contains the objects generated from the hello.c file, hello.o cannot be run.*
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** *gcc -g hello.c*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *In listing 2 the debug option is decided by the compiler, in listing 3 whether to debug is decided in the program*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *gcc hello.c -Wl,map=hello.map , -Wl is responsible*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *Its a list of all the differen resources a program uses in order to run*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *#define int=1 , #define string=string*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *double movsd Moves a scalar double-precision floating-point value , float movss  Moves a scalar single-precision floating-point value*
1. How does `make` know if a file must be recompiled?
  - **Answer:** *it checks the timestamps of the source and object files*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *make -f MyMakefile*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** *#ifndef #define in the file with the guarded definition,  It is needed in order to prevent definition of the same element two times and causing copilation errors*

##Library Task

Insert your code between the brackets `{}`:

-------------------------------------------------
main.c
    #include <stdlib.h>
    #include <l1.h>


     void main( int argc, char *argv[] )
	{

	double table [ argv[0] ];

	double min;
	double max;
	double result=0,low_num=0,hi_num=0;

	if (min==null){min = 0.0} 
	if (max==null){max = 100.0}
	
	if(min<max)
	{
                low_num=min;
                hi_num=max+1; 
            }else{
                low_num=max+1;
                hi_num=min;
            }

	for ( i = 0; i < argv[0]; i++ )
   		{
            
            srand(time(NULL));
            result = (rand()%(hi_num-low_num))+low_num;
            
     		 table[ i ] = result;
  	 	}


	tab_sort_sum(table,argv[0]);

	printf(table); 

	}
    	
----------------------------------------
l1.c

	#include <stdlib.h>

	double tab_sort_sum( double *table, int tab_size )

	int compare (const void * a, const void * b)
	{
 	 return ( *(int*)a - *(int*)b );
	}

	{
	doubble sum =table[0];
		for ( i = 1; i < tab_size; i++ ){
			sum+=table[i];
		}
	
	qsort (table, tab_size, sizeof(int), compare);

	return sum;
	
	return table
	
	}

--------------------------------
L1.h
	#ifndef L1.h
	#define L1.h

	double tab_sort_sum( double *tab, int tab_size )

	#endif
-----------------------
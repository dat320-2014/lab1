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

**Answer:** 
*sven@sven-VirtualBox:~$ mkdir unixstuff
sven@sven-VirtualBox:~$ cd unixstuff
sven@sven-VirtualBox:~/unixstuff$ mkdir backup
sven@sven-VirtualBox:~/unixstuff$ cd backups
sven@sven-VirtualBox:~/unixstuff/backups$ 
 *

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** 
*
sven@sven-VirtualBox:~$ pwd
/home/sven
sven@sven-VirtualBox:~$ cd unixstuff
sven@sven-VirtualBox:~/unixstuff$ pwd
/home/sven/unixstuff
sven@sven-VirtualBox:~/unixstuff$ ls
backup
*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** 
*sven@sven-VirtualBox:~/unixstuff$ cd backup
sven@sven-VirtualBox:~/unixstuff/backup$ ls
science.txt  science.txt~
sven@sven-VirtualBox:~/unixstuff/backup$ cp science.txt science.bak
sven@sven-VirtualBox:~/unixstuff/backup$ ls
science.bak  science.txt  science.txt~
sven@sven-VirtualBox:~/unixstuff/backup$ 
*

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** 
*sven@sven-VirtualBox:~/unixstuff/backup$ mkdir tempstuff
sven@sven-VirtualBox:~/unixstuff/backup$ ls
science.bak  science.txt  science.txt~  tempstuff
sven@sven-VirtualBox:~/unixstuff/backup$ rmdir tempstuff
sven@sven-VirtualBox:~/unixstuff/backup$ ls
science.bak  science.txt  science.txt~
*

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** 
*
@sven-VirtualBox:~/unixstuff/backup$ rm list2.txt
sven@sven-VirtualBox:~/unixstuff/backup$ printf 'orange, plum, mango, grapefruit\n' > list2.txt
@sven-VirtualBox:~/unixstuff/backup$ rm list2.txt
sven@sven-VirtualBox:~/unixstuff/backup$ printf 'orange, plum, mango, grapefruit\n' > list2.txt
sven@sven-VirtualBox:~/unixstuff/backup$ cat list2.txt
orange, plum, mango, grapefruit
sven@sven-VirtualBox:~/unixstuff/backup$
*

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** *sven@sven-VirtualBox:~/unixstuff/backup$ printf 'grape \n pineapple \n banana \n coconut' > list1.txt
sven@sven-VirtualBox:~/unixstuff/backup$ cat * | grep -n "p" | sort
1:grape 
2: pineapple 
4: coconutorange, plum, mango, grapefruit
sven@sven-VirtualBox:~/unixstuff/backup$ ls
list1.txt  list2.txt 
*

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** *sven@sven-VirtualBox:~/unixstuff/backup$ ls -l
total 12
-rw-rw-r-- 1 sven sven   36 Sep  2 20:08 list1.txt
-rw-rw-r-- 1 sven sven   32 Sep  2 20:07 list2.txt
-rw-rw-r-- 1 sven sven 1053 Sep  2 20:13 science.txt
-rw-rw-r-- 1 sven sven    0 Sep  2 19:39 science.txt~
sven@sven-VirtualBox:~/unixstuff/backup$ chmod 755 science.txt
sven@sven-VirtualBox:~/unixstuff/backup$ ls -l
total 12
-rw-rw-r-- 1 sven sven   36 Sep  2 20:08 list1.txt
-rw-rw-r-- 1 sven sven   32 Sep  2 20:07 list2.txt
-rwxr-xr-x 1 sven sven 1053 Sep  2 20:13 science.txt
-rw-rw-r-- 1 sven sven    0 Sep  2 19:39 science.txt~
sven@sven-VirtualBox:~/unixstuff/backup$ 
*

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** *rm -r*
1. What is the command used to display the manual pages for any command?
  - **Answer:** *man* 
1. What command will show the first 5 lines of an input file?
  - **Answer:** *head -5 file*
1. What command can be used to rename a file?
  - **Answer:** *mv*
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** *-a*
1. What will the command `cat -n file` do?
  - **Answer:** *Number all output lines (man cat)*
1. What will the command `echo -n hello` do?
  - **Answer:** *do not output the trailing newline*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** *w*
1. How do you change password on your account?
  - **Answer:** *passwd*
1. How can you list a file in reverse order?
  - **Answer:** *s
ven@sven-VirtualBox:~/unixstuff/backup$ ls -ltr
total 12
-rw-rw-r-- 1 sven sven    0 Sep  2 19:39 science.txt~
-rw-rw-r-- 1 sven sven   32 Sep  2 20:07 list2.txt
-rw-rw-r-- 1 sven sven   36 Sep  2 20:08 list1.txt
-rwxr-xr-x 1 sven sven 1053 Sep  2 20:13 science.txt
sven@sven-VirtualBox:~/unixstuff/backup$ ls -l
total 12
-rw-rw-r-- 1 sven sven   36 Sep  2 20:08 list1.txt
-rw-rw-r-- 1 sven sven   32 Sep  2 20:07 list2.txt
-rwxr-xr-x 1 sven sven 1053 Sep  2 20:13 science.txt
-rw-rw-r-- 1 sven sven    0 Sep  2 19:39 science.txt~
sven@sven-VirtualBox:~/unixstuff/backup$ 
*
1. What does the `less` command do?
  - **Answer:** *less filename     Like more, but you can use Page-Up too. Not on all systems. - SOURCE (http://freeengineer.org/learnUNIXin10minutes.html#Directories)*
1. With `less` how do you navigate?
  - **Answer:** 
		*PAGE-UP = page up
		ENTER = one line down 
                SPACEBAR = page down  q=quit*
1. What command will display the running processes of the current user?
  - **Answer:** *ps -u user*
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** *top*

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** *:w*
1. What command/key is used to start entering text?
  - **Answer:** *I*
1. What are the different modes the editor can be in?
  - **Answer:** *Command Mode and Text Editor mode*
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *:4*
1. What will `dd` command do (in command-mode)?
  - **Answer:** *Delete current line and put in buffer*
1. How do you undo the most recent changes?
  - **Answer:** *u*
1. How do you move back one word?
  - **Answer:** *b*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** *
		Build the object file: gcc -c hello.c - 
		Both are in a sense binary files, but the object file will not   execute as the library files are not linked. Thus, the function definitions are not resolved.
*
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** *
		Add the DEBUG macro by utilizing the following command:
		gcc -D DEBUG hello.c -o hello

		For the first example, turn debugging off by compiling 			without the macro flag. 

		For the second example, integrate 			a public function that sets/resets the debug boolean 			variable. 
*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *
		The first one is conditional, namely hardcoding entire codeblocks to be executed when compiled in debug mode. The positive aspects of doing it this way, is that it allows a whole module to run in debug mode, with added visualization of data. The down side is that it has to be recompiled to turn off. 
	
		The second one is selective, which allows users to manually set the debug option whenever he/she is so inclined. This option does not require a recompilation, and is thus less time consuming than the above. 
*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *gcc hello.c -Wl,-Map,prog.map*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *
		In general, a given object file contains three 			sections:
		- .bss, which holds uninitialized data.
 		- .data, which holds initialized writeable data.
		- .text (rodata), which holds instructions and read-only data.
*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *
	int count = 0; // Initialized writeable data (.data) 
        char* uninitialized_string; //Uninitialized, writeable data (.bss)	
	printf("Hello, world!\n");
	printf("No debugging flag this time...\n");
	return 0;
*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *
		Create an assembly file by:
		gcc hello.c -S -o hello.S
	
		Assembly for multiply(double t, double z):
		multiply:
		.LFB1:
			.cfi_startproc
			pushq	%rbp
			.cfi_def_cfa_offset 16
			.cfi_offset 6, -16
			movq	%rsp, %rbp
			.cfi_def_cfa_register 6
			movsd	%xmm0, -8(%rbp)
			movsd	%xmm1, -16(%rbp)
			movsd	-8(%rbp), %xmm0
			mulsd	-16(%rbp), %xmm0
			popq	%rbp
			.cfi_def_cfa 7, 8
			ret
			.cfi_endproc
		*Other than moving the variables into registers, the
		key assembly instruction that performs the 			multiplication is: 

		MULSD--Scalar Double-Precision Floating-Point Multiply

		Assembly for float multiply(float t, float z):
		multiply:
		.LFB1:
			.cfi_startproc
			pushq	%rbp
			.cfi_def_cfa_offset 16
			.cfi_offset 6, -16
			movq	%rsp, %rbp
			.cfi_def_cfa_register 6
			movss	%xmm0, -4(%rbp)
			movss	%xmm1, -8(%rbp)
			movss	-4(%rbp), %xmm0
			mulss	-8(%rbp), %xmm0
			popq	%rbp
			.cfi_def_cfa 7, 8
			ret
			.cfi_endproc
			
			Again, the key assembly instruction that 				performs the multiplication for floats is:
			*MULSS - Multiply Scalar Single-Precision Floating-Point Values



*
1. How does `make` know if a file must be recompiled?
  - **Answer:** *
		A file needs to be recompiled or relinked if any of its prerequisites change. A prerequisite is a file that is used as 
		input to create a target.
*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *make -f mymakefile*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** *
		An include guard is a construct used to avoid the problem of double (or multiple) inclusion when dealing with the include directive. If a certain struct is included more than once, it will cause a compiler error. 

An include guard is implemented in the following manner:
#ifndef XXXX_H
#define XXXX_H

Which means "if XXXX_H is not define, define XXXX_H"	
*

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
			int i;
			    if ( argc < 2 ) /* Must have at least two input arguments */
			    {
				printf("***********************************\n"); 
				printf( "usage: %s filename (int)table_size \n", argv[0] );
				printf( "optional arguments: (int)min (int)max \n");
				printf("\n");
				printf("Example: main.c 10 0 60 \n"); 
				printf("***********************************\n"); 
				return 0;
			    }
			    int table_size = atoi(argv[1]);
			    double table[table_size];
			    double rand_max = 100.0;
			    double rand_min = 0.0; 
			    if(argc == 3)
			    {  
				    if(atof(argv[3]) != 0.00)
				    {
					 rand_max = atof(argv[3]);
				    }
			    }
			   if(argc == 4)
			   {
				    if(atof(argv[2]) != 0.00)
				    {
				    	
					rand_min = atof(argv[2]);
				    }	   
			   }
			    for(i=0;i<table_size+1;i++)
			    {
			 	double rand = generate_random(rand_min,rand_max);	
				table[i] = rand;
			    }	
			    printf("\n");
			    printf("Unsorted table: \n");
			    print_table_contents(&table, table_size);
			    printf("The sum of the sorted table is %e \n",(double)tab_sort_sum(&table,table_size));
			    printf("(Obviously some kind of overflow happened here, since the two sums differ...\n");
			    printf("\n");
			    printf("Sorted table: \n");
			    print_table_contents(&table, table_size);
        }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
		double sum = 0.0;
   		int i;
   		qsort(tab, tab_size, sizeof (double), compare_doubles);
   		for (i = 0; i <= tab_size+1; ++i)
   		{ 
      			sum += tab[i];
   		}
   		printf("Sum before return of tab_sort_sum(***): %e (Correct sum!)\n", sum);
   		return sum;
	}



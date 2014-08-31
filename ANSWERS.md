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

**Answer:** *mkdir unixstuff/backups*

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** *cd ..; cd pedersen; ls -al; pwd*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** *cp science.txt science.bak*

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** *mkdir tempstuff; rmdir tempstuff*

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:**  
cat > list2  
orange  
plum  
mango  
grapefruit  
^D  
cat list2

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** *cat list1 list2 | grep p | sort*

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:**  
chmod 777 science.txt  
chmod 644 backups  
ls -l  

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** *rm -d*
1. What is the command used to display the manual pages for any command?
  - **Answer:** *man*
1. What command will show the first 5 lines of an input file?
  - **Answer:** *head -5*
1. What command can be used to rename a file?
  - **Answer:** *mv*
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** *ls -a*
1. What will the command `cat -n file` do?
  - **Answer:** *number the output lines*
1. What will the command `echo -n hello` do?
  - **Answer:** *display hello without the trailing newline*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** *who*
1. How do you change password on your account?
  - **Answer:** *passwd*
1. How can you list a file in reverse order?
  - **Answer:** *tac*
1. What does the `less` command do?
  - **Answer:** *View the contents of a file*
1. With `less` how do you navigate?
  - **Answer:** *You can use up and down, j,k, pgup, pgdown, enter etc.*
1. What command will display the running processes of the current user?
  - **Answer:** *jobs*
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** *top*

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** *:w*
1. What command/key is used to start entering text?
  - **Answer:** *i*
1. What are the different modes the editor can be in?
  - **Answer:** *command, insert and visual*
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *4G or :4*
1. What will `dd` command do (in command-mode)?
  - **Answer:** *Delete current line*
1. How do you undo the most recent changes?
  - **Answer:** *u*
1. How do you move back one word?
  - **Answer:** *b*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** *gcc -c  	
You don't do the linking step*
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** *In listing 2 you turn on debug by passing -D DEBUG to gcc.
In listing 3 you turn on debug by modifying the debug variable*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *In listing 2 you don't need to change the source of you program to debug, you can just compile with the DEBUG flag set.
In listing 3 you need to change the debug variable and recompile your program.
In listing 2 the debug code will not be compile as it is removed during the preprocessing, so the program will be smaller and the compiling faster.*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *gcc -o main -Wl,-Map,main.map main.c*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *.data is content like strings, .rodata is constants and .bss is uninitialized variables*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *int a; int b = 2; static const int c = 3;*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *movsd and mulsd with double and movss and mulss with float. Double is 64bit while float is 32bit*
1. How does `make` know if a file must be recompiled?
  - **Answer:** *last modified date*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *make -f mymakefile*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:**  
#ifndef FILE_H  
#define FILE_H  
%* code *%  
#endif  
  
To prevent code from being included more than once

##Library Task

Insert your code between the brackets `{}`:
```c
    void main( int argc, char *argv[] )
	{
		int min = 0;
		int max = 100;
		int n;

		if (argc < 2) {
			return 0;
		}

		sscanf(argv[1], "%d", &n);

		if (argc > 2) {
			scanf(argv[2], "%d", &min);
		}

		if (argc > 3) {
			scanf(argv[3], "%d", &max);

		int i;
		double tab[n];

		for (i = 0; i < n; i++) {
			tab[i] = min + (rand() % (int)(max - min + 1));
		}

		double sum = tab_sort_sum(tab, n);

		printf("Sum: %.4f\n", sum);	

		for (i = 0; i < n; i++) {
			printf("%f\n", tab[i]);
		}
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
		int i;
		double sum = 0;

		for (i = 0; i < tab_size; i++) {
			sum += tab[i];
		}

		qsort(tab, tab_size, sizeof(double), compare);

		return sum;
	}

	int compare(const void* a, const void* b)
	{
		return (*(double*) a - *(double*) b);
	}
```

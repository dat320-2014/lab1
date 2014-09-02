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

% cd unixstuff
% mkdir backups

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

% cd unixstuff
% ls -l
% ls
% pwd
% cd opsys/labs/
% pwd
% cd

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

% cp science.txt science.bak

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

% mkdir tempstuff
% rmdir tempstuff

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

% cat > list2
orange
plum
mango
grapefruit
^D
% cat list2

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

% cat list1 list2 | grep p | sort

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

% chmod a+rwx science.txt
% ls -l
% chmod go+rw backups/
% ls -l

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - dir dirname
1. What is the command used to display the manual pages for any command?
  - man command
1. What command will show the first 5 lines of an input file?
  - head -5 filename
1. What command can be used to rename a file?
  - mv filename newfilename
1. What option can we given to `ls` to show the hidden files?
  - ls -a
1. What will the command `cat -n file` do?
  - It will display linenumber preceding the accual line.
1. What will the command `echo -n hello` do?
  - It will return hello without new line after.
1. What command will display s list of the users who currently logged in in the system?
  - who
1. How do you change password on your account?
  - ssh jo2
    passwd
    *currentpass*
    *newpass*
    *confirmnewpass*
    exit
1. How can you list a file in reverse order?
  - ls -r
1. What does the `less` command do?
  - Returns the content of a file one page at a time.
1. With `less` how do you navigate?
  - Pressing spacebar will give you a new page, pressing return will give you
  one line at a time.
1. What command will display the running processes of the current user?
  - ps
1. What command can be used to find the process(es) consuming the most CPU?
  - top

##vi questions
1. How do we save a file in `vi` and continue working?
  - :w
1. What command/key is used to start entering text?
  - i or a
1. What are the different modes the editor can be in?
  - INSERT and COMMAND
1. What command can be used to place the cursor at the beginning of line 4?
  - :4
1. What will `dd` command do (in command-mode)?
  - delete current line
1. How do you undo the most recent changes?
  - u
1. How do you move back one word?
  - e

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - gcc -c hello.c -o hello.o The difference between generating only the .o file and building the executable is that when making
  the .o file you stop after the assembly-code have been generated, while to make the executable you also have to compile the
  linkfile. 
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - gcc -DDEBUG hello.c -o hello. For listing 2, you can turn on and off debugging by defining DEBUG in compliling. gcc -g hello.c -o hello. for
  listing 3 you have to change the debug variable in the file before degugging starts. 
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - Listing 2 has the advantage if you are debugging several files, because of the environment variable DEBUG, but you can't
  debug one file at the time. Listing 3 is opposite in that you have to set debug to 1 on each of the files you want to debug. Also, with Listing 2
  you can strip the debug code when compiling to save space. THough it might make problems to not have access to debugging code if something is
  bugging and you want to know why, in an external network where you dont have access to it. 
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - gcc hello.c -o hello -wl,-map=mymap.map
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - there is 4 sections in a map file. .data, .bss, .rodata and .text. The data area contains global and static variables, that are not null or zero. the bss
  .bss section contains variables uninitialized variables and variables equals zero or null. the rodata section contains only readable variables. the text
  section contains executable instructions, most often read-only. 
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - int a=0;int b=2;const int=5;
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - gcc -c hello.c -S can be used for only assembly, use gcc -c -g- Wa,-a,-ad hello.c > hello.lst for assembly and code. Difference in assembly when
  changing between float and double is mainly the assemblycode for moving and multiplying has different endings. eG: float generates endings for
  signed and long numbers, while double had ending of d for double. 
1. How does `make` know if a file must be recompiled?
  - make checks the timestamps of the files and if they have changed it recompiles, if not it doesnt. 
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - make -f mymakefile
1. How do you implement an *include guard*, and why is it needed?
  - #include file.h It is needed so that you dont include the same things more than one time. 

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
	int i;
	double tab[5]={4.3, 2.3, 5.4, 1.2, 1.3};
	double sum;
	sum=tab_sort_sum(tab, 5);
	for(i=0;i<5;i++)
	{
		printf("sum%f\n", i, tab[i]);
	}
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
		int i;
		double sum = 0;
		qsort(tab,tab_size, sizeof(double), dblCmp);
		for( i=0; i<tab_size; i++)
		{
			sum = sum + tab[i];
		}
	
		return sum;
	}



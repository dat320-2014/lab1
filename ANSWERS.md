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

~/unixstuff$ mkdir backups

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

cd backups pwd cd ls

###Exerci 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

mv science.bak backups/

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

mkdir tempstuff rmdir tem[tab]


###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

cat>list2 orange plum mango grapefruit cat list2 dsuppiah@badne7:~$ cat list2 orange plum mango grapefruit

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

grep p list1 list2 | sort

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

chmod a+rw science.txt chmod go-rwx backups ls -1

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - rmdir directory
1. What is the command used to display the manual pages for any command?
  - help/man/info
1. What command will show the first 5 lines of an input file?
  - head -5
1. What command can be used to rename a file?
  - mv [file1][file2]
1. What option can we given to `ls` to show the hidden files?
  - ls -a
1. What will the command `cat -n file` do?
  - Every line in the file would get a number
1. What will the command `echo -n hello` do?
  - It would print hello
1. What command will display s list of the users who currently logged in in the system?
  - who
1. How do you change password on your account?
  - passwd
1. How can you list a file in reverse order?
  - tail -r quotes.txt
1. What does the `less` command do?
  - The command less writes the contents of a file onto the screen a page at a time
1. With `less` how do you navigate?
  - Press the [space-bar] if you want to see another page, and type [q] if you want to quit reading. As you can see, less is used in preference to cat for long files.
1. What command will display the running processes of the current user?
  - ps
1. What command can be used to find the process(es) consuming the most CPU?
  - top

##vi questions
1. How do we save a file in `vi` and continue working?
  - :w
1. What command/key is used to start entering text?
  - while in COMMANDO mode press the "i" key, then you can start type text.
1. What are the different modes the editor can be in?
  - COMMANDO/INSERT mode
1. What command can be used to place the cursor at the beginning of line 4?
  - ^ Commando, would end up in the beginning of the current line
1. What will `dd` command do (in command-mode)?
  - It deletes the whole line that the cursor is at
1. How do you undo the most recent changes?
  - u COMMANDO
1. How do you move back one word?
  - b

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - gcc[sourcefile] -c, an example is to make a library, the object file is not linked.
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - Listing 2: gcc -DDEBUG. Listing 3: Global var debug must be changed in source in order to toggle.
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - Listing 2: There you have to change it before is starts to compile, Listing 3: Here you can change it while debugging.
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - gcc helloworld.c -WI,-Map=mappy.map, linkeren
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - The map shows address resolutions, .data, .code, etc sections size and position, archive members included and allocated symbols and their assigned value.
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - 
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - gcc -o -s dmult.c (took the liberty of optimizing) Examining dmult.s & fmult.s: mulsd %xmm1, %xmm0 scalar double as opposed to mulss %xmm1, %xmm0 scalar single mult. instruction. Single (float) operates on half the bit-size of double. It is thus curious how gcc chooses to use the 128bit XMM registers on both accounts.
1. How does `make` know if a file must be recompiled?
  - The source file is "newer" than the currently compiled file, or the file does not exist.
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - make -f mymakefile
1. How do you implement an *include guard*, and why is it needed?
  - include guards prevent common libraries and headers being imported several times. It looks like this:
#ifndef IHAVEBEENHERE
#DEFINE IHAVEBEENHERE
 //do the header
#endif


##Library Task

Insert your code between the brackets `{}`:




//This task is unfinished
##include <stdlib.h>

    void main( int argc, char *argv[] )
	{
		
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
		qsort(tab, tab_size, sizeof(*tab), cmp );
		double sum = 0;
		int i;
		for (i = 0; i >= 0; i--)
		{
			sum += tab[i]
		}
		return sum;
	}



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

mkdir backups

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

cd 
pwd
ls

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

cp science.txt science.bak

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

mkdir tempstuff
rmdir tempstuff

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

cat > list2
orange
plum
mango
grapefruit

cat list2

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

cat list1 list2 | grep p | sort

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

chmod a+rwx science.txt
chmod a+rwx science.bak

ls -l

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - rmdir
1. What is the command used to display the manual pages for any command?
  - man “command”
1. What command will show the first 5 lines of an input file?
  -Head -5 filename
1. What command can be used to rename a file?
  -mv oldfilename newfilename
1. What option can we given to `ls` to show the hidden files?
  -If you type ls –a all files will be shown.
1. What will the command `cat -n file` do?
  -Adds numbers to the lines.
1. What will the command `echo -n hello` do?
  -Adds the text in front of your username in the command line prompt.
1. What command will display s list of the users who currently logged in in the system?
  -who
1. How do you change password on your account?
  -passwd
1. How can you list a file in reverse order?
  -tac “filename”
1. What does the `less` command do?
  -The command less writes the contents of a file onto the screen a page at a time
1. With `less` how do you navigate?
  You press the space-bar to navigate between pages.
1. What command will display the running processes of the current user?
  -ps
1. What command can be used to find the process(es) consuming the most CPU?
  -top

##vi questions
1. How do we save a file in `vi` and continue working?
  -:w filename
1. What command/key is used to start entering text?
  -i/insert
1. What are the different modes the editor can be in?
  -Command mode and insert mode
1. What command can be used to place the cursor at the beginning of line 4?
  -:4
1. What will `dd` command do (in command-mode)?
  -dd deletes the whole line that the cursor is at
1. How do you undo the most recent changes?
  -press u
1. How do you move back one word?
  -press b

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  -“gcc –g –O –c Hello.c“. The difference is that the object file is created by stopping at an earlier point in the compilation process than what is required when creating an executable. 

1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  -Listing 2 requires debugging to be set in compilation mode, while listing 3 debugging has to be set during run-time.  Listing 2 Debug on command: “gcc HelloWorld.c –DDEBUG –o HelloWorld”. Listing 2 debugging off command: “gcc HelloWorld.c  –o HelloWorld”. 

1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - Listing 2 pros: You only have to declare the debugging symbol in compile mode once for it to work. Quick and easy. Listing 2 cons: not as flexible as debugging in runtime-mode, need to re-compile to remove debugging. Listing 3 pros: Very flexible since all the changes can be done during run-time without the need to re-compile. Listing 3 cons: A little bit more work to code it.

1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  -“gcc -o HelloWorld -Wl,-Map,HelloWorld.map HelloWorld.c”  The –Wl and –Map tools create the file.

1. What is the content of each of the sections in a *map* file. Explain briefly.
  Where objects are mapped into memory. How common symbols are allocated, all archive members included in the link , with a mention of the symbol, the values assigned to symbols.

1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - File

1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - The command used to print the assembly code was: “gcc -O2 -S -c HelloWorld.c”. LFB12 - > .cfi_startproc -> mulss changes to mulsd when we changed the double to float.

1. How does `make` know if a file must be recompiled?
  - If the creation date of the executable is older than the creation date of the .c file, it knows it needs to re-compile.

1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  -make -f mymakefile
1. How do you implement an *include guard*, and why is it needed?
  -The include guard is used to avoid the problem of double inclusion.

##Library Task

Insert your code between the brackets `{}`:

    	void main( int argc, char *argv[] )
	{
	        int tab_size = 5, min = 0, max = 100, i = 0;
	        double sum;
	        char rangeReply[10];
	
	        printf("Please write your desired table size: ");
	        scanf("%d", &tab_size);
	
	        while(strcmp(rangeReply, "y") != 0 && strcmp(rangeReply, "n") != 0){
	                printf("Would you like to specify min and max value (default: 0-100)? (y/n): ");
	                scanf("%s", &rangeReply);
	        }
	
	        if(strcmp(rangeReply, "y") == 0){
	                printf("Please write desired minimum value: ");
	                scanf("%d", &min);
	
	                printf("Please write desired maximum value: ");
	                scanf("%d", &max);
	        }
	
	        double tab[tab_size];
	
	        srand((unsigned)time(NULL));
	
	        for(i = 0; i < tab_size; i++){
	                tab[i] = (rand() % (max-min)) + min;
	        }
	
	        sum  = tab_sort_sum(tab, tab_size);
	
	        for(i = 0; i < tab_size; i++){
	                printf("%f \n", tab[i]);
	        }
	
	        printf("Sum is: %f \n", sum);
	}    
    
	double tab_sort_sum( double *tab, int tab_size )
	{
		int i = 0, c, d, n, swap;
	        double sum;
	
	        n = tab_size;
	
	        /* Bubble sort algorithm */
	        for (c = 0 ; c < ( n - 1 ); c++)
	        {
	          for (d = 0 ; d < n - c - 1; d++)
	          {
	            if (tab[d] > tab[d+1]) /* For decreasing order use < */
	            {
	              swap      = tab[d];
	              tab[d]   = tab[d+1];
	              tab[d+1] = swap;
	            }
	          }
	        }
	        sum = 0;
	        for(i = 0; i < tab_size; i++){
	                sum += tab[i];
	        }
	        return sum;
	}



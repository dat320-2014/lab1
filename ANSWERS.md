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

**Answer:** *`cd unixstuff` `mkdir backups`*

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** *`cd` changes directory `ls` lists the directory structure `pwd` show you current working directory*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** *`cp science.txt science.bak`*

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** *`mkdir tempstuff. rmdir tempstuff/`*

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** *
        
        `cat > list2
        orange
        plum
        mango
        grapefruit
        ^D

        cat list2`
*
###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** *`cat list1 list2 | grep p | sort`*

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** *`chmod -w science.txt` remove write access.`chmod +w science.txt` enabled write access. `chmod -rw backups/` made the Os print out a warning when deleting the directory.*
	
##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** *`rm -r [directory_name]` will remove a directory*
1. What is the command used to display the manual pages for any command?
  - **Answer:** *the command `man [progam]` will show the manual page for your desired program*
1. What command will show the first 5 lines of an input file?
  - **Answer:** *`head -n 5 [filename]` will show the first 5 lines of a specified file*
1. What command can be used to rename a file?
  - **Answer:** *You may use the command `mv [file] [new_name]` to rename a file*
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** *`ls -a`*
1. What will the command `cat -n file` do?
  - **Answer:** *The command will number the lines that are printed*
1. What will the command `echo -n hello` do?
  - **Answer:** *`echo -n hello` will print hello to the screen but make the cursor stay on the same line.*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** *the command `who` will list all users logged in to the system*
1. How do you change password on your account?
  - **Answer:** *You can change the password using the command `passwd [username]`*
1. How can you list a file in reverse order?
  - **Answer:** *To list a file in reverse order you may use the `tac` command which is also `cat` spelled backwards*
1. What does the `less` command do?
  - **Answer:** *the command `less` prints a file one page at a time*
1. With `less` how do you navigate?
  - **Answer:** *You can navigate `less` using the pageUp and pageDown keys. Also pressing space will take you to the next page.*
1. What command will display the running processes of the current user?
  - **Answer:** *the command `top -u [username]` will display the processes for the user*
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** *Running the program `top` with no parameters will print the running processes with the most intensive on the top of the list*

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** *You can save a file and continue working by entering `:w [filename]` in the command mode*
1. What command/key is used to start entering text?
  - **Answer:** *Pressing the `i` button *
1. What are the different modes the editor can be in?
  - **Answer:** *The editor includes two modes. `Command` and `Input Mode`*
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *Typing `:4` in command mode will take your cursor to line 4*
1. What will `dd` command do (in command-mode)?
  - **Answer:** *Typing `dd` in command mode will delete the line your cursor hovers over*
1. How do you undo the most recent changes?
  - **Answer:** *You can undo your recent by typing `u` in Command Mode*
1. How do you move back one word?
  - **Answer:** *Pressing `b` in Command Mode will take you back one word at a time*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** *By typing `gcc -c [source.c]` you will get only the `.o` file. This way gcc will only compile your source and not link it to create an executable.*
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** *To compile you program with debug enabled in case 1: use gcc with the flag `- DDEBUG`. In case two: *
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:**In Listing 2 debugging is activated by compiling with the macro `DEBUG`. In my opinion it seems like a simple and convenient method to activate debugging, mainly because it does not require you to modify the source code. In Listing 3 debugging is enabled by setting a variable. In this case you will have to modify the c file(s) to enable debugging which may become difficult as you have to trace the appropriate variables. In my opinion it also makes the code harder to read because on first sight it may seem like a "normal" part of the code.**
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *In order to generate a map file use the command `gcc -o [executable] -Wl,-Map,[desired.map] [source.c]` `ld` the linker in gcc is responsible for producing the map file*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *The .map file include a list over program entrypoints and which libraries/object files the linker uses.*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *
    
        float multiply(float x1, float x2){
           
	   return x1*x2;

        }

        int main(void){
           
	   int integer;
           char character;
           short shortvar;
           
           float floating;

           printf("Hello, World!\n");

           printf("%.3f\n", multiply(3.2,4.0));

           return 0;

         }
*
    
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *
	```
        multiply:
        .LFB0:
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
         ```
The `mulsd` Instruction performing the multiplication. When using the float type, it uses the `mulss` insturction.

*

1. How does `make` know if a file must be recompiled?
  - **Answer:** *Make checks the timestamp of the executable. If it is older than the source file required to make it, one can asume it is outdated and needs to be recompiled in order to update the executable.*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *`make -f mymakefile`*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** *And include guard is needed so that headers are not included more than once. If they are you will end up defining functions multiple times and you program may not compile. An include header is added by using the preprocessor:
    ```
    #ifndef header.h
    #define header.h
   
    ..code contents..
   
    #endif
    ```
*

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
    	int tableSize;
	
	double min;
	double max;

	if(argc == 1){
		printf("Error: You need to specify Array Size\n");
		printf("Usage: main [size] [min] [max]\n");
		return -1;
	}else{
		tableSize = atoi(argv[1]);
	}
	
	double table[tableSize];
	
	if(argc >= 3){
		min = atof(argv[2]);
	}else{
		min = 0.0;
	}
	if(argc >= 4){
		max = atof(argv[3]);
	}else{
		max = 100.0;
	}
	
	
	sclk();			// Seeds the timer
	int i;
	for(i = 0; i < tableSize;i++){
		//table[i] = min + rand() % max;
		table[i] = randDouble(min,max);
	}

	printf("\nHere is our table:\n");
	for(i = 0; i < sizeof(table)/sizeof(double);i++){
		printf("%.2f, ",table[i]);
	}

	printf("\n\nSorted table:\n");
   
	double sum = tab_sort_sum(table,tableSize);

	printf("\n\n**Sum of table: %.2f**\n\n", sum);
	
    return 0;
	
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
	    int i, j;
  	    double sum, swap;
  	    double array[tab_size];
  	    
	    for(i = 0; i < tab_size; i++){
  	       array[i] = tab[i];
  	    }

  	    int array_size = tab_size;
     
  	    for (i = 0 ; i < ( (array_size - 1 )); i++)
  	    {
    	        for (j = 0 ; j < array_size - i - 1; j++)
    		{		
      		    if (array[j] > array[j+1]) /* For decreasing order use < */
      	            {
       		        swap       = array[j];
        	        array[j]   = array[j+1];
        	        array[j+1] = swap;
      		    }
    		}
  	    }
 
	    //Create the sum
	    for(i = 0; i < tab_size; i++){
	        sum += array[i];
	    }
	    // Print the Table
	    for(i = 0; i < tab_size;i++){
	        printf("%.2f, ", array[i]);
	    }
            return sum;

    }



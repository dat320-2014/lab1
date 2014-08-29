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

**Answer:** *mkdir backups*

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** *cd = change directorie, ls = lists the content of current directorie, pwd = currentworking directorie.*

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** *cp science.txt science.bak.*

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** *mkdir tempstuff, rmdir tempstuff.*

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** *
    cat > list2
    orange
    plum
    mango
    grapefruit
    ^D

    cat list2*

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** *cat list1 list2 | grep p | sort*

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** *chmod -w sience.txt  remove write access. chmod +w science.txt. chmod -rw backups made OS write out a warning when deleted.*

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** *-r*
1. What is the command used to display the manual pages for any command?
  - **Answer:** *man*
1. What command will show the first 5 lines of an input file?
  - **Answer:** *head -n 5*
1. What command can be used to rename a file?
  - **Answer:** *mv*
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** *-a*
1. What will the command `cat -n file` do?
  - **Answer:** *it numbers each line the file*
1. What will the command `echo -n hello` do?
  - **Answer:** *does not print the newline character.*
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** *who*
1. How do you change password on your account?
  - **Answer:** *passwd*
1. How can you list a file in reverse order?
  - **Answer:** *tail*
1. What does the `less` command do?
  - **Answer:** *dispay one page at a time*
1. With `less` how do you navigate?
  - **Answer:** *spacebar, pageUp, pageDown and q*
1. What command will display the running processes of the current user?
  - **Answer:** *top -u*
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** *top*

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** *:w*
1. What command/key is used to start entering text?
  - **Answer:** *i*
1. What are the different modes the editor can be in?
  - **Answer:** *command mode or insert mode*
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** *:4*
1. What will `dd` command do (in command-mode)?
  - **Answer:** *delete current line*
1. How do you undo the most recent changes?
  - **Answer:** *u*
1. How do you move back one word?
  - **Answer:** *b*

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** *gcc-c hello.c -o hello.o, can be used to share with other, and then linked together to make an executable.*
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** * gcc -DDEBUG hello.c -o hello*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *Listing 2 is clearly better than Listing 3. Listing 2 will have its filesize reduced if not in debugmode. While Listing 3 has the same size no matter what mode it is compiled in.*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *gcc -o hello -Wl,-Map=hello.map hello.c, Linker is responsible for producing the map file.*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *It shows where the different data types are stored in memory.*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *added: int i; int debug = 1; static int a = 1;*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *double -> mulsd, float -> mulss, no idea why, I guess the ALU in the processor has different tools for different datatypes.*
1. How does `make` know if a file must be recompiled?
  - **Answer:** *it checks the datestamp on the files to see if any of the precompiled files have been changed since last compilation.*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *make -f mymakefile*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** *you can do a #ifndef #endif check in the preprocessor area to skip code if there are more than one #include, include guards are needed to not violate 'one definition rule'.*

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
    {
    	int tableSize;
    double min = 0.0;
    double max = 100.0;
	
    if(atoi(argv[1])){
    	tableSize = atoi(argv[1]);
    }else{
    	printf("You need to specify table size!");
    }
	
    double table[tableSize];
    if(argc >= 3 ){
    	min = atof(argv[2]);
    }else {
    	min = 0.0;
    }
    if(argc  >= 4){
    	max = atof(argv[3]);
    }else{
    	max = 100.0;
    }
	
    srand(time(NULL));
    int i;

    for(i = 0; i < tableSize; i++){
    	table[i] = randDouble(min,max);
    }
    printf("Here is our array :\n");
    for(i=0; i < tableSize; i++){
    	printf("%.2f, ", table[i]);

    }
	
    printf("and the sum: \n %.2f,\n ",tab_sort_sum(table, tableSize));

	
    }
	
	

    }
    
    double tab_sort_sum( double *tab, int tab_size )
    {
    	double table[tab_size];
    double sum;
    int i;
	

    for(i= 0; i < tab_size; i++){
    	table[i] = tab[i];
    }



    for(i=0; i < tab_size -1; ++i){
    	int j;
    	double temp;
    	int  min = i;
    	for(j= i+1; j < tab_size; ++j){
    		if(table[j] < table[min]) min = j;
    			}
    			temp = table[i];
    			table[i] = table[min];
			table[min] = temp;
    	}

		
	


    printf("\nThe sorted list\n");	
    for(i = 0; i < tab_size; i++){
    	printf(" %.2f ", table[i]);
    }
    printf("\n");
    for(i = 0; i < tab_size; i++){
    	sum += table[i];

    }
    return sum;
    }
	



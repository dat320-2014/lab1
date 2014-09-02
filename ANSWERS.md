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

cd unixstuff, mdir backups, (, indicates return press)

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

cd NAME gets you to directory NAME, ls lists all files and directory in the current working directory, pwd shows me where i am working

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

cp science.txt science.bak

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

mkdir tempstuff, rmdir tempstuff

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

cat > list2, orange, plum, mango, grapefruit, (ctrl+d) cat list2

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

cat list1 list2 | grep p | sort

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

chmod go-rwx backups, chmod a+rw science.txt

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - it has to be empty
1. What is the command used to display the manual pages for any command?
  man command
1. What command will show the first 5 lines of an input file?
  - head -5 filename
1. What command can be used to rename a file?
  - mv currentfilename newfilename
1. What option can we given to `ls` to show the hidden files?
  - ls -a
1. What will the command `cat -n file` do?
  - displays content inside the file file and with line numbers
1. What will the command `echo -n hello` do?
  - it adds "hello" to the start of your username, so when you write next time it says helloUsername@computername:
1. What command will display s list of the users who currently logged in in the system?
  - who
1. How do you change password on your account?
  - passwd enter oldpassword enter newpassword enter newpassword enter (enter = enterbutton)
1. How can you list a file in reverse order?
  - ls -r
1. What does the `less` command do?
  - writes out content of a file one page at a time
1. With `less` how do you navigate?
  - space bar for another page and q for quit
1. What command will display the running processes of the current user?
  - ps
1. What command can be used to find the process(es) consuming the most CPU?
  - sleep 100 + C (control c), kill PID_number

##vi questions
1. How do we save a file in `vi` and continue working?
  - :w filename
1. What command/key is used to start entering text?
  - "i"for insert, escape for going back to command
1. What are the different modes the editor can be in?
  - insert and command
1. What command can be used to place the cursor at the beginning of line 4?
  - :# 4 #
1. What will `dd` command do (in command-mode)?
  - deletes the line that the cursor is on
1. How do you undo the most recent changes?
  - "u" for undo
1. How do you move back one word?
  - "b"

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - gcc -c hello.c -o hello.o, you dont specify the exe filename and hello.o isnt runnable
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - gcc hello.c -D DEBUG hello -o (debug on) gcc hello.c hello -o (debug off).  
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *YOUR ANSWER HERE*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *YOUR ANSWER HERE*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *YOUR ANSWER HERE*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *YOUR ANSWER HERE*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *YOUR ANSWER HERE*
1. How does `make` know if a file must be recompiled?
  - **Answer:** *YOUR ANSWER HERE*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *YOUR ANSWER HERE*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** *YOUR ANSWER HERE*

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
	}



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
NB! Lab er utført på VM med Ubuntu, med brukernavn linus. Jeg får ikke enkelt linjeskift til å fungere via MarkdownPad 2(kun dobbelt), så teksten kan være litt uoversiktelig. Det er imidlertid korrekt i "koden".

`mkdir unixstuff, cd unixstuff, mkdir backups`
			

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** 
`cd, pwd, ls -a, cd Documents, cd .., cd Videos, pwd ->
 /home/linus/Videos	`		

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** 
`touch science.txt
cp science.txt ./backups`

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:**
`mkdir tempstuff
ls
rmdir tempstuff`

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** 
`cat > list2
orange
plum
mango
grapefruit
^D
cat list2`

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:**
`sort biglist | grep p`
apple
grape
grapefruit
peach
pear
plum

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** 
`chmod a+rwx science.txt2
chmod a+rwx backups
ls -l`
d rwx rwx rwx linus linus 4096 2014-08-31 14.30 backups
- rw- r-- r-- linus linus   66 2014-08-31 14.38 biglist
- rw- r-- r-- linus linus   37 2014-08-31 14.37 list1
- rw- r-- r-- linus linus   29 2014-08-31 14.35 list2
- rwx rwx rwx linus linus    0 2014-08-31 14.29 science.txt
- rw- r-- r-- linus linus   66 2014-08-31 14.39 slist

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** rmdir
1. What is the command used to display the manual pages for any command?
  - **Answer:** man _command_
1. What command will show the first 5 lines of an input file?
  - **Answer:** head -5
1. What command can be used to rename a file?
  - **Answer:** mv _oldName_ _newName_
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** -a
1. What will the command `cat -n file` do?
  - **Answer:** Gives numbers to all lines
1. What will the command `echo -n hello` do?
  - **Answer:** Nothing, as the -n indicates that it should not echo the next line
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** who
1. How do you change password on your account?
  - **Answer:** passwd 
1. How can you list a file in reverse order?
  - **Answer:** sort -r
1. What does the `less` command do?
  - **Answer:** Writes content to screen one page at a time
1. With `less` how do you navigate?
  - **Answer:** [Space] to continue, [q] to quit
1. What command will display the running processes of the current user?
  - **Answer:** ps
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** ps --sort=-pid (given that pid is process consumtion, which it might not be)

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** `:w`
1. What command/key is used to start entering text?
  - **Answer:** `i` for Insert
1. What are the different modes the editor can be in?
  - **Answer:** Command and Insert mode
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** `:4`
1. What will `dd` command do (in command-mode)?
  - **Answer:** Delete the current line
1. How do you undo the most recent changes?
  - **Answer:** `u`
1. How do you move back one word?
  - **Answer:** `b`

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** `gcc hello.c -c`
				.o is an Object file and not an executable file.
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** To compile for debugging, use -g. This will create a a.out file.
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** In theory, the first example should always show the debug code when run in gdc mode couse it looks to see if DEBUG is defined (which it might not be now I guess), while the second one will only show when debug is set to 1, which it is not currently. An advantage of the first way to do it is that it is much easier to find and remove debug code when needed, while an advantage of the second way is that you can debug part of the program at a time. However, I was not able to get the debug comment to print, no matter what i did, using gcc and gdb. Ideally i would like a resource that describes this in more details, as I could not find anything regarding this on isLearning, gitHub or in the course book. That also goes for the rest of this and the next task (although to be fair, make was briefly mentioned on a slideshow). 
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** After googling this for quite some time, the best I can say is that it's possibly something with "-W1,-MAP=output.map", but I am not able to make it work as gcc does not recognise the commands. Some examples would be welcome. Edit: After the next task, I was able to create a .map file. However, as I tried several different commands, I do not know which one worked. Possibly -m?
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** 
  The address to the memory allocation of:
  .txt -> The code
  .data -> Initialized global and static variables
  .bss -> Uninitialized global and static variables
  .rodata -> Constants and strings 
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** Done
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** The assembly instructions looks to be the following:
`.cfi_startproc
pushq %rbp
.cfi_def_cfa_offset 16
movq %rsp, %rbp
.cfi_offset 6, -16
.cfi_def_cfa_register 6
movsd %xmm0, -8(%rbp)
movsd %xmm1, -16(%rbp)
movsd -8(%rbp), %xmm0
mulsd -16(%rbp), %xmm0
leave
ret
.cfi_endproc`

After changing double with float, lines 7-10 changed to:
`movss %xmm0, -4(%rbp)
movss %xmm1, -8(%rbp)
movss -4(%rbp), %xmm0
mulss -8(%rbp), %xmm0
`
So the "d" is changed to "s", and the number value is halved.


1. How does `make` know if a file must be recompiled?
  - **Answer:** The makefile indicated what files make should look at, and make checkes the last change date for them compaired to last compile.
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** `make -f mymakefile`
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** You implement include guard using #ifndef. Include guard is needed to avoid double inclusion, that can happen with parent and child files.

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
		/* I do not know C, but I am somewhat familiar with C# and have read the C introduction ppt, so hopefully I am close. I was not able to run this program, so I know it is not correct. */
	
		table intTable[argc][argc];
		for (i = 0, i < argc, i++)
		{
			for (j = 0, j < argc, j++)
			{
				intTable[i][j] = rand()%(MAX-MIN)+MIN;
			}
		}
		int tableSum = lib1.tab_sort_sum(intTable, argc);
		for (i = 0, i < argc, i++)
		{
			for (j = 0, j < argc, j++)
			{
				printf(intTable[i][j] + "\n");
			}
		}
		printf(tableSum); 
		return 0;
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
		//I assume *tab is the table, as the table is needed as input to sort it
		int tempInt = 0;
		int currentInt = 0;
		int = sum;

		for (i = 0, i < tab_size-1, i++)
		{
			for (j = 0, j < tab_size-1, j++)
			{
				currentInt = *tab[i][j];
				sum =+ currentInt;
				for (k = 0, k =< i, k++;)
				{
					for (l = 0, l =< j, l++;)
					{
						if(currentInt > *tab[k][l])
						tempInt = *tab[k][l];
						*tab[k][l] = currentInt;
						*tab[i][j] = tempInt;
					}
				}

			}
		}
		return sum, *tab;
	}



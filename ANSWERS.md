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

**Answer:** *`mkdir unixstuff/backups`*

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** 

    cd backups
    ls
    pwd
    /home/stud/ronnieb/unixstuff/backups


###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** `cp science.txt science.bak`

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:**
```
    mkdir tempstuff
    rmdir tempstuff 
```

###Exercise 3a

Using the above method, create another file called `list2` containing the following fruit: orange, plum, mango, grapefruit. Read the contents of `list2`.

**Answer:** 
```
    cat > list2
    orange
    plum
    mango
    grapefruit
    ^D
    cat list2` 
```

###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** `cat list1 list2 | grep p | sort` 

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** 
```
chmod o-rwx science.txt
chmod ug+rwx backups
ls -l
```

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** `rm -r`
1. What is the command used to display the manual pages for any command?
  - **Answer:** `man x` 
1. What command will show the first 5 lines of an input file?
  - **Answer:** `head -5`
1. What command can be used to rename a file?
  - **Answer:** `mv oldfilename newfilename`
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** `ls -a`
1. What will the command `cat -n file` do?
  - **Answer:** It will number all the output lines. 
1. What will the command `echo -n hello` do?
  - **Answer:** Echo hello without trailing newline.
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** `who` 
1. How do you change password on your account?
  - **Answer:** `passwd` 
1. How can you list a file in reverse order?
  - **Answer:** `tail -r file`
1. What does the `less` command do?
  - **Answer:** List the content of a file one page at a time.
1. With `less` how do you navigate?
  - **Answer:** Down with enter. Or use pgup/pgdown or arrow keys.
1. What command will display the running processes of the current user?
 - **Answer:** `ps`
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** `top`

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** Enter command mode, then :w 
1. What command/key is used to start entering text?
  - **Answer:** From command mode: i (insert)
1. What are the different modes the editor can be in?
  - **Answer:** Command mode, Insert mode, Replace mode, 
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** In command mode, type :4
1. What will `dd` command do (in command-mode)?
  - **Answer:** Moves current line to buffer (deletes it).
1. How do you undo the most recent changes?
  - **Answer:** u from command mode
1. How do you move back one word?
  - **Answer:** b (small b) from command mode.

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** The `-c` option tells gcc not to run the linker. The source code file is only compiled to machine language (.o-file), it is not linked. So the .o-files are not executable. 
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** *`gcc -DDEBUG file.c -o file` In Listing 2 you have to compile with the -DDEBUG option on gcc. For Listing 3 you dont need -DDEBUG option, you just have to change the debug variable to 1.*
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** *In Listing 2 we use a preprocessor directive. This means that if we use the option `-D DEBUG` on gcc, the text within the `#IFDEF` will be copied into the sourcefile. So during our final release we can omit this code, which gives us a smaller size on the executable. In Listing 2 the code will always be there unless we go into each sourcefile and manually remove that code.*
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** *`gcc -Xlinker -Map=hello.map -o hello.c` This command produces both the map and the executable. The linker (ld) is responsible for creating the map file.*
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** *YOUR ANSWER HERE*
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:** *YOUR ANSWER HERE*
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** *With double:*
```
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
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	multiply, .-multiply
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-4)"
	.section	.note.GNU-stack,"",@progbits
```
*With float:*
```
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
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	multiply, .-multiply
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-4)"
	.section	.note.GNU-stack,"",@progbits

```
*In the first snippet MOVSD (Move Scalar Double-Precision Floating-Point Value) ia used. In the second, MOVSS (Move Scalar Single-Precision Floating-Point Value) is used.*

1. How does `make` know if a file must be recompiled?
  - **Answer:** *From the man-page: Make uses the last-modification times of the files to decide which files needs to be updated.*
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** *`make -f mymakefile`*
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** *An include guard is needed to prevent double inclusions. If two .c-files includes the same .h-file this can cause compilation errors. For example you can end up with two equal function definitions if you forget include guards. Heres an example of an include guard, this can be put in a header-file:*

```
#ifndef _HEADER_H_
#define _HEADER_H_

/* Code here */

#endif // #ifndef _HEADER_H_
```

##Library Task

Insert your code between the brackets `{}`:

    void main( int argc, char *argv[] )
	{
    }
    
	double tab_sort_sum( double *tab, int tab_size )
	{
	}



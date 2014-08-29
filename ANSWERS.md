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

**Answer:** `~/unixstuff$ mkdir backups`

###Exercise 1b

Use the commands `cd`, `ls` and `pwd` to explore the file system.

(Remember, if you get lost, type `cd` by itself to return to your home-directory)

**Answer:** `cd backups` `pwd` `cd ..` `ls`

###Exercise 2a

Create a backup of your `science.txt` file by copying it to a file called `science.bak`

**Answer:** `cp -T sci[tab] science.bak`

###Exercise 2b

Create a directory called `tempstuff` using `mkdir`, then remove it using the `rmdir` command.

**Answer:** `mkdir tempstuff` `rmdir tem[tab]`

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
cat list2
```
###Exercise 3b

Using pipes, display all lines of `list1` and `list2` containing the letter 'p', and sort the result.

**Answer:** `grep p list1 list2 | sort` 

###Exercise 5a

Try changing access permissions on the file `science.txt` and on the directory `backups`.

Use `ls -l` to check that the permissions have changed.

**Answer:** `chmod go+rw science.txt` `chmod go-rwx backups` `ls -l`

##Shell questions

1. What option with the command `rm` is required to remove a directory?
  - **Answer:** `-r`, `-R` or  `-recursive`
1. What is the command used to display the manual pages for any command?
  - **Answer:** `man <cmd>` or  `help <cmd>`, `whatis <cmd>`, `info <cmd>`
1. What command will show the first 5 lines of an input file?
  - **Answer:** `head -n 5 <file>`
1. What command can be used to rename a file?
  - **Answer:** `mv <oldfile> <newfile>` or `rename <old> <new> <file(s)>`
1. What option can we given to `ls` to show the hidden files?
  - **Answer:** `-a`
1. What will the command `cat -n file` do?
  - **Answer:** Prints contents of file with enumerated lines.
1. What will the command `echo -n hello` do?
  - **Answer:** Prints "hello" without automatically appending a newline char.
1. What command will display s list of the users who currently logged in in the system?
  - **Answer:** `who` or `users` (`users | sed 's/ /\n/g' | uniq`)
1. How do you change password on your account?
  - **Answer:** `passwd`
1. How can you list a file in reverse order?
  - **Answer:** `tac <file>` (linewise)
1. What does the `less` command do?
  - **Answer:** Lazily reads files and allows for backtracing. 
1. With `less` how do you navigate?
  - **Answer:** [space] for next page
1. What command will display the running processes of the current user?
  - **Answer:** `ps` `pstree` `top` `top??`
1. What command can be used to find the process(es) consuming the most CPU?
  - **Answer:** `top`

##vi questions
1. How do we save a file in `vi` and continue working?
  - **Answer:** `:w[Enter]` in normal-mode
1. What command/key is used to start entering text?
  - **Answer:** `i`
1. What are the different modes the editor can be in?
  - **Answer:** normal / insert / visual / select / command-line / ex-mode
1. What command can be used to place the cursor at the beginning of line 4?
  - **Answer:** `4gg`, `4G` or `:4[Enter]`
1. What will `dd` command do (in command-mode)?
  - **Answer:** dd is a linewise delete function
1. How do you undo the most recent changes?
  - **Answer:** `u` `:undo[Enter]`
1. How do you move back one word?
  - **Answer:** `b`

##The C Language and Make tool Questions

1. How do you use `gcc` to only produce the `.o` file?  What is the difference between generating only the `.o` file, and building the `hello` executable done in the previous compilation above?
  - **Answer:** `gcc -c <sourcefile>` The object file is not linked
1. Give the command for compiling with `debug` enabled instead of normal compilation for the two examples shown in Listing 2 and Listing 3. Explain how to turn debugging on/off for the two cases.
  - **Answer:** Listing 2: `gcc -DDEBUG <sourcefile>`, `-g` is similar but does not define anything. *(NDEBUG may however NOT be defined) 
  Listing 3: global var `debug` must be changed in source in order to toggle.
1. Give a brief pros and cons discussion for the two methods to add debug code shown in Listing 2 and Listing 3.
  - **Answer:** Listing 2 requires compile time config but is efficient. Listing 3 can potentially be toggled during runtime but may cause efficiency reduction in tight loops regardless of mode (if self modification is not allowed/implemented)
1. Provide the command for generating the *map* file. Which of the `gcc` tools is responsible for producing a *map* file?
  - **Answer:** `-Wl,-Map=mymap.map` (`-Wl,-Map,mymap.map` for non-GNU). Arguments are passed on as linker is not part of gcc
1. What is the content of each of the sections in a *map* file. Explain briefly.
  - **Answer:** The map shows address resolutions, .data, .code, etc sections size and position, archive members included and allocated symbols and their assigned value.
1. Rewrite `hello.c` to produce entries in the *map* file for `.data`, `.bss`, and `.rodata`. Hint: This can be done by adding one variable for each type to the file.
  - **Answer:**
```
const char debug_cmt[] = "Some smart debugcomment\n";
const char hello[]     = "Hello world!\n";
const int  retval      = 0;
```
1. Add the following function to `hello.c`: `double multiply(double x1, double x2)`, which returns `x1*x2`. Use `gcc` to generate an assembly code listing for the program, and examine the assembly code. What assembly instructions are used to do this? Repeat this task, but now replace `double` with `float`. Explain!
  - **Answer:** `gcc -O -S dmult.c` (took the liberty of optimizing)
  Examining dmult.s & fmult.s: `mulsd    %xmm1, %xmm0` scalar double as opposed to `mulss    %xmm1, %xmm0` scalar single mult. instruction. Single (float) operates on half the bit-size of double. It is thus curious how gcc chooses to use the 128bit XMM registers on both accounts.
1. How does `make` know if a file must be recompiled?
  - **Answer:** The source file is 'newer' than the currently compiled file, or the file does not exist.
1. Provide a `make` command to use a file named `mymakefile` instead of the default `makefile`.
  - **Answer:** `make -f mymakefile`
1. How do you implement an *include guard*, and why is it needed?
  - **Answer:** Include guards prevent common libraries and headers being imported several times. It looks like this:
```
#ifndef IVEBEENHEREBEFORE
#define IVEBEENHEREBEFORE
// do header stuff
#endif
```
##Library Task

Insert your code between the brackets `{}`:

**main.c:**
```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "l1.h"

void main( int argc, char *argv[] )
{
    int
      size = 4,
      min = 0,
      max = 100,
      range = max - min,
      table[size][size];
    srand( time( NULL )); // seed random generator
    for ( int i = size; i >= 0; i-- )
    {
        for ( int j = size; j >= 0; j-- )
        {
            table[i][j] = rand_in_range( min, range );
        }
    }

    double sum = tab_sort_sum( ptable, size );

    int cell_width = 10; // log_2( max ) + 1
    char *format[6];
    sprintf( format, '%%%dd', cell_width ); // e.g. '%10d'
    char *line[size * cell_width + 1];

    for ( i = 0; i < size; i++ ) // each row
    {
        for ( j = 0; j < size; i++ ) // each column -  build line buffer
        {
            sprintf( line, format, table[i][j] );
            line += cell_width; // assuming char is 8bit!
        }
        printf( '%s\n' line );
        // No need to clean up the buffer. Rows have equal length
    }
    printf( 'SUM: %20d\n', sum );
}

int rand_in_range( int min, int range )
// Returns number within range with maintained random disribution.
// min + range must not exceed INT_MAX
{
    unsigned long
      intsize    = (unsigned long) INT_MAX + 1, 
      groupsize  = intsize / (unsigned long) range,
      failmargin = intsize % groupsize;
    long r;
    while ( intsize - failmargin <= (unsigned long) (r = rand()) );
    return min + (int) (r / groupsize);
}
```
**l1.c:**
```
double tab_sort_sum( double *tab, int tab_size )
{
    return 0.0;
}
```
**makefile:**
```
main: main.c l1.h
    gcc main.c -O -o main
l1.h: l1.c
    gcc l1.c -c -O -o l1.h
```


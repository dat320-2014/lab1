This is just a test

Introduction
============

The overall aim of the lab in this course is to learn how to develop
systems, where some degree of low-level tuning is necessary to obtain
the desired performance. We will do this through a series of lab
exercises that will expose you to developing an application in the Go
programming language, and some of the tools that people frequently use
to tune such applications. Specifically you will learn about a
performance (CPU/memory) profiler and race detector. In addition to
developing this application, we will also require that you develop a
Linux kernel module (a driver) that we will eventually use together with
the Go application. This will also expose you to the challenges of
interacting with Linux system calls written in C from the Go language.
To develop the Linux kernel drivers, it is convenient to use a virtual
machine running Linux.

#### Handin:

For every lab, you are required to write a report, including answers to
questions. And upload submit on git [^1] You should also hand in your
source files. Do this by uploading a zip or tgz file to ITL, named
`lab1groupX.zip`. Please put all your code in a folder called src. This
first lab has to be handed in, but will not be graded. The directory
structure of the zip or tgz file must be, where `X` is replaced with
your group’s number:

     lab1/groupX/src/<somefile>.go

The Linux Lab
=============

Lab sessions will be held in the <span>Linux lab</span> in E353, where
the machines are named: <span>pitter</span>1 - <span>pitter</span>40.
All necessary software should be installed on these machines. Also, the
lab project will include a networking part, requiring you to run your
code on several machines, or at least from different ports on the
localhost. This can be conveniently done using the machines in E353.

To be able to log into the machines in E353 you need an account on the
Unix system.

#### Task:

* Get an account for UiS’ Unix system, following the instructions on
[**user.ux.uis.no**](http://user.ux.uis.no/).*

#### 

You can use `ssh`[^2] to log on to another machine without physically
going to that machine and login there. This makes it easy to run and
test the example code and your project later. To log onto a machine
using `ssh`, open a terminal window and type a command according to this
template, and make sure to replace username and hostname:

      ssh username@hostname

For example to log on to one of the machines in the <span>Linux
lab</span>

    ssh username@%\machine{}18.\domain%

this will prompt for your password. Enter your account password and you
will be logged into that machine remotely.

You can avoid having to type the password each time by generating a
public-private key-pair using the `ssh-keygen` command (see the man
pages for `ssh-keygen`). Type

      man ssh-keygen

and read the instructions. Then try running this command to generate
your key-pair; make sure that once asked to give a password, just press
enter at the password prompt. Once the key-pair have been generated,
copy the public-key file (ends with `.pub`) to a file named
`authorized_keys`. If you have multiple keys in the latter file, make
sure not to overwrite those keys, and instead paste the new public-key
at the end of your current file. After having completed this process,
try `ssh` to another machine and see whether you have to type the
password again.

Another tip: If you are running from a laptop and wish to remain
connected even if you close the laptop-lid, you can check out the `mosh`
command[^3].

Basic Linux commands
--------------------

To get a feeling for how to work with the Linux shell, we are going to
try out several different commands. We will use parts of the online
tutorial found at
[www.ee.surrey.ac.uk/Teaching/Unix/](http://www.ee.surrey.ac.uk/Teaching/Unix/).

#### Task:

* Do the exercises from tutorials 1 to 6 at
[www.ee.surrey.ac.uk/Teaching/Unix/](http://www.ee.surrey.ac.uk/Teaching/Unix/).
*

#### 

For later lookup, a more condensed tutorial can be found at\
[freeengineer.org/learnUNIXin10minutes.html](http://freeengineer.org/learnUNIXin10minutes.html).

Shell questions
---------------

What option with the command “rm” is required to remove a directory\`?
What is the command used to display the manual pages for any command?
What command will show the first 5 lines of an input file? What option
can we given to “ls” to show the hidden files? What will the command
“cat -n file” do? What will the command “echo -n hello” do? What command
will display s list of the users who currently logged in in the system?
How do you change password on your account? How can you list a file in
reverse order? What does the “less” command do? With “less” how do you
navigate?

The vi / vim editor
-------------------

In later labs we will be forced to use the *vi*-editor and the the
improved version *vim*. This editor can be a bit hard to get used to,
but it is quite useful to have some hands on experience with the *vi*
editor, because it is almost always available on Unix systems. On very
stripped down Linux systems, e.g. on embedded systems like routers,
set-top boxes, typically the only editor available is *vi*. Once you get
used to it, *vi* is actually quite powerful, and many people prefer it,
even over fully fledged IDEs for programming.

#### Task:

* Walk through the information found here:
<http://www.arekdreyer.com/articles/crash-course-on-running-the-vi-editor>.*

vi questions
------------

How do we save a file in `vi` and continue working? What command/key is
used to start entering text? What are the different modes the editor can
be in? What command can be used to place the cursor at the beginning of
line 4? What will *dd* command do (in command-mode)? How do you undo the
most recent changes? How do you move back one word?

The <span>*C language*</span>
=============================

In this lab we will first provide some basic introduction to the
<span>*C language*</span>. You will learn how to build a small program
in C, how to compile and execute it, and how to extend the program with
libraries. You will also get to know the *make* utility and learn how to
automate the process of building an application written in C. This is
typically a little bit more difficult than doing the same in Java, but
since lots of legacy code out there rely on programmers with C
knowledge, by completing this course, you will have an edge over your
peers who doesn’t know these tools.

Even though the <span>*C language*</span>is almost 40 years old, it is
still one of the most important computer languages. This is mainly
because it enables the programmer to do low-level bit manipulation and
access memory in a way that most higher-level languages prevent users
from doing. The <span>*C language*</span>is the primary language for
write operating systems such as Windows, Linux, and MacOS X is also
partially written in C. And for building embedded systems there is
virtually no other viable language.

Hello world
-----------

To get started with C, it is customary to implement the good old *Hello,
world!* program.

#### Task:

* Start a terminal window on a lab-machine and create the file shown in
Listing [lst:helloworld] using vim, and save it as
<span>`hello.c`</span>*

Compile the program by using the following command:

<span>`gcc hello.c -o hello`</span>

The <span>`-o`</span> flag lets you specify the output (executable) file
name, <span>`hello`</span> in this case. Before continuing, inspect the
current directory using the <span>`ls`</span> command to confirm that
the file has been compiled. Run the command by typing
<span>`./hello`</span> in the terminal window, which should give you:

<span>`Hello, world!`</span>

As will be explained in the introduction lecture before this lab, the
<span>`gcc`</span> compiler does a lot of things behind the scenes.

#### Questions:

How do you use <span>`gcc`</span> to only produce the <span>`.o`</span>
file? What is the difference between generating only the
<span>`.o`</span> file, and building the <span>`hello`</span> executable
done in the previous compilation above?

Returning to the compile to executable binary. Rewrite
<span>`hello.c`</span> so that parts of the program only executes if
compiled in <span>`debug`</span> mode. That is, it should output:

<span>`Debugging`</span>\
<span>`Hello, world!`</span>

#### Questions:

Give the command for compiling with *debug* enabled instead of normal
compilation for the two examples shown in Listing [lst:ifdefdebug] and
Listing [lst:intdebug]. Explain how to turn debugging on/off for the two
cases. Give a brief pros and cons discussion for the two methods to add
debug code shown in Listing [lst:ifdefdebug] and Listing [lst:intdebug].

To examine the internals of an executable file, the linker can be told
to generate a <span>*map* file</span>. The content of the <span>*map*
file</span>contains several sections, including: <span>`.text`</span>,
<span>`.data`</span>, <span>`.bss`</span>, and <span>`.rodata`</span>.

#### Questions:

Provide the command for generating the <span>*map* file</span>. Which of
the <span>`gcc`</span> tools is responsible for producing a <span>*map*
file</span>?

What is the content of each of the sections in a <span>*map*
file</span>. Explain briefly.

Rewrite <span>`hello.c`</span> to produce entries in the <span>*map*
file</span>for <span>`.data`</span>, <span>`.bss`</span>, and
<span>`.rodata`</span>. Hint: This can be done by adding one variable
for each type to the file.

Add the following function to <span>`hello.c`</span>:
<span>`double multiply(double x1, double x2)`</span>, which returns
<span>`x1*x2`</span>. Use <span>`gcc`</span> to generate an assembly
code listing for the program, and examine the assembly code. What
assembly instructions are used to do this? Repeat this task, but now
replace <span>`double`</span> with <span>`float`</span>. Explain!

The ’make’ tool
===============

On Unix systems <span>`make`</span> is an important build tool. In
particular, many programs written in C/C++ depends on
<span>`make`</span><span>[^4]</span> to compile, build, and install
software. For this part of the lab, run through the example found at
http://mrbook.org/tutorials/make/

#### Questions:

How does <span>`make`</span> know if a file must be recompiled? Provide
a <span>`make`</span> command to use a file named
<span>`mymakefile`</span> instead of the default
<span>`makefile`</span>.

Using Make: A simple example with library dependencies
------------------------------------------------------

In this section of the lab, we are going to develop a small C
application that makes use of a library. The library is called:
<span>`lib1`</span>. The dependency is illustrated here:
$$app\rightarrow lib1$$

A skeleton of the code is given in the following listings:

    void main( int argc, char *argv[] )
    {
        //Make a table of size give by an argument on the command line.
        //Fill the table with random numbers between MIN and MAX
        //MIN = 0.0 if not specified with another value on command line, i.e. optional argument
        //MAX = 100.0 if not specified with another value on command line, i.e. optional argument
        //Call tab_sort_sum() in lib1
        //Print out table and sum
    }

    double tab_sort_sum( double *tab, int tab_size )
    {
        //Sort the table, return the sum and the sorted table
    }

#### Task:

* Write the two C files (main.c, l1.c) and prepare the corresponding
makefile to compile an executable. You must also make corresponding
<span>`.h`</span> files (l1.h): Make sure that dependencies are handled
correctly. The makefile should also contain a ’TEST’ target, where all C
files are compiled and tested. You can choose if you want to use
specific C files for testing, or if you add test code to the existing
files. When executing the ’TEST’ target necessary app’s and lib’s must
be built and a test executed. A failing test should fail ’make’.*

#### Questions:

How do you implement an *include guard*, and why is it needed?

Tips
----

The following should be done to check that your <span>`makefile`</span>
is correct:

-   If you delete a single <span>`.o`</span> file. Does
    <span>`make`</span> rebuild only the necessary files?

-   If you delete a <span>`lib`</span> file, does the rebuild work as it
    should?

-   If you change a <span>`.h`</span> file (e.g. save it to refresh its
    timestamp), does <span>`make`</span> rebuild the correct files?

Deliverable
===========

A *small* report where all questions are answered. In assignments where
there are several programming steps, only the last need step need to be
included. For example, only the last version of the *Hello, world!*
program needs to be delivered.

[^1]: A document with instruction how to use git will be provided.

[^2]: Secure SHell - gives you a secure remote login prompt.

[^3]: <http://mosh.mit.edu/>

[^4]: For those of you familiar with Java, a popular tool for building
    large Java projects these days are <span>`Maven`</span>, which can
    also help to manage dependencies between libraries used by your
    project. Another popular tool for Java projects is called
    <span>`Ant`</span>, which is very similar to <span>`make`</span>.

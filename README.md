Introduction
============

The overall aim of the lab in this course is to learn how to develop systems,
where some degree of low-level tuning is necessary to obtain the desired
performance. We will do this through a series of lab exercises that will expose
you to developing an application in the Go programming language, and some of
the tools that people frequently use to tune such applications. Specifically
you will learn about a performance (CPU/memory) profiler and race detector. In
addition to developing this application, we will also require that you develop
a Linux kernel module (a driver) that we will eventually use together with the
Go application. This will also expose you to the challenges of interacting with
Linux system calls written in C from the Go language. To develop the Linux
kernel drivers, it is convenient to use a virtual machine running Linux.


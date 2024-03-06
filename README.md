## Table of Contents:
1. a step-by-step description of how to compile this source code and run this shell,
2. an explanation of how to use this shell,
3. a list of what functions this shell contains, and
4. citations of any resources David used in completing this project.

## 1 - How to Compile & Run

After decompression, have your system console open inside of the folder, same folder as the one this README is in. After hitting `ls` you should see:

* Makefile
* shell (executable)
* shell.o (object file)
* README.md (this file you're reading)
* shell.c (source code)

If you'd like to recompile the 'shell.c' file, whether you modify it, or find me a untrustworthy author, run: `make all` in your terminal after deleting 'shell.o' & 'shell' execution files.

This `make all` command creates an executable with the name 'shell' which will naturally overwrite any previous file of the same name. To start the shell SAFELY, enter `make run`.

## 2 - How to use David's Shell

David's shell has several more working commands than the original Linux shell - used in many difficult computers today - giving the software a steep learning curve.

When you run the command `make run`, your shell makes a child shell: David's shell. Until you type in and hit `enter` the command `Q`, you'll keep running the child shell. Once you quit, the child dies abruptly and you'll return to the shell you've run `make run`.

These things are happening all in what seems like one window, because the shell is actually just broadcasting data through your system's terminal emulator. The shell is a program and can be a running process.

While David's shell is running, execute commands like `Q` below just the same way by hitting `enter` right after them...UNLESS they have what we call "arguments". For the user's physical & mental saftey, David's shell only allows strict adherence to the following command structures.

## 3 Shell Functions / Reference

When David's shell is running, instead of getting scared and immediately hitting `Q` this time, lets try entering the command `H` and reading over:

```
A Simple Linux Shellp:
======================
>C [file1] [file2]      - Copy [file1] + Paste to [file2].
>D [file]               - Delete [file].
>E [comment]            - Print [comment] (echo).
>H                      - Help me!
>L                      - List current directory contents, no arguments.
>M [file]               - Create [file] w/ nano, which is a choice...
>P [file]               - Display the contents of [file].
>Q                      - Quit.
>S                      - Launches firefox.
>W                      - Clears the console.
>X [program]            - Execute [program].
======================================================================

3 BASIC RULES:
==============
1.) Internal commands are case sensitive.
2.) Provide ONLY the necessary arguments, or use an external command.
3.) Unlisted/Unrecognized commands ARE external commands.
======================================================================
```

Internal commands are ones we've crafted in-house for David's Shell.

External commands are from your own system or imagination, *our developer cannot say for certain these external commands won't harm your computer.*

## 4 CITATIONS

* IBM Documentation Site: <br> z/OS C/C++ Runtime Library Reference
https://www.ibm.com/docs/en/zos/3.1.0?topic=files-cc-header

* CPSC 489 DevOps: Project 1 - "Makefile" (Submitted 02/12/14)
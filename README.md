Simple Shell:
 A shell terminal, also known as a command line interface or CLI, is a text-based interface used to interact with an operating system or application.

Descritpion:
 It allows users to input commands through a keyboard and receive output in text format on a screen.
The shell also is an infinity loop that keep running until exit command or end of file.
The basic program logic: what does the shell do during its loop? Well, a simple way to handle commands is with three steps:

*Read: Read the command from standard input.
*Parse: Separate the command string into a program and arguments.
*Execute: Run the parsed command.

1) First step /Read :
	Reading a line from stdin using the function read_line();

2) Second step /parse:
	We need to parse that line into a list of arguments.
	We won’t allow quoting or backslash escaping in our command line arguments. Instead, we will simply use whitespace to separate arguments from each other. So the command echo "this message" would not call echo with a single argument this message, but rather it would call echo with two arguments: "this and message".

3) Third Step /Execute : execute_cmd();
	After read  split the line into a liste of arguments we need to execute our commande using the execve commande and return print the ruslt into the screen then return to our loop from begining because its an infint loops 

Our program wait the user to write "exit" that end the process.

Compilation && exemples
 Our code is compiled using the command
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

INTERACTIVE MODE:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

NON-INTERACTIVE MODE:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

AUTHORS:
Ramzi Hkiri
facebook: https://www.facebook.com/ram.hki
instagram: https://www.instagram.com/ramzi_hkiri/
linkedIn: https://www.linkedin.com/in/hkiri-ramzi/

COPYRIGHT:
Copyright (C) 2023 @RAMZI_HKIRI on 27/04/2023

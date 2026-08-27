# Simple Shell

## Description

Simple Shell is a UNIX command-line interpreter written in C.

The project is designed to provide a basic understanding of how a shell works, including process creation, command execution, environment variables, and the use of the `PATH` to locate programs.

## Installation

Clone the repository:

```bash
git clone https://github.com/<@14870-source>/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell
```

## Compilation

Compile the shell using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

Run the shell in interactive mode:

```bash
./hsh
```

Example:

```text
($) /bin/ls
AUTHORS  README.md  main.c  shell.c
($) /bin/pwd
/home/user/holbertonschool-simple_shell
($) exit
```

The shell can also be used in non-interactive mode:

```bash
echo "/bin/ls" | ./hsh
```

## Features

* Execute commands using their full path.
* Search for commands using the `PATH` environment variable.
* Execute commands in both interactive and non-interactive modes.
* Handle the `exit` built-in command.
* Handle the `env` built-in command.
* Create and manage processes using `fork()`.
* Execute programs using `execve()`.
* Wait for child processes using `wait()`.

## System Calls and Functions

The project uses several UNIX system calls and standard C library functions, including:

* `fork()` - creates a new process.
* `execve()` - executes a program.
* `wait()` - waits for a child process to finish.
* `getline()` - reads a line from standard input.
* `access()` - checks whether a file can be executed.
* `isatty()` - checks whether standard input is connected to a terminal.

## Authors

* Shaden Saad , Layan Abdulrahman Alghayama


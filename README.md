# Simple Shell

Simple shell is a UNIX command interpreter. It's designed to mimic Bash.

## Requirements

* Allowed editors: vi, vim, emacs
* All files are compiled on Ubuntu 14.04 LTS
* Programs and functions are compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Code should use the Betty style. It is checked using betty-style.pl and betty-doc.pl
* No more than 5 functions per file
* All header files should be include guarded
* Use system calls only when needed

## List of allowed functions and system calls

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage
The shell works like this in interactive mode:

```bash
$ ./hsh
#cisfun$ /bin/ls
hsh main.c shell.c
#cisfun$
#cisfun$ exit
$
```

The shell works like this in non-interactive mode:

```bash
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
```

## Supported Builtin Functions

| Builtin | Description |
|:-------:| ----------- |
| alias | Define or display aliases |
| cd | Change the shell working directory |
| env | Display the environmental variables |
| exit | Exit the shell |
| help | Display information about builtin commands |
| setenv | Set an environmental variable |
| unsetenv | Unset an environmental variable |

## Examples

```bash
$ ./hsh
#cisfun$ ls
AUTHORS		file		search_path.c	string_helper2.c
README.md	get_built_in.c	shell.c		string_helper3.c
built_ins.c	hsh		shell.h		test_cats
execute.c	ls		string_helper.c	test_ls_2
#cisfun$
```

## Authors

[Brent Muha](https://github.com/bmuha1)

[Sudeep Raj](https://github.com/rajsudeep)

# Brent and Sudeep's Blue Shell

![Image of Blue Shell]
(https://i.imgur.com/1vMhRiL.png)

Brent and Sudeep's Blue Shell is a UNIX command interpreter. It's designed to mimic Bash.

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
<^^^> /bin/ls
hsh main.c shell.c
<^^^> exit
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

## Flowchart

![Image of Flowchart]
(https://i.imgur.com/GUtPTTZ.jpg)

## Supported Builtin Functions

| Builtin | Description |
|:-------:| ----------- |
| cd | Change the shell working directory |
| env | Display the environmental variables |
| exit | Exit the shell |
| help | Display information about builtin commands |
| setenv | Set an environmental variable |
| unsetenv | Unset an environmental variable |

## Examples

```bash
$ ./hsh
<^^^> ls -l
total 108
-rw-rw-r-- 1 vagrant vagrant   154 Aug 27 21:03 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  2534 Aug 27 21:03 README.md
-rw-rw-r-- 1 vagrant vagrant  1176 Aug 27 21:03 built_ins.c
-rw-rw-r-- 1 vagrant vagrant   545 Aug 27 21:03 execute.c
---------- 1 vagrant vagrant     0 Aug 26 17:18 file
-rw-rw-r-- 1 vagrant vagrant   505 Aug 27 21:03 get_built_in.c
-rwxrwxr-x 1 vagrant vagrant 28081 Aug 27 20:46 hsh
-rwxrwxr-x 1 vagrant vagrant 23810 Aug 26 19:10 ls
-rw-rw-r-- 1 vagrant vagrant    89 Aug 27 17:20 oldpath.txt
-rw-rw-r-- 1 vagrant vagrant  1220 Aug 27 21:03 search_path.c
-rw-rw-r-- 1 vagrant vagrant  1268 Aug 27 21:03 shell.c
-rw-rw-r-- 1 vagrant vagrant  1257 Aug 27 21:03 shell.h
-rw-rw-r-- 1 vagrant vagrant  2921 Aug 27 13:43 string_helper.c
-rw-rw-r-- 1 vagrant vagrant  1348 Aug 27 21:03 string_helper2.c
-rw-rw-r-- 1 vagrant vagrant   827 Aug 25 15:27 string_helper3.c
-rw-rw-r-- 1 vagrant vagrant    45 Aug 26 17:44 test_cats
-rw-rw-r-- 1 vagrant vagrant    16 Aug 25 19:40 test_ls_2
<^^^> setenv env_test 5
<^^^> echo $env_test
5
<^^^> pwd
/home/vagrant/simple_shell
<^^^> cd ..
<^^^> pwd
/home/vagrant
<^^^> qwerty
./hsh: 7: qwerty: not found
<^^^> echo $?
127
<^^^> echo $$
30935
<^^^> help # This is a comment
These shell commands are defined internally.  Type `help' to see this list.
Type `help name' to find out more about the function `name'.
cd
env
exit
help
setenv
unsetenv
<^^^> ^C
<^^^> ^C
<^^^> ^C
<^^^> exit
$
```

## Authors

[Brent Muha](https://github.com/bmuha1)

[Sudeep Raj](https://github.com/rajsudeep)

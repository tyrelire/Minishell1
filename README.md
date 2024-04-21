# Epitech Project, first Year -> Minishell1

## Description
Minishell1 is a basic UNIX command interpreter designed to work on the terminal. It provides a command-line interface similar to 42sh while focusing on basic functionalities.

## Version
2.0

## Binary Command
Binary command name: `mysh`

## Project Directory
Repository name: `PSU_minishell1_$ACADEMICYEAR`

## Directory Rights
Directory rights: `ramassage-tek`

## Language
Programming language: C

## Compilation
Compilation is done via a Makefile, including `re`, `clean`, and `fclean` rules.

## Directory Contents
The directory must contain all source files, excluding any unnecessary files (binary, temporary files, object files, etc.).

Bonus files, including any specific Makefile, should be placed in a directory named `bonus`.

## Error Handling
Error messages should be written to the error output, and the program should exit with error code 84 (0 if there is no error).

## Features
The interpreter must:
- Display a prompt (`$>`, for example) and wait for the user to enter a command line, validated by a newline.
- Display the prompt again only after the command execution.
- Execute only basic command lines; no handling of pipes, redirections, or other advanced features is expected.
- Use executables found in the PATH variable.
- Display an error message and the prompt again if the executable is not found.
- Properly handle the PATH and the environment (by copying and restoring the initial environment).
- Implement the following builtins: `cd`, `setenv`, `unsetenv`, `env`, `exit`.
  - `env` should not take any argument.
  - `unsetenv` should not support the `*` wildcard.

## Reference Shell
The reference shell is TCSH.

## Authorized Functions
Authorized functions include:
- malloc, free, exit, opendir, readdir, closedir, getcwd, chdir
- fork, stat, lstat, fstat, open, close, getline
- read, write, execve, access, isatty, wait, waitpid
- wait3, wait4, signal, kill, getpid, strerror, perror, strsignal

## Documentation
Don't forget to refer to the man pages for comprehensive documentation.

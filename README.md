# pipex
Fourth project of 42cursus.

This is a project to reproduce the shell behavior of redirecting STDIN and STDOUT to files and emulating pipes. Runs only on macOS and linux systems.
Compile main or bonus part of the project and then type the one of the commands listed below.

```./pipex infile cmd1 cmd2 outfile``` - main part \
The arguments will be processed as same as < infile cmd1 | cmd2 > outfile on the shell.

```./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile``` - bonus part \
The arguments will be processed as same as < infile cmd1 | cmd2 | cmd3 | ... cmdn > outfile on the shell.

The bonus part supports not only overwriting the output file, but also adding to it. For this, the first argument must be set here_doc, as in the example below: \
```./pipex here_doc STOP cmd1 cmd2 cmd3 ... cmdn outfile```


Makefile actions are listed below.

Compilation:
- run "make"

Compilation with a bonus part of the project (multiple pipelines):
- run "make bonus"

Clean object files:
- run "make clean"

Full clean object and library files:
- run "make fclean"

Recompilation:
- run "make re"

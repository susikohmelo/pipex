# Pipex <img align="left" src="https://github.com/susikohmelo/pipex/blob/main/readme_files/score.png" height="120"/>
A general practice project about pipes & executing commands. A fairly short project, and commented, so it should be easy to read through.
## Build & run
Download the repo and run `make` at the root of the repository.

*The program takes (1) an input file - (2) a command - (3) another command - (4) an output file.<br/>*
Functionally it is the same as doing `< file1 cmd1 | cmd2 > file2` in bash.

Example:
` ./pipex infile "ls -l" "wc -l" outfile`

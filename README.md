# 42KL Core Program - pipex

## About
The goal of this project is to learn how to manipulate input read from a file via commands, and store the final output in a different file. Key concepts learned to accomplish this are: `pipes`, `forking processes`, and `file descriptors`.

### Mandatory

The program should be executed in the following manner: ./pipex file1 cmd1 cmd2 file2

It should produce the same output as the following shell command: < file1 cmd1 | cmd2 > file2

### Bonus

* Handle multiple pipes (more than 2 commands): ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
  * It should produce the same result as the following shell command: < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
  
* Support « and » when the first parameter is "here_doc": ./pipex here_doc LIMITER cmd cmd1 file
  * It should produce the same result as the following shell command: cmd << LIMITER | cmd1 >> file
  
  
*My pipex only handles the multiple pipes.*

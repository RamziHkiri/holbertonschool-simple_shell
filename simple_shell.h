#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include <sys/wait.h>
#include <stddef.h>
char *read_line(void);
void inf_loop(void);
void execute_cmd(char **cmd);
char **split_line(char *line);
#endif

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
/**
 * struct builtins - builtins function's struct
 * @commande:commande
 * @func: pointer function
 */
typedef struct builtins
{
	char *commande;
	void (*func)(char **cmd);
} builtins_t;

extern char **environ;

void _free_cmd(char **token);
void get_path(char **cmd);
void free_array(char **array);
char *read_line(void);
void inf_loop(void);
void execute_cmd(char **cmd);
char **split_line(char *line);
void print_env(void);
void sh_cd(char **cmd);
void sh_help(char **cmd);
void sh_exit(char **cmd);
#endif

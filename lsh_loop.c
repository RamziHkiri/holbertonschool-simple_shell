#include<stdio.h>
#include<stdlib.h>
#include"simple_shell.h"
/**
 * inf_loop - loop inlimited
 */
void inf_loop(void)
{
	char *line;
	char **cmd;

	do {
		printf("($)> ");
		line = read_line();
		cmd = split_line(line);
		execute_cmd(cmd);

		free(line);
		free(cmd);
	} while (1);
}

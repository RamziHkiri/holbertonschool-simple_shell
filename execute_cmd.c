#include"simple_shell.h"
/**
 * execute_cmd -function that execute the commande
 * @cmd:the commande to be executed
 * Return: none
 */
void execute_cmd(char **cmd)
{
	pid_t p = 0;
	int stat = 0;

	p = fork();
	if (p == -1)
		perror("fork");
	else if (p > 1)
	{
		waitpid(p, &stat, 0);
		kill(p, SIGTERM);
	}
	else
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		perror("shell");
		exit(EXIT_FAILURE);
	}
}

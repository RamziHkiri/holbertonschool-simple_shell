#include"simple_shell.h"
/**
 * sh_cd - change dir
 * @cmd: commande
 */
void sh_cd(char **cmd)
{
	if (cmd[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(cmd[1]) != 0)
		{
			perror("lsh");
		}
	}
}
/**
 * sh_help - help
 * @cmd: commande
 */
void sh_help(char **cmd)
{
	int i;

	builtins_t tab[] = {
		{"exit", sh_exit},
		{"cd", sh_cd},
		{"help", sh_help}
	};
	(void)cmd;
	printf("Ramzi hkiri's SH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	for (i = 0; i < 3 ; i++)
	{
		printf("  %s\n", tab[i].commande);
	}
	printf("Use the man command for information on other programs.\n");
}
/**
 * sh_exit - exit terminal
 * @cmd: commande
 */
void sh_exit(char **cmd)
{
	int status;

	if (cmd[1] == NULL)
	{
		exit(0);
	}
	else
	{
		status = atoi(cmd[1]);
		exit(status);
	}
}

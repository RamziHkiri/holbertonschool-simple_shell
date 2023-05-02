#include"simple_shell.h"
/**
 * inf_loop - loop inlimited
 */
void inf_loop(void)
{
	char *line;
	char **cmd;
	int i, stats = 0;

	builtins_t tab[] = {
		{"exit", sh_exit},
		{"cd", sh_cd},
		{"help", sh_help}
	};
	do {
		line = read_line();
		cmd = split_line(line);
		if (strcmp(cmd[0], "env") == 0)
		{
			print_env();
			free_array(cmd);
			continue;
		}
		for (i = 0; i < 3 ; i++)
		{
			if (strcmp(cmd[0], tab[i].commande) == 0)
			{
				stats = 1;
				tab[i].func(cmd);
				continue;
			}
		}
		if (stats == 0)
		{
			get_path(cmd);
			execute_cmd(cmd);
		}
		stats = 0;
	} while (1);
	free(line);
	free_array(cmd);
}

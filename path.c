#include "simple_shell.h"
/**
 * split - function taht split the input in an array of string
 * @raw_cmd: the input
 * @limit: the delimenter
 * Return: array of string
 */
char **split(char *raw_cmd, char *limit)
{
	char	*ptr = NULL;
	char	**cmd = NULL;
	size_t	idx = 0;

	ptr = strtok(raw_cmd, limit);

	while (ptr)
	{
		cmd = realloc(cmd, ((idx + 1) * sizeof(char *)));
		cmd[idx] = strdup(ptr);
		ptr = strtok(NULL, limit);
		++idx;
	}
	cmd = realloc(cmd, ((idx + 1) * sizeof(char *)));
	cmd[idx] = NULL;
	return (cmd);
}
/**
 * get_path - function that read the path
 * @cmd: the commande
 */
void get_path(char **cmd)
{
	int i;
	char	*path = strdup(getenv("PATH"));
	char	*bin = NULL;
	char	**path_split = NULL;

	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{

		path_split = split(path, ":");
		free(path);
		path = NULL;
		for (i = 0; path_split[i]; i++)
		{

			bin = calloc(sizeof(char),
					(strlen(path_split[i]) + 1 + strlen(cmd[0]) + 1));
			if (bin == NULL)
				break;
			strcat(bin, path_split[i]);
			strcat(bin, "/");
			strcat(bin, cmd[0]);

			if (access(bin, F_OK) == 0)
				break;
		free(bin);
			bin = NULL;
		}
		free_array(path_split);

		free(cmd[0]);
		cmd[0] = bin;
	} else
	{
		free(path);
		path = NULL;	}
}

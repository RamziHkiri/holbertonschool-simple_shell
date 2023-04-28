#include<string.h>
#include"simple_shell.h"
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
 */
void get_path(char **cmd)
{
	int i;
	char *path = getenv("PATH");
	char *full_path;
	char **s_path;
	
	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{
		s_path = split(path, ":");
		free(path);
		for (i = 0; s_path[i]; i++)
		{
			full_path = calloc(sizeof(char),(strlen(s_path[i]) + strlen(cmd[0]) + 2));
			if (full_path == NULL)
				break;
			strcat(full_path, s_path[i]);
			strcat(full_path, "/");
			strcat(full_path, cmd[0]);
			if (access(full_path, F_OK) == 0)
				break;
			free(full_path);
			full_path = NULL;
		}
		cmd[0] = full_path;
	} 
	else
	{
		free(path);
		path = NULL;	}
}

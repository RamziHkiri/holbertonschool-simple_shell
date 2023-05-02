#include "simple_shell.h"
/**
 * read_line - function that read the commande line
 * Return: char*
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buflen = 0;
	ssize_t len;
	int err = 0;

	len = getline(&line, &buflen, stdin);
	if (len < 0)
	{
		if (err)
		{
			perror("shell");
		}
		free(line);
		exit(0);
	}
	return (line);
}

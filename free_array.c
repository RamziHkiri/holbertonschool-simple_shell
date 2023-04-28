#include"simple_shell.h"
/**
 * free_array -free array space
 * @array: freed array
 */
void free_array(char **array)
{
	int i;


	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

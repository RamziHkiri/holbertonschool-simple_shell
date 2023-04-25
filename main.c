#include"simple_shell.h"
/**
 * main - main function
 * @argc:number of arguments
 * @argv: array of arguments
 * Return: none
 */
int main(int argc, char **argv)
{
	/* Load config files, if any.*/
	(void)argc;
	(void)argv;
	/*Run command loop.*/
	inf_loop();


	/*Perform any shutdown/cleanup.*/

	return (EXIT_SUCCESS);
}

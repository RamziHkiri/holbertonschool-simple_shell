#include"simple_shell.h"
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

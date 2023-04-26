#include "main.h"

void execmd(char **argv)
{
	char *cmd = NULL, *act_cmd = NULL;
	if (argv)
	{
		cmd = argv[0];
		act_cmd = get_location(cmd);

		if(execve(act_cmd, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}

}

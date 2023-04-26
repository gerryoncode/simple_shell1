#include "main.h"

char *get_location(char *command)
{
	char *path, *path_cp, *path_tok, *file_pt;
	int cmd_len, dir_len;
	struct	stat buffer;

	cmd_len = strlen(command);
	path = getenv("PATH");
	if (path)
	{
		path_cp = strdup(path);
		cmd_len = strlen(command);
		path_tok = strtok(path_cp, ":");

		while (path_tok != NULL)
		{
			dir_len = strlen(path_tok);
			file_pt = malloc(cmd_len + dir_len + 2);
			strcpy(file_pt, path_tok);
			strcat(file_pt, "/");
			strcat(file_pt, command);
			strcat(file_pt, "\0");
			if (stat(file_pt, &buffer) == 0)
			{
				free(path_cp);
				return (file_pt);
			}
			else 
			{
				free(file_pt);
				path_tok = strtok(NULL, ":");
			}
		}
		free(path_cp);

		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}

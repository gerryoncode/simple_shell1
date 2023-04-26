#include "main.h"
/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char **argv)
{
	char *start = "$ ";
	char *line = NULL, *line_cp = NULL;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t read_chars;
	int i_tokens = 0;
	char *token;
	int j;

	(void)argc;

	while (1)
	{
		printf("%s", start);
		read_chars = getline(&line, &n, stdin);
		if (read_chars == -1)
		{
			printf("Exiting..\n");
			return (-1);
		}
		line_cp = malloc(sizeof(char) * read_chars);
		if (line_cp == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(line_cp, line);
		token = strtok(line, delim);
		while (token != NULL)
		{
			i_tokens++;
			token = strtok(NULL, delim);
		}
		i_tokens++;
		argv = malloc(sizeof(char *) * i_tokens);
		token = strtok(line_cp, delim);
		for (j = 0; token != NULL; j++)
		{
			argv[j] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[j], token);
			token = strtok(NULL, delim);
		}
		argv[j] = NULL;
		execmd(argv);
	}
	free(line);
	return (0);
}

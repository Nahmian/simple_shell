#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - PID
 * @argc: not used
 * @argv: lines
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	char **cmd = NULL;
	(void)argc;

	while (1)
	{
		buffer = _read_buffer();
		if (buffer == NULL)
		{
			if (isatty(0) == 1)
				perror(argv[0]);
			return (0);
		}
		cmd = tokizer(buffer);

		if (cmd == NULL)
			continue;
		exec(cmd, argv);
	}
	return (0);
}

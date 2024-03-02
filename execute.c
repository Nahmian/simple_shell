#include "main.h"
/**
 * free_2d_arr - function tat free array
 * @arr: the array wich will be freed
 */
void free_2d_arr(char **arr)
{
	int i;

	if (arr == NULL)
		return;
	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}
/**
 * exec - function that makes the same of execve
 * @command: array that has the commandes
 * @av: the array of argv in main
 * Return: status value of child pid
 */
int exec(char *command[], char **av)
{
	int stat;
	pid_t child;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
			free_2d_arr(command);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		free_2d_arr(command);
	}
	return (WEXITSTATUS(stat));
}

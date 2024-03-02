#include "main.h"
/**
 * tokizer - function that splits the str to an array
 * @string: the str wich splited
 * Return: return the array if succed
 */
char **tokizer(char *string)
{
	char *buffer = NULL, **array = NULL;
	int i = 0;

	if (string == NULL)
		return (NULL);
	buffer = strtok(string, "\n\t");
	if (buffer == NULL)
	{
		free(string), string = NULL;
		return (NULL);
	}
	while (buffer)
	{
		array = realloc(array, (i + 2) * sizeof(char *));
		if (array == NULL)/*check realloc*/
		{
			_printf("ERROR realloc()");
			free(buffer), buffer = NULL;
			free(string), string = NULL;
			if (i > 0)
				free_2d_arr(array);
			exit(EXIT_FAILURE);
		}
		array[i] = _strdup(buffer);
		if (_strcmp("exit", array[i]) == 0)
			exit(EXIT_FAILURE);
		buffer = strtok(NULL, " \n\t");
		i++;
	}
	array[i] = NULL;
	free(buffer), buffer = NULL;
	free(string), string = NULL;
	return (array);
}
/**
 * _read_buffer - function that take line from commande line
 *
 * Return: if succ return the line taken
 *
 */
char *_read_buffer(void)
{
	char *line = NULL;
	size_t size_line = 0;
	int ret = 0;

	if (isatty(0) == 1)/*if we are in terminal (1)*/
		_printf("#cisfun$");
	ret = getline(&line, &size_line, stdin);
	if (ret == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}

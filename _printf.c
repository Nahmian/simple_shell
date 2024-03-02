#include "main.h"
/**
 * _printf - function that print str
 * @str: string that printed
 * Return: tne number of chars printed
 */
int _printf(char *str)
{
	int ret = 0;

	if (str == NULL)
		str = "(null)";
	write(1, str, _strlen(str));
	return (ret);
}

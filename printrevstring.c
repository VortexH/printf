#include "holberton.h"

/**
 * _printrevstring - using the specifier, r, prints the reversed string
 *
 * @valist: the pointer to the argument list
 *
 * Description: use the va_arg macro to return a string and reverse the string
 *
 * Return: type int - return the number of characters printed
*/

int _printrevstring(va_list valist)
{
	char *string = va_arg(valist, char *);
	int len, i;

	if (string)
	{
		len = _strlen(string);
		i = 0;
		while (i < len / 2)
		{
			tmp = string[i];
			string[i] = string[len - 1 - i];
			string[len - 1 - i] = tmp;

			i++;

		}

		i = 0;
		while (string[i])
		{
			write(1, string[i], 1);
			i++;
		}

	}

	return (i);

}

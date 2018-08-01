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
	int len, i = 0;

	if (string)
	{
		len = _strlen(string) - 1;
		while (len >= 0)
		{
			_putchar(string[len]);
			len--;
			i++;
		}
	}

	return (i);

}

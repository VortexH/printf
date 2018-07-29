#include <stdlib.h>
#include "holberton.h"

/**
 * _strlen - calculates the string length of the format string
 *
 * @s: string argument, type - char *
 *
 * Description: calculates the length of the string excluding the null byte
 *
 * Return: Length of the string - int
*/

int _strlen(const char *s)
{
	int i = 0;

	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			i++;

		}

	}


	return (i);
}

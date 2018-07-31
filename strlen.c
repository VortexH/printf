#include "holberton.h"

/**
 * _strlen - calculate the string length, excluding the null byte
 *
 * @s: string argument
 *
 * Description: loop through the string, and find the number of characters
 * in the string
 *
 * Return: type int - length of the string
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);

}

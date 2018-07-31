#include "holberton.h"

/**
 * getfunc - function takes in a specifier in the form of a char
 * and returns the associated function to print an argument of that type
 *
 * @s: type char, the specifier passed in
 *
 * Description: an array of structs is initialized with all possible specifiers
 * and the associated functions that will print arguments of that type
 *
 * Return: integer value, the number of characters printed when the called
 * function (via a function pointer) prints characters
*/

int (*getfunc(char s))(va_list)
{
	int i = 0;

	specdo arr[] = { {'c', _printchar},
			{'s', _printstring},
			{'d', _putint},
			{'i', _putint},
			{' ', NULL},
			{'\0', NULL}};

	while (arr[i].s != '\0')
	{
		if (s == arr[i].s)
			return (arr[i].prntr);
		i++;
	}

	return (0);


}


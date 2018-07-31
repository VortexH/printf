#include "holberton.h"
/**
 * _printchar - prints a single byte of type char
 *
 * @arglist: pointer to argument list
 *
 * Description: given a va_list passed in, get that particular type from
 * va_arg, and store it in a temporary variable of type char.
 * Using the address of this location, write to the standard output,
 * the character stored at that address.
 *
 * Return: The number of characters written to stdout.
*/
int _printchar(va_list arglist)
{
	char ch = va_arg(arglist, int);

	write(1, &ch, 1);

	return (1);
}


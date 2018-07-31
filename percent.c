#include "holberton.h"
/**
 * _percent - puts a percent
 * @valist: arglist to source our int to print
 *
 * Return: Number of characters printed (excluding the null byte)
*/

int _percent(__attribute__((unused)) va_list valist)
{
	_putchar('%');
	return (1);
}

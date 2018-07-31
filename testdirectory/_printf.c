#include "holberton.h"

/**
 * _printf - a format string contains specifiers, which are placeholders
 * for stuff that needs to be printed, which are the characters that the string
 * will be parsed for so that arguments given to _printf will be placed in the
 * appropriate spots in the string.
 *
 * @format: character string containing specifiers, more on that below.
 *
 * Description: Format of description: specifier:prints.
 * %c:character, %s:string
 *
 *
 * Return: Number of characters printed (excluding the null byte)
*/

int _printf(const char *format, ...)
{
	int i = 0, retval = 0;
	va_list arglist;

	if (!format)
		return (-1);

	va_start(arglist, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			retval += getfunc(format[i])(arglist);
		}
		else
		{
			write(1, &format[i], 1);
			retval++;
		}
		i++;

	}

	return (retval);


}

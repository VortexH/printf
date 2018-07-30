#include "holberton.h"
#include <stdarg.h>

/**
 * _printf - print a string
 * @format: character string
 *
 * Description: using the format string, checks if input string is
 * valid, and prints that particular argument in the list. Writes output
 * to stdout
 *
 * Return: Number of characters printed (excluding the null byte)
*/

int _printf(const char *format, ...)
{
	/* format string index */
	int i = 0;
	/* arg string index */
	int stp = 0;
	/* putchar'd count */
	int retval = 0;
	va_list arglist;
	char *string;

	va_start(arglist, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(arglist, int));
					i++;
					retval++;
					break;

				case 's':
					stp = 0;
					string = va_arg(arglist, char *);
					while (string[stp] != '\0')
					{
						_putchar(string[stp]);
						stp++;
						retval++;
					}
					i++;
					break;

				default:
					break;

			}


		}

		else
		{
			_putchar(format[i]);
			i++;
			retval++;
		}
	}

		return (retval);

}


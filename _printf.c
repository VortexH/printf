#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
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
	int i = 0;
	int k = 0;
	int numDirects = 0;
	int d = 0;
	int stp = 0;
	int retval = 0;
	va_list arglist;
	char *string;

	va_start(arglist, format);

	k = 0;
	while (format[k] != '\0')
	{
		if (format[k] == '%' && (format[k + 1] == 'c' || format[k + 1] == 's'))
			numDirects++;
		k++;
	}

	while (format[i])
	{
		if (format[i] == '%')
		{
			stp = 0;
			i++;

			switch (format[i])
			{
				case 'c':
					d++;
					if (d < numDirects)
					{
						_putchar(va_arg(arglist, int));
						i++;
						retval++;
						break;
					}
					else
					{
						exit(0);
					}

				case 's':
					d++;
					if (d < numDirects)
					{

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
					}
					else
					{
						exit(0);
					}

				case '%':
					while (format[i] == '%')
					{
						stp++;
						i++;
					}
					stp = stp / 2;
					while (stp--)
					{
						_putchar('%');
						retval++;
					}
					_putchar('%');
					retval++;
					break;

				default:
					if (format[i - 1] == '%')
					{
						_putchar('%');
						retval++;
					}
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

		va_end(arglist);
		return (retval);
}





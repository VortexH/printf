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

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			stp = 0;

			switch (format[i + 1])
			{
				case 'd':
				case 'i':
					d++;
					/*
					*if (d > numDirects)
					*	return (-1);
					*/
					retval = _putint(va_arg(arglist, int));
					i++;
					break;

				case 'c':
					d++;
					/*
					*if (d > numDirects)
					*	return (-1);
					*/
					_putchar(va_arg(arglist, int));
					i++;
					retval++;
					break;

				case 's':
					d++;
					/*
					*if (d > numDirects)
					*	return (-1);
					*/
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

				case '%':
					i++;
					_putchar(format[i]);
					retval++;
					break;

				case ' ':
					return (-1);
				case '\0':
					return (-1);
				default:
					return (-1);

			}


		}

		else
		{
			_putchar(format[i]);
			retval++;
		}
	}

		va_end(arglist);
		return (retval);
}



/**
 * _putint - print a int
 * @num: int to print
 *
 * Return: Number of characters printed (excluding the null byte)
*/

int _putint(int num)
{
	int i, tmp, retval;

	retval = 0;

	tmp = num;
	i = 1;
	while (tmp / 10)
	{
		tmp /= 10;
		i *= 10;
	}
	while (i)
	{
		tmp = num / i;
		if (tmp < 0)
		{
			_putchar('-');
			retval++;
			tmp *= -1;
			num = num % i * -1;
		}
		else
		{
			num = num % i;
		}

		_putchar('0' + tmp);
		retval++;
		i /= 10;
	}
	return (retval);
}

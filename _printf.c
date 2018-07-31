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
	int i, stp, retval = 0;
	va_list arglist;
	char *string;

	if (!format)
		return (-1);

	va_start(arglist, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			stp = 0;

			switch (format[i + 1])
			{
				case 'd':
				case 'i':
					retval = _putint(va_arg(arglist, int));
					i++;
					break;

				case 'c':
					stp = va_arg(arglist, int);
					if (stp)
					{
						_putchar(stp);
						i++;
						retval++;
					}
					break;

				case 's':
					stp = 0;
					string = va_arg(arglist, char *);
					if (!string)
					{
						_putchar('(');
						_putchar('n');
						_putchar('u');
						_putchar('l');
						_putchar('l');
						_putchar(')');
					}
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

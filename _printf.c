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
	int stp = 0;
	int retval = 0;
	va_list arglist;
	char *string;
	int nPerc;

	va_start(arglist, format);

	if (format != NULL)
	{
		while (format [i] != '\0')
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
						string = va_arg(arglist, char *);
						stp = 0;
						while (string[stp] != '\0')
						{
							_putchar(string[stp]);
							retval++;
							stp++;
						}
						i++;
						break;

					case '%':
						stp = 0;
						nPerc = 0;
						while (format[stp] != '%')
						{
							nPerc++;
							stp++;
							i++;
						}
						nPerc++;
						if (nPerc % 2 == 0)
						{
							nPerc /= 2;
							while(nPerc <= 0)
							{
								_putchar(format[stp]);
								retval++;
								nPerc--;
								stp--;
							}
							i += nPerc - 1;
						}
						else
						{
							exit(100);
						}

					case ' ':
						exit(100);
						break;

					case '\0':
						exit(100);
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
	return (-1);
}




							
							
							
			
	


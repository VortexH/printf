#include "holberton.h"
/**
 * _printrot13 - prints all the bytes of a string excluding the null byte
 *
 * @arglist: pointer to the argument list, va_arg uses this to get a string
 *
 * Description: given that va_list is passed in, get a char * from va_arg
 * and set the address of the resultant string to variable string.
 * In order to print all the characters of the string, first calculate
 * the length of the string, and use the address where the string is stored
 * print that many bytes from that location.
 *
 * Return: the number of bytes printed to stdout
*/

int _printrot13(va_list arglist)
{
	char *string = va_arg(arglist, char *);
	int i, j;
	char *abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	i = 0;
	if (!(string))
		string = "(null)";
	while (string[i])
	{
		for (j = 0; abc[j] != '\0'; j++)
		{
			if (string[i] == abc[j])
			{
				_putchar(rot[j]);
				i++;
				break;
			}
		}
		_putchar(string[i]);
		i++;
	}
	return (i);
}

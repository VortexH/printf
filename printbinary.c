#include "holberton.h"
#include <stdlib.h>

/**
 * _printbinary - converts an unsigned int to binary given the conversion
 * specifier, b.
 *
 * @valist: given that valist is passed in, return an unsigned int from the
 * the argument list, and convert that value to binary
 *
 * Description: unsigned ints are converted to binary in the function
 *
 * Return: type int - number of characters printed
*/

int _printbinary(va_list valist)
{
	unsigned int num = va_arg(valist, unsigned int);
	unsigned int rem = 0;
	int retval = 0;
	int len = 0;
	int i = 0;
	/* allocate well more than 32 bits worth of char bytes */
	char *numarray = malloc(sizeof(char) * 60);

	if (!numarray)
		return (-1);

	if (num == 0 || num == 1)
	{
		_putchar(num + '0');
		retval++;
	}
	else
	{
		while (num != 0)
		{
			rem = num % 2;
			num /= 2;
			numarray[i] = rem + '0';
			i++;
		}

		numarray[i] = '\0';
		len = _strlen(numarray);
		len -= 1;
		/* print each byte to stdout in reverse */
		while (len >= 0)
		{
			_putchar(numarray[len]);
			retval++;
			len--;
		}

	}

	free(numarray);
	return (retval);

}

#include "holberton.h"
/**
 * _putint - print a int
 * @num: int to print
 *
 * Return: Number of characters printed (excluding the null byte)
*/

int _putint(va_list valist)
{
	int i, tmp, num, retval;

	num = va_arg(valist, int);
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

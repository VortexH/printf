#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>


int _printf(const char *format, ...);
int _printchar(va_list valist);
int _printstring(va_list valist);
int (*getfunc(char s))(va_list);
int _putint(va_list valist);
int _putchar(char c);
int _percent(va_list valist);
int _negativeone(va_list valist);
/**
 * struct specs - contains the specifier and the associated function being
 * called.
 * @s: the specifier, type char
 * @prntr: pointer to function that takes in a va_list
 * and returns the number of characters printed
 *
*/
struct specs
{
	char s;
	int (*prntr)(va_list);
};

/**
 * specdo - typedef for struct spec
*/
typedef struct specs specdo;

#endif

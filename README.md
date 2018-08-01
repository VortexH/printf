# printf - a rudimentary implementation

# Description
printf is a complex function that parses a format string for certain specifiers and essentially pastes content\n
from arguments that match the specifier. Each specifier corresponds to the a specific argument that matches that type. Print regular characters as is, but print an argument when a directive (%) appears in the format string.

## Function prototype
- int \_printf(const char \*format, ...)
- \_printf is a variadic function which takes in a variable number of arguments requiring macros such as (va\_start, va\_end,va\_arg, va\_list) to print such arguments. 

# Specifiers included
- %c
specifier prints a character to stdout using the write function

- %s
prints a character string by counting length of string and writes 'length' many bytes to stdout

- %d, %i
prints an integer one digit at a time

- %b
takes an unsigned int and converts it to its binary representation
Potential bugs: passing in a string argument prints some binary representation that we were not able to fully understand.

- %r
prints a string in reverse

- %R
using the rot13 cipher, converts each character to the appropriate character from the rot13 string

# WiP Specifiers 
- u, o, x, X
- S
- p
- l
- h

# WiP Flag characters 
- +
- space
- #
- 0
- -

# Included functions
Each function called, returns the number of characters printed to stdout.

## int (\*getfunc(char s))(va\_list)
Function pointer takes in a specifier in the form of a char and returns the associated function to print an argument of that type. Traverses array of structs containing 2 members: the character specifier and the function to print that type. Each function called returns the numbers printed to stdout.

## int \_negativeone(\_\_attribute\_\_((unused)) va\_list valist)
Function that returns a failure when a specifier is not located within the array of structs. Since all second members of a struct point to a function that takes in a va\_list, thi s attribute is unused, so it needs to return a fail state of -1.

## int \_percent(\_\_attribute\_\_((unused)) va\_list valist)
Prints a percent if that character after the % is a %.

## int \_printbinary(va\_list valist)
It's easy to think about the individual characters of the resultant binary representation as a bunch of characters consisting of 0s and 1s, so we've allocated memory of 60 bytes for such chars. The size of an unsigned int varies from machine to machine, our development environment consists of Ubuntu 14.04 64 bit, so an unsigned int is 4 bytes. Meaning that there are 32 possible bits, and we allocate at least double that just to be on the safe side.

With this memory allocated, push characters into positions in memory in the order that they appear in the calculations and append a null byte at the end.

Use this null byte to our advantage, by calculating length and printing the string in reverse.
# Developers
- Marius Farioletti
- Hemant Heer

# Contact information
- Hemant Heer @hemant\_heer
- Marius Farioletti @ThrownBlown



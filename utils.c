#include "main.h"

/**
 * convert_size_number - A function that casts a number to
 * the specified size
 * @size: Indicator fo the type to be casted
 * @num: Interger to be casted
 *
 * Return: Value of casted number.
*/

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * is_digit - It verifies whether or not a character is a digit
 * @c: The character to be evaluated
 *
 * Return: 1 when (c) is a digit, 0 when not.
*/

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * is_printable - A function that evaluates if a character is printable
 * or not
 * @c: The character to be evaluated.
 *
 * Return: 1 when (c) is printable, 0 when not
*/

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

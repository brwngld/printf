#include "main.h"

/**
 * print_int - Prints out Integers
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @types: Arguments lists
 * @buffer: The buffer array to handle print
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints out string
 * @width: get width
 * @precision: Precision specification
 * @types: Arguments lists
 * @buffer: the buffer arry to handle print
 * @flags: Calculates active flags
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_char - Prints out Characters
 * @size: The size specifier
 * @width: The width
 * @buffer: The buffer array to handle print
 * @precision: The precision specificaiton
 * @flags: Calculates active flags
 * @types: The list of arguments
 *
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_write_char(a, buffer, flags, width, precision, size));
}

/**
 * print_percent - Prints out a percent sign
 * @types: The list of arguments
 * @precision: The precision specification
 * @width: The Widith
 * @flags: Calculates active flags
 * @buffer: The buffer array to handle print
 * @size: The size specifier
 *
 * Return: Number of chars printed
*/

int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

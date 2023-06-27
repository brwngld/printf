#include "main.h"

/**
* get_size - calculate the size to cast the argument
* @i:The list of arguments taken to be printed
* @format:The formatted string of characters
*
* return:the precision.
*/

int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == '1')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
return (size);
}

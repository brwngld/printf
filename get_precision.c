"include "main.h"

/**
* get_precision : it calculates the precision for the printing of the characters
* @format: It formats the string in which we are printing the arguments
* @list: It helps us to list the arguments
* @i: List of arguments to printed
*
* return: precision of the buffer.
*/
int get_precision(const char *format, int *i, va_list list)
 {
   int curr_i = *i + 1 ;
   int precision = -1 ;
   if (format[curr_i] != '.')
       return (precision) ;
   for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
   {
     if (is_digit(format[curr_i]))
       {
	   precision *= 10;
	   precision += format[curr_i] - '0' ;
       }
     else if (format[curr_i] == '*')
     {
	 curr_i++;
	 precision = va_arg(list, int);
	  break;
     }
     else
	  break ;
   }
  *i = curr_i +1 ;
 return(precision);
 } 

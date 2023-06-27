#include "main.h"
/************ Write our handle as indicated below ************************/
/* handle_WRITER_CHAR - Prints a string
* @c: Character types defined
* @buffer: Calculates active flags.
* @width: helps in getting width
* @precision: precision of specifier
* @size: Size of specifier
*
* Return: The number of characters printed
*/
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{ int i = 0;
  char padd = ' ';
  UNUSED(precision);
  UNUSED(size);

  if (flags & F_ZERO)
	  padd  = '0';
  buffer[i++] = c;
  buffer[i] = '\0';
  if (width > 1)
  {
    buffer[BUFF_SIZE - 1] = '\0';
    for (i =0; i < width - 1; i++)
	  buffer[BUFF_SIZE - i - 2] = padd ;
    if (flags & F_MINUS)
	 return (write(1,&buffer[0], 1) + write(1, &buffer[BUFF_SIZE - i -1], width - 1));
    else
	 return (write(1, &buffer[BUFF_SIZE -i - 1], width - 1) + write(1, &buffer[0], 1));
   }
  return (write(1, &buffer[0], 1));
}
/*************************** Lets write the number *********************************************/
/**
*write_number - Prints a string
* @is_negative: List of arguments
* @ind: of type characters
* @buffer: Buffer array that will  handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: precision of the  specifier
* @size: Size of the  specifier
*
* Return: Number of characters  printed.
*/
int write_number(int is_negative,int ind, char buff[], int flags, int width, int precision, int size)
{
  int length = BUFF_SIZE - ind - 1 ;
  char padd = ' ', extra_ch = 0;
  UNUSED(size);

  if ((flags & F_ZERO) && !(flags & F_MINUS))
	  padd = '0';
  if (is_negative)
	  extra_ch = '-';
  else if (flags & F_PLUS)
	  extra_ch = '+';
  else if (flags & F_SPACE)
	  extra_ch = ' ';
  return (write_num(ind, buffer, flags, width, precision, length, padd, extra_ch));
/** @prec: Precisio  of  pecifier
* @length: Number of length
* @padd: Pading of the  character
* @extra_c: Extra character entered
* write_num - Write a number using a bufffer
* @ind: Index at which the number starts on the buffer
* @buffer: Buffer
* @flags: Flags
* @width: width
*
* Return : number of the printed characters.
*/
int write_num(int ind, char buffer[],int flags, int width, int prec, int length, char padd, char extra_c)
{ 
  int i, padd_start = 1;
  
  if (prec == 0 && ind == BUFF_SIZE - 2 && buffer(ind == '0' && width == 0)
      return (0);/* printf(".0d", 0) no char is printed */
  if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' '; /* width is displayed with padding '
' */
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
 {
for (i = 1; i < width - length + 1; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra characters to the  left of the buffer*/
 {
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], lenght) + write(1, &buffer[1], i-1));
 }
else if (!(flags & F_MINUS) && padd == '0') /* Extra character to the left of the buffer*/
 {
   if (extra_c)
      buffer[--padd_start] = extra_c ;
   return (write(1,& buffer[padd_start], i - padd_start) + write(1, &buffer[ind], length - ( 1 - padd_start)));
 }
 }
  if  (extra_c)
	  buffer[--ind] = extra_c;
  return ( write(1,&buffer[ind], length));
}
/**
* @buffer: Array of characters
* @flags: Flags of the  specifiers
* @width: Width  of the specifier
* write_unsgnd - Writes an unsigned number
* @is_negative: Number indicating if the num is negative or not
* @ind: Index at which the number starts in the buffer
* @precision: Precision of the  specifier
* @size: Size of the  specifier
*
* Return: Number of written characters.
*/
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
  {
    int length = BUFF_SIZE - ind - 1, i = 0;
    char padd = ' ';
    UNUSED(is_negative);
    UNUSED(size);
    if (precision == 0 && ind == BUFF_SIZE -2 && buffer[ind] == '0')
	 return (0); /* printf(".0d", 0) no character is printed because the precision is 0and the buffer is 0*/
    if (precision > 0 && precision < length)
	    padd = ' ';
    while (precision > length)
	 {
		 buffer[--ind] = '0';
		 length++;
	 }
    if ((flags & F_ZERO) && !(flags & F_MINUS))
	    padd = '0';
    if ( width > length)
       {
	  for(i = 0; i < width-length; i++)
		  buffer[i] = padd;
	  buffer[i] = '\0';
	  if (flags & F_MINUS) /* Asign an extra character to the left of the buffer [buffer>padd] */
	  {  
		  return (write(1,&buffer[ind], length) + write(1, &buffer[0], i)):
	  }
	  else /* asigning an extra charater to the left of the padding [padd>buffer] */
           {
		   return (write(1,&buffer[0], 1) + write(1,&buffer[ind],lenght));
	   }
       }
     return (write(1, &buffer[ind], length));
  }
/**
* @width: width of the specifier
* @flags: Flags of the  specifier
* write_pointer - Write a memory address of the buffer
* @buffer: Arrays of characters
* @ind: Index at which the number starts in the buffer
* @length: Length of number of the characters
* @padd: Char representing the padding
* @extra_c: Char representing extra char
* @padd_start: Index at which padding should start
*
* Return: Number of written chars.
*/
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start)
{
int i;
if (width > length)
{
for (i = 3; i < width - length + 3; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left
of buffer */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1,
&buffer[3], i - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')/* extra char to
left of buffer */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], i - 3) + write(1,
&buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* extra char to
left of padd */
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) -
2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

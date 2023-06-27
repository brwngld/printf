#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size);

/**
 * typedef struch fm fmt_t - Struct op
 * @fm_t: The function associated.
 * @fmt: The format
*/

typedef struct fm fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list,
		char buffer[], int flags, int width, int precision, int size);

int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list lsit);
int get_precision(const char *format, int *i, va_list list);
int get_flags(const char *format, int *i);

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

int is_printable(char);
int is_digit(char);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int write_num(int ind, char bff[], int flags, int width,
		int precision, int length, char padd, char extra_c);
int handle_write_char(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags,
		int width, int precision, int size);

#define S_SHORT 1
#define S_LONG 2

long int convert_size_number(long int num, int size);

/**
 * struct fmt - Function
 * @fn: The associated function
 * @fmt: Format
*/

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

#endif

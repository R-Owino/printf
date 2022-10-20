#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>

/**
 * File: main.h
 * Desc: Header file with all function prototypes for this project
 */

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list ap);
int print_str(va_list ap);
int print_num(va_list ap);
int print_binary(va_list ap);
int print_octal(va_list ap);
int print_hexa_lower(va_list ap);
int print_hexa_upper(va_list ap);
int print_unsigned(va_list ap);
int print_str_unprintable(va_list ap);
int print_str_reverse(va_list ap);
int print_add(va_list ap);
int print_rot13(va_list ap);
int print_percent(va_list ap __attribute__((unused)));
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _puts(char *str, int a);
int num_len(int prmNumber);
char *_strcpy(char *str);
int _strlen_recursion(char *s);
char *convert_rot13(char *str);
int convert_alpha_numeric(int nb, int upper);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *convert_base_pointer(unsigned long p);

/**
 * struct flags_printf - struct conversion to function
 * @c: flag string
 * @f: pointer to func
 */

typedef struct flags_printf
{
	char *c;
	int (*f)(va_list);
} specifier;


#endif

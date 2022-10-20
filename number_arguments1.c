#include "main.h"

/**
 * print_unsigned - handle unsigned int
 * @ap: arg list
 * Return: value number of printed chars
 */

int print_unsigned(va_list ap)
{
        unsigned int argument = va_arg(ap, unsigned int);

        return (print_unsigned_number(argument));
}

/**
 * print_add - gets the address
 * @ap: argument
 * Return: number of printed char
 */
int print_add(va_list ap)
{
        char *str;
        int sum = 0;
        unsigned long p = (unsigned long) va_arg(ap, void*);

        if (!p)
        {
                sum += _puts("(nil)", 0);
                return (sum);
        }

        str = convert_base_pointer(p);
        if (!str)
                return (0);
        sum += _puts("0x", 0);
        sum += _puts(str, 0);
        free(str);
        return (sum);
}



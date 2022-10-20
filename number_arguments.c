#include "main.h"

/**
 * print_num - prints a number
 * @ap: argument list
 * Return: number of printed chars
 */

int print_num(va_list ap)
{
        return (print_number(va_arg(ap, int)));
}

/**
 * print_binary - print number in binary
 * @ap: argument list
 * Return: number of printed chars
 */

int print_binary(va_list ap)
{
        char *str;
        int sum = 0;
        unsigned int argument = va_arg(ap, unsigned int);

        if (!argument)
        {
                sum += _puts("0", 0);
                return (sum);
        }
        str = convert_base(argument, 2, 0);
        if (!str)
                return (0);
        sum = _puts(str, 0);
        free(str);
        return (sum);
}

/**
 * print_octal - print number in octal
 * @ap: argument list
 * Return: number of printed chars
 */

int print_octal(va_list ap)
{
        char *str;
        int sum;

        str = convert_base(va_arg(ap, unsigned int), 8, 0);
        sum = _puts(str, 0);
        free(str);
        return (sum);
}

/**
 * print_hexa_lower - print hexadecimal lower
 * @ap: argument list
 * Return: number of printed chars
 */

int print_hexa_lower(va_list ap)
{
        char *str;
        int sum;

        str = convert_base(va_arg(ap, unsigned int), 16, 0);
        sum = _puts(str, 0);
        free(str);
        return (sum);
}

/**
 * print_hexa_upper - print hexadecimal upper
 * @ap: argument list
 * Return: number of printed chars
 */

int print_hexa_upper(va_list ap)
{
        char *str;
        int sum;
        
        str = convert_base(va_arg(ap, unsigned int), 16, 1);
        sum = _puts(str, 0);
        free(str);
        return (sum);
}




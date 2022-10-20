#include "main.h"

/**
 * print_str - print string
 * @ap: arg list
 * Return: number of printed char
 */

int print_str(va_list ap)
{
        char *argument = va_arg(ap, char *);
        int sum = 0;

        if (!argument)
        {
                sum += _puts("(null)", 0);
                return (sum);
        }

        return (_puts(argument, 0));
}

/**
 * print_str_unprintable - unprint some characters
 * @ap: arg list
 * Return: number of printed char
 */

int print_str_unprintable(va_list ap)
{
        char *argument = va_arg(ap, char *);
        int sum = 0;

        if (!argument)
        {
                sum += _puts("(null)", 0);
                return (sum);
        }

        return (_puts(argument, 1));
}

/**
 * print_rot13 - prints the rot13'ed string
 * @ap: arg list
 * Return: number of printed char
 */

int print_rot13(va_list ap)
{
        int sum = 0;
        char *str, *argument = va_arg(ap, char*);

        if (!argument)
        {
                sum += _puts("%R", 0);
                return (sum);
        }

        str = convert_rot13(argument);
        if (!str)
                return (0);
        sum = _puts(str, 0);
        free(str);
        return (sum);
}

/**
 * print_str_reverse - reverses a string
 * @ap: arg list
 * Return: number printed char
 */
int print_str_reverse(va_list ap)
{
        char *argument = va_arg(ap, char *), *str;
        int size, left, limit, right, sum = 0;

        if (!argument)
        {
                sum += _puts("%r", 0);
                return (sum);
        }

        size = _strlen_recursion(argument);
        right = size - 1;
        limit = (size % 2 == 0) ? (size + 1) / 2 : (size / 2);

        str = malloc(sizeof(char) * size + 1);

        if (str == NULL)
        {
                return (0);
        }

        if (size % 2 != 0)
        {
                str[limit] = argument[limit];
        }

        for (left = 0; left < limit; left++)
        {
                str[left] = argument[right];
                str[right] = argument[left];
                right--;
        }

        str[size] = '\0';
        
        sum = _puts(str, 0);
        free(str);

        return (sum);
}



#include "main.h"

/**
 * _puts - write all char from string to stdout
 * @str: string to print
 * @a: enable ascii restriction
 * Return: number of printed char
 */

int _puts(char *str, int a)
{
        char *s;
        int i = 0, sum = 0;

        while (str[i])
        {
                if (((str[i] >= 0 && str[i] < 32) || str[i] >= 127) && a)
                {
                        s = convert_base(str[i], 16, 1);
                        sum += write(1, "\\x", 2);
                        if (str[i] >= 0 && str[i] < 16)
                                sum += _putchar('0');
                        sum += _puts(s, 0);
                        free(s);
                        i++;
                }
                else
                {
                        sum += _putchar(str[i]);
                        i++;
                }
        }
        return (sum);
}

/**
 * _strlen_recursion - return the length of a string
 *
 * @s: char pointer
 *
 * Return: the length of a string
 */
int _strlen_recursion(char *s)
{
        if (*s != '\0')
        {
                return (_strlen_recursion(s + 1) + 1);
        }
        else
        {
                return (0);
        }
}

/**
 * _strcpy - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *
 * @str: char pointer to copy
 *
 * Return: a new char pointer
 */
char *_strcpy(char *str)
{
        char *s;
        int i;

        if (str == NULL)
        {
                return (NULL);
        }

        s = malloc(sizeof(char) * (_strlen_recursion(str) + 1));

        if (s == NULL)
        {
                return (NULL);
        }

        for (i = 0; i < _strlen_recursion(str) + 1; i++)
        {
                s[i] = str[i];
        }

        return (s);
}



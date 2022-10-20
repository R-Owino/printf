#include "main.h"

/**
 * conversion - function that gets a conversion specifier
 * @c: character to check
 * Return: function result
 */
int (*conversion(const char c))(va_list)
{
	specifier fp[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_num},
		{"d", print_num},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"u", print_unsigned},
		{"S", print_str_unprintable},
		{"r", print_str_reverse},
		{"p", print_add},
		{"R", print_rot13},
		{"%", print_percent}
	};

	int i = 0;

	while (i < 14)
	{
		if (c == fp[i].c[0]) return (fp[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _printf - fuction that produces output according to format
 * @format: character string composed of 0 or more directives
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0, i = 0;
	int (*func)();
	
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[1 + i] != '\0')
				func = conversion(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				sum++;
				i++;
			}
			else
			{
				sum += func(ap);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar (format[i]);
			sum++;
			i++;
		}
        }
	va_end(ap);
	return (sum);
}

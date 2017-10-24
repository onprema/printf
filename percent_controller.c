#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * percent_controller - controls the flow of _printf parser when the input
 * contains at least one '%'
 * @format: input string into _printf
 * @args: optional _printf arguments
 * @i: current index for format
 *
 * Return: void
 */

int percent_controller(const char *format, va_list args, unsigned int i)
{
	unsigned int j, chars_printed = 0;
	spec arr[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_dig},
		{"i", print_int},
		{NULL, NULL}
	};

	if ((format[i + 1] == 0 || format[i + 1] == ' '))
		return (-1);

	j = 0;
	while (arr[j].special != NULL)
	{
		if (*(arr[j].special) == format[i + 1])
		{
			chars_printed += arr[j].f(args);
			i++;
		}
		j++;
	}
	if (arr[j].special == NULL)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i++;
			chars_printed++;
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			_putchar('%');
			_putchar(format[i + 1]);
			chars_printed++;
		}
	}
	return (chars_printed);
}
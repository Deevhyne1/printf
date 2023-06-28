#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: On success, returns the character written.
 *         On error, returns EOF.
 */
int _putchar(char c)
{
	return (putchar(c));
}

/**
 * _print - Prints the formatted output based on the format specifier
 * @format: The format string containing the directives
 * @args: The variable arguments list
 *
 * Return: The number of characters printed
 */
int _print(const char *format, va_list args);

/**
 * _printf - Prints formatted output to the standard output
 * @format: The format string containing the directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = _print(format, args);
	va_end(args);

	return (count);
}

/**
 * _print - Helper function for recursive printing based on format specifier
 * @format: The format string containing the directives
 * @args: The variable arguments list
 *
 * Return: The number of characters printed
 */
int _print(const char *format, va_list args)
{
	int i;
	int len;
	len = 0;
	if (*format == '\0')
		return (0);

	if (*format != '%')
	{
		_putchar(*format);
		return (1 + _print(format + 1, args));
	}
	else
	{
		format++;
		switch (*format)
		{
			case 'c':
			{
				int c = va_arg(args, int);

				_putchar(c);
				return (2 + _print(format + 1, args));
			}
			case 's':
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				while (str[len] != '\0')
					len++;
				for (i = 0; i < len; i++)
					_putchar(str[i]);
				return (len + 2 + _print(format + 1, args));
			}
			case '%':
				_putchar('%');
				return (2 + _print(format + 1, args));
			default:
				_putchar('%');
				_putchar(*format);
				return (3 + _print(format + 1, args));
		}
	}
}


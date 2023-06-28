#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else if (*(format + 1) == '%')
		{
			_putchar('%');
			count++;
			format++;
		}
		else if (*(format + 1) == 'c')
		{
			int c = va_arg(args, int);
			_putchar(c);
			count++;
			format++;
		}
		else if (*(format + 1) == 's')
		{
			char *str = va_arg(args, char *);
			if (str)
			{
				while (*str)
				{
					_putchar(*str);
					count++;
					str++;
				}
			}
			format++;
		}
		format++;
	}

	va_end(args);

	return (count);
}


int main(void)
{
	int count = _printf("Hello, %s! The character is %c. The percent sign: %%, The number is %d.", "Alice", 'A', 42);
	printf("\nNumber of characters printed: %d\n", count);

	return 0;
}

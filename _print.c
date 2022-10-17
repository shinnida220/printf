#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: format string containing the characters
 * Return: integer length of the outpput
 */
int _printf(const char *format, ...)
{
	flags_t flags = {0, 0, 0};
	va_list args;
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	register int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (_get_flag(*p, &flags))
				p++;
			pfunc = _get_print(*p);
			count += (pfunc) ? pfunc(args, &flags) : _printf("%%%c", *p);
		}
		else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}

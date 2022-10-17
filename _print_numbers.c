#include "main.h"

/**
 * _print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int _print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int res = _count_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	_print_number(n);
	return (res);
}

/**
 * _print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int _print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = _convert(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * _print_number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void _print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		_print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * _count_digit - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int _count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}

/**
 * func_digit - Prints an integer
 * @list: the list of arguments the function _printf is receiving
 * Return: count digit
 */
int func_digit(va_list list, __attribute__((unused)) flags_t *f)
{
	unsigned int m;
	int i = 0, k = 0, n = 0, count = 0;

	n = va_arg(list, int);
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n < 0)
		{
			n *= -1;
			_putchar('-');
			count += 1;
		}
		m = n;
		for (k = 0; (m / 10) > 0; k++)
			m /= 10;

		m = n;
		while (k != 0)
		{
			for (i = 0; i < k; i++)
				m /= 10;
			m %= 10;
			_putchar(m + '0');
			count++;
			k--;
			m = n;
		}
		_putchar(m % 10 + '0');
		count++;
	}
	else
	{
		return (-1);
	}
	return (count);
}

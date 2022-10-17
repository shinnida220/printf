#include "main.h"

/**
 * _get_print - a function that selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Return: a pointer to the matching printing function
 */
int (*_get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'s', _print_string},
		{'c', _print_char},
		{'d', _print_int},
		{'i', _print_int},
		{'u', _print_unsigned},
		{'x', _print_hex},
		{'X', _print_hex_big},
		{'b', _print_binary},
		{'o', _print_octal},
		{'R', _print_rot13},
		{'r', _print_rev},
		{'S', _print_bigS},
		{'p', _print_address},
		{'%', _print_percent}};
	int flags = 14;
	register int i;

	for (i = 0; i < flags; i++)
	{
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	}
	return (NULL);
}

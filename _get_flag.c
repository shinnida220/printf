#include "main.h"
/**
 * _get_flag - enables flag if _printf finds
 * a flag modifier in the format string supplied
 * @f: pointer to flags struct
 * @s: character holding the flag
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int _get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
	case '#':
		f->hash = 1;
		i = 1;
		break;
	case ' ':
		f->space = 1;
		i = 1;
		break;
	case '+':
		f->plus = 1;
		i = 1;
		break;
	}

	return (i);
}

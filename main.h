#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
    char c;
    int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums */
int _print_int(va_list l, flags_t *f);
void _print_number(int n);
int _print_unsigned(va_list l, flags_t *f);
int _count_digit(int i);

/* _print_bases */
int _print_hex(va_list l, flags_t *f);
int _print_hex_big(va_list l, flags_t *f);
int _print_binary(va_list l, flags_t *f);
int _print_octal(va_list l, flags_t *f);

/* _converter */
char *_convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* _get_print */
int (*_get_print(char s))(va_list, flags_t *);

/* _get_flag */
int _get_flag(char s, flags_t *f);

/* print_alphanumeric */
int _print_string(va_list l, flags_t *f);
int _print_char(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int _print_rot13(va_list l, flags_t *f);
int _print_rev(va_list l, flags_t *f);
int _print_bigS(va_list l, flags_t *f);

/* _print_address */
int _print_address(va_list l, flags_t *f);

/* _print_percent */
int _print_percent(va_list l, flags_t *f);

#endif

/*
** EPITECH PROJECT, 2022
** mini_.c
** File description:
** mini_
*/
#include "my.h"
#include <stdarg.h>

int condition(const char *format, va_list ap, int ptr)
{
    if (format[ptr + 1] == 'd') {
        my_put_nbr(va_arg(ap, int));
    } if (format[ptr + 1] == 'i') {
        my_put_nbr(va_arg(ap, int));
    } if (format[ptr + 1] == 's') {
        my_fast_putstr(va_arg(ap, char *));
    } if (format[ptr + 1] == 'c') {
        my_putchar(va_arg(ap, int));
    } if (format[ptr + 1] == '%') {
        my_putchar('%');
    } if (format[ptr + 1] == 'b') {
        binaire(va_arg(ap, unsigned int));
    } if (format[ptr + 1] == 'S') {
        nprintable_char(va_arg(ap, char *));
    } if (format[ptr + 1] == 'o') {
        decimal_to_octal(va_arg(ap, int));
    } if (format[ptr + 1] == 'u') {
        non_sign(va_arg(ap, unsigned int));
    }
    return 0;
}

int condition2(const char *format, va_list ap, int ptr)
{
    if (format[ptr + 1] == 'x') {
        into_hex_min(va_arg(ap, int));
    } if (format[ptr + 1] == 'X') {
        into_hex_max(va_arg(ap, int));
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    for (int ptr = 0; format[ptr] != '\0'; ptr++) {
    if (format[ptr] == '%') {
    condition(format, ap, ptr);
    condition2(format, ap, ptr);
    ptr++;
    } else {
    my_putchar(format[ptr]);
    }
    }
    va_end(ap);
    return 0;
}

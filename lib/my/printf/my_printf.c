/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** B-PSU-100-BDX-1-1-bsmyprintf-arthur.py
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../../include/my.h"

int choose_flag4(va_list flags, char letter)
{
    switch(letter){
        case 'X':
            int X = va_arg(flags, int);
            my_putnbr_BASE(X, "0123456789abcdef");
            break;
        default:
            my_putstr("flags error");
            break;
    }
    return 0;
}

int choose_flag3(va_list flags, char letter)
{
    switch (letter){

        case 'C':
            char c = (char) va_arg(flags, int);
            my_putchar(c);
            break;
        case 'S':
            char *str = va_arg(flags, char *);
            my_putstr(str);
            break;
        case 'b':
            int b = va_arg(flags, int);
            my_putnbr_BASE(b, "01");
            break;
        default:
            choose_flag4(flags, letter);
            break;
    }
    return 0;
}

int choose_flag2(va_list flags , char letter)
{
    switch(letter){
        case 'x':
            int x = va_arg(flags, int);
            my_putnbr_base(x, "0123456789abcdef");
            break;
        case 'i':
            int i = va_arg(flags, int);
            my_put_nbr(i);
            break;
        case 'o':
            int o = va_arg(flags, int);
            my_putnbr_base(o, "01234567");
            break;
        default:
            choose_flag3(flags, letter);
            break;
    }
    return 0;
}

int choose_flag(va_list flags , char letter)
{
    switch(letter){
        case 's':
            char *str = va_arg(flags, char *);
            my_putstr(str);
            break;
        case 'd':
            int i = va_arg(flags, int);
            my_put_nbr(i);
            break;
        case 'c':
            char c = (char) va_arg(flags, int);
            my_putchar(c);
            break;
        default:
            choose_flag2(flags, letter);
            break;
    }
    return 0;
}

int my_printf(char *str, ...)
{
    va_list flags;
    va_start(flags, str);
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            choose_flag(flags, str[i]);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    va_end(flags);
    return 0;
}

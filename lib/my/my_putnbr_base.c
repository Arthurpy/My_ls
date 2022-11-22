/*
** EPITECH PROJECT, 2021
** day06
** File description:
** getnbr_base
*/

#include <stdio.h>
#include <unistd.h>

int get_base(char const *base)
{
    int i = 0;

    while (base[i] != '\0') {
        i++;
    }
    return i;
}

void final_result(char *str)
{
    int i = 0;
    char x = 'x';
    while (str[i] != '\0') {
        i++;
    }
    while (i >= 0) {
        write (1, &str[i] , 1);
        if (str[i] == '0')
            write(1, &x, 1);
        i--;
    }
}

int my_putnbr_base(int nbr, char const *base)
{
    int a = 1;
    char result[99];
    int result_int = 0;
    int base_int = get_base(base);
    int cont = 0;

    while (a <= nbr) {
        a = a * base_int;
        cont++;
    }
    while (a >= 1) {
        if (nbr >= a) {
            if ((nbr / a) > 9) {
                result_int = (nbr / a) + 55;
            } else {
                result_int = (nbr / a) + 48;
            }
            result[cont] = (char) result_int;
            nbr = nbr % a;
            a = a / base_int;
        } else {
            result[cont] = 48;
            a = a / base_int;
        }
        cont--;
    }
    final_result(result);
    return 0;
}

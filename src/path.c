/*
** EPITECH PROJECT, 2021
** choose_flag.c
** File description:
** B-PSU-100-BDX-1-1-myls-arthur.py
*/

#include "../include/my.h"

char *tr_path(const char *str, const char *str2)
{
    int str_size1 = my_strlen(str);
    int str_size2 = my_strlen(str2);
    int size = str_size1 + str_size2 + 2;
    char *result = malloc(sizeof(char) * size + 1);
    result[size - 1] = '\0';
    size = size - 2;
    str_size2 = str_size2 - 1;
    int i = 0;

    while (str[i] != '\0')
    {
        result[i] = str[i];
        i++;
    }
    result[i] = '/';
    i++;
    while (str2[i - str_size1 - 1] != '\0')
    {
        result[i] = str2[i - str_size1 - 1];
        i++;
    }
    i++;
    result[i] = '\0';
    my_putstr(result);
    free(result);
    return result;
}
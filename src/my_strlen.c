/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** B-CPE-110-BDX-1-1-BSQ-arthur.py
*/

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}
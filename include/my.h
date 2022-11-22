/*
** EPITECH PROJECT, 2021
** day09
** File description:
** Arthur Py
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int choose_flag(char flag);
int my_strlen(const char *str);
char *tr_path(const char *str, const char *str2);
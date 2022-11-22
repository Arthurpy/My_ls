/* 
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-arthur.py
** File description:
** my_ls
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
#include "../include/my.h"


int my_ls(char *path)
{
    DIR *dir = opendir(path);
    if (dir == 0)
        return 84;
    struct dirent *directory = NULL;
    while ((directory = readdir(dir)) != NULL) {
        if (directory->d_name[0] != '.'){
            my_putstr(directory->d_name);
            my_putchar(' ');
        }
    }
    my_putchar('\n');
    closedir(dir);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc <= 1){
        my_ls(".");
    }
    int i = 1; 
    while (i < argc)
    {
        char *str = argv[i];
        if (str[0] == '-' ){
            choose_flag(str[1]);
        } else {
            if (argc > 2){
                my_putstr(argv[i]);
                my_putstr(":\n");
            }
            my_ls(str);
        }
        i++;
    }
    return 0;
}


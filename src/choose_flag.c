/*
** EPITECH PROJECT, 2021
** choose_flag.c
** File description:
** B-PSU-100-BDX-1-1-myls-arthur.py
*/

#include "my.h"

int flag_l(char *path)
{
    struct stat mem;
    DIR *dir = opendir(path);
    if (dir == 0)
        return 84;
    struct dirent *directory = NULL;
    while ((directory = readdir(dir)) != NULL) {
        if (directory->d_name[0] != '.') {
            stat(directory->d_name, &mem);
            my_put_nbr(mem.st_blocks);
            my_putstr(" ");
            my_putstr(directory->d_name);
            my_putstr("\n");
        }
    }
    my_putchar('\n');
    closedir(dir);
    return (0);
}

int flag_R(char *path)
{
    DIR *dir = opendir(path);
    if (dir == 0)
        return 84;
    my_ls(path);
    struct dirent *directory = NULL;
    while ((directory = readdir(dir)) != NULL) {
        if (directory->d_name[0] != '.') {
            if (directory->d_type == DT_DIR){
                my_putstr(tr_path(path, directory->d_name));
                my_putstr(": \n");
                flag_R(directory->d_name);
            }
        }
    }
    my_putchar('\n');
    closedir(dir);
    return 0;
}

int choose_flag(char flag)
{
    switch (flag){
    case 'R':
    flag_R(".");
    break;
    case 'l':
    flag_l(".");
    break;
    default:
    my_putstr("error");
    break;
}
return 0;
}
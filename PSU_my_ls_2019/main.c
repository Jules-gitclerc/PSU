/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** main
*/

#include "my.h"
#include "my_ls.h"

struct stat file_stat;

char *init_path(char **av)
{
    char *path;

    if (av[1] != NULL)
        path = my_strdup(av[1]);
    else
        path = my_strdup(".");
    return (path);
}

void print_error(char *av)
{
    my_printf("ls: cannot access '%s': No such file or directory\n", av);
}

int exec_mylls(char **av, char *path, int ac, int i)
{
    char *str = NULL;
    DIR *dir;

    if ((dir = opendir(path)) == NULL)
        print_error(av[i]);
    if (ac > 3)
        my_printf("%s:\n", av[i]);
    my_lls(path, str);
    if (i + 1 != ac)
        my_putchar('\n');
    return (0);
}

int main(int ac, char **av)
{
    char *path = init_path(av);

    if (my_strcmp(path, "-l") != 0) {
        path = my_alloc("./", path);
        my_ls(path);
    }
    else if (my_strcmp(path, "-l") == 0) {
        if (ac == 2)
            my_lls("./", NULL);
        for (int i = 2; i <= ac - 1; i++) {
            path = my_alloc("./", my_alloc(my_strdup(av[i]), "/"));
            exec_mylls(av, path, ac, i);
        }
    }
    return (0);
}
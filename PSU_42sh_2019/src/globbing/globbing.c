/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** globbing
*/

#include "mysh.h"
#include "my.h"
#include <dirent.h>

char *check_in(char *str)
{
    char **tmp = my_str_to_word_array(str, ' ');
    DIR *dir = opendir("./");
    struct dirent *dirent;
    char *src = malloc(sizeof(char) * 1000);
    int x = 0;

    if (src == NULL)
        return (NULL);
    if (my_strcmp(tmp[1], "*") == 0 && my_strcmp(tmp[0], "echo") == 0) {
        if (dir != NULL) {
            while ((dirent = readdir(dir)) != NULL) {
                for (int i = 0; dirent->d_name[i] != '\0'; i++, x++)
                    src[x] = dirent->d_name[i];
                src[x] = ' ';
                x++;
            }
            src[x] = '\0';
        } src = my_strcat(my_strcat(tmp[0], " "), src);
        return (src);
    } free_double_tab(tmp);
    closedir(dir);
    return (str);
}
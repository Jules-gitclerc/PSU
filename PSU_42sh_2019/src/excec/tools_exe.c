/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** tools_exe
*/

#include "mysh.h"

int locate_path(const char *name, env_t *env)
{
    int nb = 0;
    int i = 0;

    for (env_t *cur = env->next; cur != NULL; cur = cur->next, i++) {
        for (int i2 = 0; cur->line[i2] == name[nb]; i2++)
            nb++;
        if (nb == my_strlen(name))
            return (i);
        else
            nb = 0;
    }
    return (-1);
}

char *recup_env_path(char *line)
{
    int nb = 0;
    char *new = NULL;

    for (nb = 0; line[nb] != '='; nb++);
    nb++;
    new = malloc(sizeof(char) * ((my_strlen(line) - nb) + 1));
    if (new == NULL)
        exit (84);
    new[(my_strlen(line) - nb)] = '\0';
    for (int i = 0; line[nb] != '\0'; i++, nb++)
        new[i] = line[nb];
    return (new);
}

char **recup_path(env_t *env)
{
    int indic = locate_path("PATH", env);
    char **path = NULL;
    char *new = NULL;
    env_t *cur = env->next;

    if (indic == -1)
        return (NULL);
    for (int i = 0; i < indic; i++, cur = cur->next);
    new = recup_env_path(cur->line);
    path = my_str_to_word_array(new, ':');
    free (new);
    return (path);
}

char *prea_alloc(char *com_b)
{
    char *new = NULL;

    new = malloc(sizeof(char) * (my_strlen(com_b) + 1));
    if (new == NULL)
        return (NULL);
    for (int i = 0; com_b[i] != '\0'; i++)
        new[i] = com_b[i];
    return (new);
}

char *prea_com(char *com_b, char *path_set)
{
    char *new = my_strcat(path_set, "/");
    char *tab[4] = {"./", "../", new, 0};

    for (int i = 0; tab[i] != 0; i++)
        if (my_strncmp(tab[i], com_b, my_strlen(tab[i])) == 0) {
            free (new);
            return (prea_alloc(com_b));
        }
    return (my_strcat(new, com_b));
}

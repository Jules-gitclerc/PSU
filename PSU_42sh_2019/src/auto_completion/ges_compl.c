/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** ges_compl
*/

#include "mysh.h"

char *add_in_str(char *base, char *add)
{
    int nb = my_strlen(base) + my_strlen(add);
    char *new = malloc(sizeof(char) * (nb + 1));
    int len = 0;

    if (new == NULL)
        return (NULL);
    new[nb] = '\0';
    for (int i = 0; base[i] != '\0'; i++, len++)
        new[len] = base[i];
    for (int i = 0; add[i] != '\0'; i++, len++)
        new[len] = add[i];
    free (base);
    return (new);
}

char *create_pannel(char *new, DIR *rep, char *input)
{
    struct dirent *read;

    while ((read = readdir(rep)) != NULL)
        if (read->d_name[0] != '.')
            if (my_strncmp(input, read->d_name, my_strlen(input) - 1) == 0)
                new = add_in_str(new, my_strcat(read->d_name, "  "));
    return (new);
}

char *concat_posibility(char *input, char **path)
{
    char *new = malloc(sizeof(char));
    DIR *rep;

    if (new == NULL)
        return (NULL);
    new[0] = '\0';
    for (int i = 0; path[i] != NULL; i++) {
        rep = opendir(path[i]);
        new = create_pannel(new, rep, input);
        closedir(rep);
    }
    write(1, new, my_strlen(new) - 2);
    my_printf("\n\033[34;01m%s$> \033[00m", recup_pwd());
    return (input);
}

char *ges_compl(char *input, env_t *env)
{
    char **path = recup_path(env);

    concat_posibility(input, path);
    free_double_tab(path);
    return (input);
}

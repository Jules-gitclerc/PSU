/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_where
*/

#include "mysh.h"

int reach_builting(char *param, env_t *env, shell_t *shell)
{
    char *tab[12] = {"env", "exit", "setenv", "unsetenv", "cd", "alias", \
                    "echo", "unalias", "where", "which", "repeat", 0};

    (void)env;
    (void)shell;
    for (int i = 0; tab[i] != 0; i++) {
        if (my_strcmp(tab[i], param) == 0) {
            my_printf("%s is a shell built-in\n", param);
            return (0);
        }
    }
    return (0);
}

int reach_in_alias(char *param, env_t *env, shell_t *shell)
{
    alias_t *cur = shell->alias->next;

    (void)env;
    for (; cur != NULL; cur = cur->next)
        if (my_strcmp(cur->name, param) == 0) {
            my_printf("%s is aliased to %s\n", param, cur->command);
            return (1);
        }
    return (0);
}

int read_file(DIR *rep, char *param, char *path)
{
    struct dirent *read;
    char *res = NULL;
    int len = 0;

    while ((read = readdir(rep)) != NULL)
        if (read->d_name[0] != '.')
            if (my_strcmp(read->d_name, param) == 0) {
                res = my_strcat(path, my_strcat("/", param));
                my_printf("%s\n", res);
                free (res);
                len += 1;
            }
    return (len);
}

int reach_in_path(char *param, env_t *env, shell_t *shell)
{
    DIR *rep;
    char **path = recup_path(env);
    int catch = 0;

    (void)shell;
    if (path == NULL)
        return (0);
    for (int i = 0; path[i] != NULL; i++) {
        rep = opendir(path[i]);
        catch += read_file(rep, param, path[i]);
        closedir (rep);
    }
    free_double_tab(path);
    return (catch);
}

void my_where(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');
    int nb = 3;
    int (*fct[3])(char *param, env_t *env, shell_t *shell) = {reach_builting, \
    reach_in_path, reach_in_alias};

    if (com[1] == NULL) {
        my_printf("where: Too few arguments.\n");
        return;
    }
    for (int i = 1; com[i] != NULL; i++) {
        for (int x = 0; x < nb; x++)
            if (fct[x](com[i], env, shell) >= 1)
                break;
    }
}
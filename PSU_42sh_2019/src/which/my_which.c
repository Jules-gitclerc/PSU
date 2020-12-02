/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_which
*/

#include "mysh.h"

int reach_which_builting(char *param, env_t *env, shell_t *shell)
{
    char *tab[12] = {"env", "exit", "setenv", "unsetenv", "cd", "alias", \
                    "echo", "unalias", "where", "which", "repeat", 0};

    (void)env;
    (void)shell;
    for (int i = 0; tab[i] != 0; i++) {
        if (my_strcmp(tab[i], param) == 0) {
            my_printf("%s: shell built-in command.\n", param);
            return (1);
        }
    }
    return (0);
}

int reach_wich_alias(char *param, env_t *env, shell_t *shell)
{
    alias_t *cur = shell->alias->next;

    (void)env;
    for (; cur != NULL; cur = cur->next)
        if (my_strcmp(cur->name, param) == 0) {
            my_printf("%s:\taliased to %s\n", param, cur->command);
            return (1);
        }
    return (0);
}

int reach_wich_path(char *param, env_t *env, shell_t *shell)
{
    DIR *rep;
    char **path = recup_path(env);
    int catch = 0;

    (void)shell;
    if (path == NULL)
        return (0);
    for (int i = 0; path[i] != NULL; i++) {
        rep = opendir(path[i]);
        catch = read_file(rep, param, path[i]);
        closedir (rep);
        if (catch == 1)
            return (1);
    }
    free_double_tab(path);
    return (0);
}

void my_which(env_t *env, char *input, shell_t *shell)
{
    char **com = my_str_to_word_array(input, ' ');
    int nb = 3;
    int x = 0;
    int (*fct[3])(char *param, env_t *env, shell_t *shell) = { \
    reach_which_builting, reach_wich_path, reach_wich_alias};

    if (com[1] == NULL) {
        my_printf("which: Too few arguments.\n");
        return;
    }
    for (int i = 1; com[i] != NULL; i++) {
        for (x = 0; x < nb; x++)
            if (fct[x](com[i], env, shell) == 1)
                break;
        if (x == nb)
            my_printf("%s: Command not found.\n", com[i]);
    }
}
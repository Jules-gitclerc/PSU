/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** my_exe
*/

#include "mysh.h"

void print_error_exe(char *str)
{
    dprintf(2, "%s: Command not found.\n", str);
    exit (84);
}

char **my_tabdup_env(env_t *env)
{
    char **new_env = NULL;
    int nb_line = 0;
    int i = 0;

    for (env_t *cur = env->next; cur != NULL; cur = cur->next, nb_line++);
    new_env = malloc(sizeof(char *) * (nb_line + 1));
    if (new_env == NULL)
        return (NULL);
    new_env[nb_line] = NULL;
    for (env_t *cur = env->next; cur != NULL; cur = cur->next, i++) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(cur->line) + 1));
        if (new_env[i] == NULL)
            return (NULL);
        new_env[i][my_strlen(cur->line)] = '\0';
        for (int o = 0; cur->line[o] != '\0'; o++)
            new_env[i][o] = cur->line[o];
    }
    return (new_env);
}

int check_comp_exce(env_t *env, char **com)
{
    char **new_env = my_tabdup_env(env);
    int exe_val = 0;
    char *command = NULL;

    exe_val = execve(com[0], com, new_env);
    free (command);
    if (exe_val == -1)
        print_error_exe(com[0]);
    free_double_tab(new_env);
    return (exe_val);
}

int my_exe_bis(env_t *env, char **com)
{
    char **path = recup_path(env);
    char **new_env = my_tabdup_env(env);
    int exe_val = 0;
    char *command = NULL;

    if (path == NULL)
        check_comp_exce(env, com);
    if (error_handling_excec(com) == -1)
        exit (-1);
    for (int i = 0; path[i] != NULL; i++) {
        command = prea_com(com[0], path[i]);
        exe_val = execve(command, com, new_env);
        free (command);
    }
    if (exe_val == -1)
        print_error_exe(com[0]);
    free_double_tab(path);
    free_double_tab(new_env);
    return (exe_val);
}

int my_exe(env_t *env, char *input)
{
    char **com = my_str_to_word_array(input, ' ');
    int status = 0;

    status = my_exe_bis(env, com);
    free_double_tab(com);
    return (status);
}

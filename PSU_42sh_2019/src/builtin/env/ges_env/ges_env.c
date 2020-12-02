/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** ges_env
*/

#include "mysh.h"

void go_to_racine(shell_t *shell, char *pwd)
{
    int count = 0;
    int nb_slach = 0;

    for (int i = 0; pwd[i] != '\0' && nb_slach <= 2; i++, count++)
        if (pwd[i] == '/')
            nb_slach++;
    shell->rac = malloc(sizeof(char) * (count + 1));
    if (shell->rac == NULL)
        exit (84);
    shell->rac[count] = '\0';
    for (int i = 0; i < count; i++)
        shell->rac[i] = pwd[i];
}

void add_node_env(char *str, env_t *env)
{
    env_t *cur = env;

    for (; cur->next != NULL; cur = cur->next);
    cur->next = malloc(sizeof(env_t));
    cur = cur->next;
    cur->next = NULL;
    cur->line = malloc(sizeof(char) * my_strlen(str) + 1);
    cur->line[my_strlen(str)] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
        cur->line[i] = str[i];
}

void init_head_env(env_t *env)
{
    env->line = NULL;
    env->next = NULL;
}

void fill_env(char **envp, env_t *env)
{
    init_head_env(env);
    for (int i = 0; envp[i] != NULL; i++)
        add_node_env(envp[i], env);
}

void my_env(env_t *env, char *input, shell_t *shell)
{
    (void)input;
    (void)shell;
    for (env_t *cur = env->next; cur != NULL; cur = cur->next)
        my_printf("%s\n", cur->line);
}

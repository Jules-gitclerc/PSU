/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "minishell.h"
#include "my.h"
#include "sys/wait.h"
#include "sys/types.h"

char my_commands(char **str, t_list *env)
{
    char *commands[3] = {"exit", "env", "setenv"};
    char (*direction[3])(char **, t_list *) = {my_exit, my_env, my_setenv};
    int i = 0;

    if (my_strcmp(str[0], "unsetenv") == 0)
        return (-100);
    if (my_strcmp(str[0], "cd") == 0)
        return (-100);
    while (i < 4 && (my_strcmp(str[0], commands[i]) != 0))
        i++;
    return (i == 3 ? 100 : direction[i](str, env));
}

char my_minishell(char *input, t_list *env)
{
    char **str = my_str_custom_array(input, ' ');

    if (str[0] == NULL || str == NULL)
        return (0);
    if ((my_commands(str, env)) == -100)
        return (0);
    if ((my_commands(str, env)) == 100)
        my_exec(str, env, search_env(env, "PATH"));
    return (0);
}

t_list *create_node(void)
{
    t_list	*node;

    if ((node = malloc(sizeof(t_list))) == NULL)
        return (NULL);
    node->next = node;
    node->prev = node;
    return (node);
}

t_list *init_env(char **env)
{
    t_list	*chain;
    t_list	*chain2;
    int i = 0;
    int j = 0;

    chain = create_node();
    while (env[i] != NULL) {
        j = -1;
        chain2 = create_node();
        if ((chain2->data = malloc(my_strlen(env[i]) + 1)) == NULL)
    	    return (NULL);
        while (env[i][++j] != '\0')
    	    chain2->data[j] = env[i][j];
        chain2->data[j] = '\0';
        chain2->prev = chain->prev;
        chain2->next = chain;
        chain->prev->next = chain2;
        chain->prev = chain2;
        i++;
    }
    return (chain);
}

int	main(int ac, char **av, char **env)
{
    char *input = NULL;
    size_t size;
    char cwd[256];
    t_list *envp;

    (void)ac;
    (void)av;
    envp = init_env(env);
    while (1) {
        getcwd(cwd, sizeof(cwd));
        my_printf("\033[30;44m~%s$>\033[0m ", cwd);
        if (getline(&input, &size, stdin) == -1) {
            my_printf("exit\n");
            exit(0);
        }
        input[my_strlen(input) - 1] = '\0';
        my_minishell(input, envp);
    }
    return (0);
}
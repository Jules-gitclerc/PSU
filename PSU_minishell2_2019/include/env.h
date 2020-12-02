/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** env
*/

#ifndef ENV_H_
#define ENV_H_

/*
** env
*/

#include "my.h"

typedef struct s_env
{
    char *data;
    struct s_env *next;
    struct s_env *prev;
} t_env;

t_env *init_listenv(char **env);
t_env *add_env(t_env *env, char *str, char *str2);
void display_env(t_env *env);
t_env *update_env(t_env *env, char *dir, char *str);
char *search_env(t_env *env, char *str);
char **conv_list(t_env *env);
void remove_env(t_env *env, char *command);
char my_setenv(char **command, t_env *env);
char my_env(char **command, t_env *env);
char my_unsetenv(char **command, t_env *env);
int count_list(t_env *tmp, t_env *env);

#endif /* !ENV_H_ */

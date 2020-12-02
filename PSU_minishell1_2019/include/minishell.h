/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

typedef struct		s_list
{
    char *data;
    struct s_list *next;
    struct s_list *prev;
}			t_list;

t_list *create_node(void);
char **my_str_custom_array(char *str, char c);

/*
** my_commands
*/

void my_free(char **tab);
char my_env(char **str, t_list *env);
char my_exec(char **command, t_list *env, char *path);
char **conv_list(t_list *env);
char *search_env(t_list *env, char *str);
char my_puterror_execve(char *error, char **command);
char my_exit(char **str, t_list *env);
char my_setenv(char **str, t_list *env);

/*
** str
*/

char *my_custom_strcat(char *path, char *command, int cond);
char my_custom_strcmp(char *s1, char *s2);

#endif /* !MINISHELL_H_ */
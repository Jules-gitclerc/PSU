/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_

#include "env.h"

typedef struct s_command
{
    char **data;
    int fd;
    int output;
    int input;
    struct s_command *next;
    struct s_command *prev;
} t_command;

typedef struct s_list
{
    t_command *first;
    t_command *last;
} t_list;

/*
** utils_str
*/

char **separe_wordtab(char *str, char c);
char *my_custom_strcat(char *path, char *command, int cond);

/*
** parser
*/

char *parser(char *tab, t_env *env, t_list *list);

/*
** command
*/

char check_command(t_command *command, t_env *env);

/*
** exec
*/

int my_execve(t_command *tab, t_env *env, int *pipe);

/*
** tools
*/

void my_free(char **tab);
void close_pipe(int *pipe);

/*
** cd
*/

char my_cd(char **command, t_env *env);

/*
** exit
*/

char my_exit(char **command, t_env *env);

/*
** pipe
*/

int my_pipe(t_command *command);

#endif /* !MYSH_H_ */

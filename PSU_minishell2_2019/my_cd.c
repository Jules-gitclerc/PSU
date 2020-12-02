/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** my_cd
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"
#include "env.h"

static char *get_pwd(void)
{
    char *pwd = malloc(sizeof(char *) * 1000);

    if (pwd == NULL)
        exit(84);
    getcwd(pwd, sizeof(pwd));
    return (pwd);
}

char *update_env_cd(t_env *env, char *change)
{
    char *buff = malloc(sizeof(char *) * 1000);

    if (search_env(env, change) != NULL) {
        if (buff == NULL)
            exit(84);
        getcwd(buff, sizeof(buff));
        env = update_env(env, my_custom_strcat(my_custom_strcat(change, "=", 0)
        , buff, 0), change);
        free(buff);
    }
    return (NULL);
}

char *check_directory(t_env *env, char *command, char *oldpwd)
{
    char *dir;

    if (command == NULL || my_strcmp(command, " ") != 0
        || my_strcmp(command, "\t") != 0 || my_strcmp(command, "\0") != 0)
        dir = search_env(env, "HOME");
    else if (my_strcmp(command, "-") != 0)
        dir = (oldpwd == NULL) ? "\0" : oldpwd;
    else if (my_strcmp(command, "~") != 0)
        dir = search_env(env, "HOME");
    else
        dir = command;
    return (dir);
}

char my_cd(char **command, t_env *env)
{
    static char *oldpwd;
    char *dir = check_directory(env, command[1], oldpwd);

    if (dir == NULL)
        return (0);
    if (access(dir, F_OK) == -1) {
        my_printf("cd: no such file or director: %s\n", dir);
        return (0);
    }
    if (access(dir, R_OK) == -1) {
        my_printf("cd: Permission denied: %s\n", dir);
        return (0);
    }
    oldpwd = get_pwd();
    if (chdir(dir) == -1) {
        my_printf("cd: You cannot change the dir: %s\n", dir);
        return (0);
    }
    update_env_cd(env, "PWD");
    return (0);
}

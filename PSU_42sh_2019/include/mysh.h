/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_

#include "my.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <getopt.h>
#include <termios.h>
#include <sys/select.h>

/*-------double_redir---------*/
typedef struct save_s save_t;
struct save_s {
    char *line;
    save_t *next;
};
int add_node_save(save_t *save, char *input);

/*------------var-------------*/
typedef struct set_var var_t;
struct set_var {
    char *line;
    int n;
    var_t *next;
};

/*------------alias------------*/
typedef struct set_alias alias_t;
struct set_alias {
    char *name;
    char *command;
    alias_t *next;
};
void display_alias(alias_t *alias);
void look_and_display(alias_t *alias, char *catch);
char *my_strdup_name(char *str);
char *check_alias(char *input, alias_t *alias);

/*------------shell------------*/
typedef struct tools_shell {
    char *rac;
    int exit_value;
    alias_t *alias;
    var_t *var;
    save_t *save;
    int fd;
    int fd_modif;
    int fd_to_switch;
} shell_t;
char *recup_first_command(char *input);
char *suppr_one_carat(char *input);
void free_double_tab(char **tab);
/*---->signal*/
void signal_ctrl_c(int sig);

/*-------------env-------------*/
typedef struct set_env env_t;
struct set_env {
    char *line;
    env_t *next;
};

/*---->ges_env*/
char **my_tabdup_env(env_t *env);
void fill_env(char **envp, env_t *env);
void go_to_racine(shell_t *shell, char *pwd);
void my_env(env_t *env, char *input, shell_t *shell);
void destroy_env_list(env_t *env);

/* ->shell*/
void loop_shell(env_t *env);
char *recup_input(env_t *env);
int display_reset_save(save_t *save, char *input, env_t *env);
char *my_realloc_read(char *buf, char letter);
char *patch_back_slash_n(char *str);
int my_strcmp_carat(char *red, char *input);
int looking_input(env_t *env, char *input, shell_t *shell);
int check_error_command(char *input); /* 84 = error -> 0 = OK */
void separator(env_t *env, char *input, shell_t *shell);
int pars_command(env_t *env, char *input, shell_t *shell, int mode);
/* ->shell*/

/*-------alias_bis-------------*/
void my_alias(env_t *env, char *input, shell_t *shell);
int init_alias(shell_t *shell);

/*-----------pwd---------------*/
char *recup_pwd(void);

/*----------exit---------------*/
void my_exit(env_t *env, char *input, shell_t *shell);

/*---------setenv--------------*/
void my_setenv(env_t *env, char *input, shell_t *shell);
int check_input_setenv(char **com);

/*---------unsetenv------------*/
void my_unsetenv(env_t *env, char *input, shell_t *shell);

/*------change_directory-------*/
void my_cd(env_t *env, char *input, shell_t *shell);

/*--------exe------------------*/
char **recup_path(env_t *env);
char *prea_com(char *com_b, char *path_set);
int my_exe(env_t *env, char *input);
int my_exe_bis(env_t *env, char **com);
void segfault_handling(int status);
int error_handling_excec(char **com);

/*---------pipe---------------*/
int pipe_proc(char **pars_pipe, env_t *env, shell_t *shell);

/*---------redirect-----------*/
int ges_left_redirect(char *input);
char *recup_com_redirect(char *input);
int redir_left(char *input, shell_t *shell);
int reset_fd(shell_t *shell);
int double_redir_left(char *input, shell_t *shell);

/*----------echo--------------*/
void my_echo(env_t *env, char *input, shell_t *shell);

/*----------unalias-----------*/
void my_unalias(env_t *env, char *input, shell_t *shell);

/*---------operators-----------*/
int operator_loop(env_t *env, char *input, shell_t *shell);
int check_op_errors(char *command);
char **ft_split_2_sep(char *str, char *sep1, char *sep2);
char *get_operators(char *input);

/*-------auto_completion-------*/
char *ges_compl(char *input, env_t *env);

/*----------where--------------*/
void my_where(env_t *env, char *input, shell_t *shell);
int read_file(DIR *rep, char *param, char *path);

/*----------which--------------*/
void my_which(env_t *env, char *input, shell_t *shell);

/*-----------repeat------------*/
void my_repeat(env_t *env, char *input, shell_t *shell);

/*----------local var--------------*/
char *exec_var(char *str, env_t *env, var_t *var);
char *clean_space(char *str);
char *clean_quote(char *str);
char *replace_space(char *str, int nb);
char *clean_double(char *str);
int count_space2(char *str);
void my_set(env_t *env, char *input, shell_t *shell);
void my_unset_var(env_t *env, char *input, shell_t *shell);
int init_var(shell_t *shell);
int check_input_set(char *com);
void display_set(var_t *var);
int search_exist_var(const char *name, var_t *var, char **com);
void change_env_set_var(var_t *var, int i, char *name, char *enviro);
int count_nb_arg(char **com);
char *check_var(char *input, env_t *env, shell_t *shell);

/*--------------globbing-------------*/
char *check_in(char *str);

#endif /* !MYSH_H_ */

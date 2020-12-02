/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** my_cd
*/

#include "mysh.h"

char *alloc_after(char *pwd)
{
    int nb = my_strlen(pwd);
    char *new = malloc(sizeof(char) * nb + 1);

    new[nb] = '\0';
    for (int i = 0; i < nb; i++)
        new[i] = pwd[i];
    free (pwd);
    return (new);
}

int check_error_cd(char **com)
{
    int nb_arg = 0;

    for (nb_arg = 0; com[nb_arg] != NULL; nb_arg++);
    if (nb_arg >= 3) {
        my_printf("cd: Too many arguments.\n");
        free_double_tab(com);
        return (-1);
    }
    return (0);
}

void setup_env(env_t *env, shell_t *shell)
{
    char *input_set = NULL;

    input_set = my_strcat("a PWD ", recup_pwd());
    my_setenv(env, input_set, shell);
    free (input_set);
}

void my_cd(env_t *env, char *input, shell_t *shell)
{
    static char *after = NULL;
    char **com = my_str_to_word_array(input, ' ');
    char *pwd_last = recup_pwd();

    if (check_error_cd(com) == -1) {
        free (pwd_last);
        return;
    }
    if (com[1] == NULL || (com[1][0] == '~' && my_strlen(com[1]) == 1))
        chdir(shell->rac);
    else if (com[1][0] == '-' && my_strlen(com[1]) == 1 && after != NULL)
        chdir(after);
    else
        if (chdir(com[1]) == -1)
            my_printf("%s: Not a directory.\n", com[1]);
    free (after);
    after = alloc_after(pwd_last);
    setup_env(env, shell);
    free_double_tab(com);
}

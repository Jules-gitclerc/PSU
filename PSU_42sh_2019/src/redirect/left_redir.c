/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** left_redir
*/

#include "mysh.h"

char *recup_short_input(void)
{
    char letter;
    char *input = malloc(sizeof(char));
    int read_c = 0;

    input[0] = '\0';
    for (letter = '\0'; letter != '\n'; letter = letter) {
        read_c = read(0, &letter, 1);
        if (letter == 4 || read_c == 0)
            return (NULL);
        input = my_realloc_read(input, letter);
    }
    return (input);
}

int double_redir_left(char *input, shell_t *shell)
{
    char **pars = my_str_to_word_array(input, '<');
    char *tmp = NULL;

    while (1) {
        my_printf("? ");
        tmp = recup_short_input();
        if (tmp == NULL || my_strcmp(patch_back_slash_n(tmp),
        my_clean_str(pars[2])) == 0)
            return (0);
        add_node_save(shell->save, tmp);
        free (tmp);
    }
    return (0);
}

int redir_left(char *input, shell_t *shell)
{
    char **array = my_str_to_word_array(input, ' ');

    shell->fd = open(array[2], O_RDONLY | O_CREAT, S_IWUSR
    | S_IRUSR);
    if (shell->fd == -1) {
        my_printf("%s: Permission denied.\n",
        array[2]);
        return (0);
    }
    shell->fd_modif = dup(0);
    dup2(shell->fd, 0);
    shell->fd_to_switch = 0;
    return (0);
}

int reset_fd(shell_t *shell)
{
    if (shell->fd) {
        dup2(shell->fd_modif, shell->fd_to_switch);
        close(shell->fd);
        close(shell->fd_modif);
        shell->fd = 0;
        shell->fd_modif = -1;
    }
    return (0);
}
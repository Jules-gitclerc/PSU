/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** error_handling_excec
*/

#include "mysh.h"

int error_handling_excec(char **com)
{
    struct stat file_info;
    if (com[0][0] == '.') {
        if (stat(com[0], &file_info)) {
            my_printf("%s: Command not found.\n", com[0]);
            return (-1);
        }
        if (access(com[0], X_OK) ||
        S_ISDIR(file_info.st_mode)) {
            my_printf("%s: Permission denied.\n", com[0]);
            return (-1);
        }
    }
    return (0);
}

void segfault_handling(int status)
{
    if (WIFEXITED(status))
        status = (WEXITSTATUS(status));
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 8)
            my_printf("Floating exception");
        else
            my_printf("%s", strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            my_printf(" (core dumped)");
        status = WTERMSIG(status) + 128;
        my_printf("\n");
    }
}
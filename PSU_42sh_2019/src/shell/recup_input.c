/*
** EPITECH PROJECT, 2020
** the_beautiful_mysh_2019_2020
** File description:
** recup_input
*/

#include "mysh.h"

struct termios orig_termios;

void set_conio_terminal_mode(void)
{
    struct termios new_termios;

    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(struct termios));
    new_termios.c_cc[VMIN] = 1;
    new_termios.c_cc[VTIME] = 0;
    new_termios.c_lflag &= ~ICANON;
    new_termios.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new_termios);
}

char *patch_back_slash_n(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            str[i] = '\0';
    return (str);
}

char *my_realloc_read(char *buf, char letter)
{
    int nb = my_strlen(buf) + 1;
    char *new = malloc(sizeof(char) * nb + 1);
    int i = 0;

    new[nb] = '\0';
    for (; buf[i] != '\0'; i++)
        new[i] = buf[i];
    new[i] = letter;
    free (buf);
    return (new);
}

char *recup_input(env_t *env)
{
    char letter;
    char *input = malloc(sizeof(char));
    int read_c = 0;

    (void)env;
    input[0] = '\0';
    for (letter = '\0'; letter != '\n'; letter = letter) {
        read_c = read(0, &letter, 1);
        if (letter == 4 || read_c == 0) {
            if (isatty(0) == 1)
                my_printf("exit\n");
            exit(0);
        }
        input = my_realloc_read(input, letter);
    }
    return (my_clean_str(patch_back_slash_n(input)));
}

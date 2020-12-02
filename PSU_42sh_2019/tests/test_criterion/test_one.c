/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** test_one
*/

#include "mysh.h"
#include <criterion/criterion.h>

Test(test_01, test_my_strcmp_carat)
{
    char *str = "je suis la >> couscous< > epitech promo 2024 \n soso Maness";
    char *read[] = {"je", "coquelicot"};
    int ret_value[] = {1, 0, -1};
    int catch = 0;

    for (int i = 0; ret_value[i] != -1; i++) {
        catch = my_strcmp_carat(read[i], str);
        cr_assert(catch == ret_value[i], \
        "Input = %s -> expected value = %d -> I receive = %d\n", \
        read[i], ret_value, catch);
    }
}

Test(test_02, test_my_strdup_name)
{
    char *str[] = {"EPITECH", "j'aime le veau", "Salut a tous les amis....",
    "j'adore le 42", "je suis passer chez SOSH", "Grosgiteck", 0};
    char *catch = NULL;

    for (int i = 0; str[i] != 0; i++) {
        catch = my_strdup_name(str[i]);
        cr_assert(my_strcmp(str[i], catch) == 0,
        "Input = %s -> expected value = %s -> I receive = %s\n", \
        str[i], str[i], catch);
        free (catch);
    }
}

Test(test_03, test_check_error_command)
{
    char *input[] = {"ls | cat -e | wc", "ls << >> wc", "ls | wc"};
    int ret_value[] = {0, 84, 0, -1};
    int catch = 0;

    for (int i = 0; ret_value[i] != -1; i++) {
        catch = check_error_command(input[i]);
        cr_assert(catch == ret_value[i], \
        "Input = %s -> expected value = %d -> I receive = %d\n", \
        input[i], ret_value, catch);
    }
}

Test(test_04, test_my_clean_str)
{
    char *input[] = {"\trien        \t de           nouveaux", \
    "    cous     cous \tparty    ", \
    "ces la chenille qui redemare", 0};
    char *ret_value[] = {"rien de nouveaux", "cous cous party", \
    "ces la chenille qui redemare", 0};
    char *catch = NULL;

    for (int i = 0; input[i] != 0; i++) {
        catch = my_clean_str(input[i]);
        cr_assert(my_strcmp(ret_value[i], catch) == 0,
        "Input = %s -> expected value = %s -> I receive = %s\n", \
        input[i], ret_value[i], catch);
        free(catch);
    }
}
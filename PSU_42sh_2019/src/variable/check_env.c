/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** init_local
*/

#include "mysh.h"
#include "my.h"

char *replace_var(char *str)
{
    int i = 0;
    int x = -1;
    char *tmp = malloc(sizeof(char) * my_strlen(str));

    if (tmp == NULL)
        return (NULL);
    str = replace_space(str, 1);
    for (i = 0; str[i] != '='; i++);
    while (str[++i] != '\0')
        tmp[++x] = str[i];
    tmp[x + 1] = '\0';
    str = replace_space(str, 2);
    return (tmp);
}

char *get_var(var_t *var, char **tmp, int i, env_t *env)
{
    for (var_t *cur1 = var->next; cur1 != NULL; cur1 = cur1->next)
            if (my_strncmp(tmp[i], cur1->line, my_strlen(tmp[i])) == 0
            && tmp[i][0] != '\0') {
                tmp[i] = replace_var(cur1->line);
                var->n = 1;
            }
    for (env_t *cur = env->next; cur != NULL; cur = cur->next)
            if (my_strncmp(tmp[i], cur->line, my_strlen(tmp[i])) == 0
            && tmp[i][0] != '\0' && var->n == 0)
                tmp[i] = replace_var(cur->line);
    return (tmp[i]);
}

char *exec_var(char *str, env_t *env, var_t *var)
{
    int nb = count_space2(str);
    char **tmp = my_str_to_word_array(clean_double(replace_space(
        clean_quote(str), 0)), '$');
    char *src = malloc(sizeof(char) * 1000);
    int z = 0;
    int c = 0;

    for (int i = 0; tmp[i] != NULL; i++, c++) {
        var->n = 0;
        tmp[i] = get_var(var, tmp, i, env);
        for (int x = 0; tmp[i][x] != '\0'; x++, z++)
            src[z] = tmp[i][x];
        if (tmp[i + 1] == NULL)
            src[z] = '\0';
        else if (c < nb)
            src[z++] = ' ';
    }
    free_double_tab(tmp);
    return (src);
}

char *check_var(char *input, env_t *env, shell_t *shell)
{
    char *tmp = NULL;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '$' && input[i - 1] != 92) {
            tmp = exec_var(input, env, shell->var);
            return (tmp);
        }
    }
    return (input);
}


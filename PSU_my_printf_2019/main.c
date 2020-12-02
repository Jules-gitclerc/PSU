/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** main
*/

#include <stdio.h>
#include "my.h"

int main(void)
{
    int a = 42;
    my_printf("my_printf = %s%s%s%d %k%d\n", "hello", "hey", "yolo", 18, 42);
    printf("printf = %s%s%s%d %k%d\n > \n", "hello", "hey", "yolo", 18, 42);
    my_printf("my_printf = %s\n", "hello");
    printf("printf = %s\n > \n", "hello");
    my_printf("my_printf = %c\n", 'o');
    printf("printf = %c\n > \n", 'o');
    my_printf("my_printf = %d\n", 42);
    printf("printf = %d\n > \n", 42);
    my_printf("my_printf = %i\n", 22);
    printf("printf = %i\n > \n", 22);
    my_printf("my_printf = %x\n", 46);
    printf("printf = %x\n > \n", 46);
    my_printf("my_printf = %X\n", 46);
    printf("printf = %X\n > \n", 46);
    my_printf("my_printf = %o\n", 10000);
    printf("printf = %o\n > \n", 10000);
    my_printf("my_printf = %p\n", &a);
    printf("printf = %p\n > \n", &a);
    my_printf("my_printf = %%p\n", &a);
    printf("printf = %%p\n > \n", &a);
    my_printf("my_printf = %s%dAstek42%\n", "hello", 18);
    printf("printf = %s%dAstek42%\n > \n", "hello", 18);
    my_printf("my_printf = Astek\n");
    printf("printf = Astek\n > \n");
    my_printf("my_printf =  \\[astek\\] \n");
    printf("printf =  \\[astek\\] \n > \n");
    my_printf("my_printf = %b\n > \n", 999);
    my_printf("my_printf = %S\n > \n", "t6to");
    my_printf("my_printf = %%%%%%%d\n", 42);
    printf("printf = %%%%%%%d\n > \n", 42);
    my_printf("my_printf = %     d\n", 42);
    printf("printf = %     d\n > \n", 42);
    my_printf("my_printf = %%%%%%%%d\n", 42);
    printf("printf = %%%%%%%%d\n > \n", 42);

    return (0);
}


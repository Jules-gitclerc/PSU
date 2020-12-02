/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ls
*/

#include "my_ls.h"
#include "my.h"

int my_ls(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *dent;

    if (dir != NULL) {
        while ((dent = readdir(dir)) != NULL) {
            if ((my_strcmp(dent->d_name, ".") == 0 ||
            my_strcmp(dent->d_name,"..") == 0 || (*dent->d_name) == '.' ))
                return (0);
            else {
                my_putstr(dent->d_name);
                my_putchar('\n');
            }
        }
    }
    closedir(dir);
    return (0);
}

char *my_alloc(char *dest, char *str)
{
    int nb = my_strlen(dest) + my_strlen(str);
    char *alloc = malloc(sizeof(char) * nb + 1);
    int run = 0;

    for (int i = 0; dest[i] != '\0'; i++, run++)
        alloc[run] = dest[i];
    for (int x = 0; str[x] != '\0'; x++, run++)
        alloc[run] = str[x];
    alloc[nb] = '\0';
    return (alloc);
}

void display_total(char *path)
{
    struct stat st;
    struct dirent *drt;
    char *str;
    int tmp = 0;
    DIR *dir = opendir(path);

    while ((drt = readdir(dir))) {
        str = my_alloc(my_alloc(path, "/"), drt->d_name);
    	if ((lstat(str, &st)) == 0)
    		(drt->d_name[0] != '.') ? tmp += st.st_blocks : 0;
    }
    closedir(dir);
    my_printf("total %d\n", tmp / 2);
}

void my_perm(struct stat s)
{
    my_putstr(S_ISDIR(s.st_mode) ? "d" : "-");
    my_putstr(s.st_mode & S_IRUSR ? "r" : "-");
    my_putstr(s.st_mode & S_IWUSR ? "w" : "-");
    my_putstr(s.st_mode & S_IXUSR ? "x" : "-");
    my_putstr(s.st_mode & S_IRGRP ? "r" : "-");
    my_putstr(s.st_mode & S_IWGRP ? "w" : "-");
    my_putstr(s.st_mode & S_IXGRP ? "x" : "-");
    my_putstr(s.st_mode & S_IROTH ? "r" : "-");
    my_putstr(s.st_mode & S_IWOTH ? "w" : "-");
    my_putstr(s.st_mode & S_IXOTH ? "x" : "-");
}

void my_lls(char *path, char *str)
{
    struct dirent *dirent;
    struct stat st;
    struct passwd *passwd;
    struct group *group;
    DIR *dir = opendir(path);

    display_total(path);
    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            str = my_alloc(path, dirent->d_name);
            stat(str, &st);
            passwd = getpwuid(st.st_uid);
            group = getgrgid(st.st_gid);
            my_perm(st);
            my_printf(" %i %s", st.st_nlink, passwd->pw_name);
            my_printf(" %s %i ", group->gr_name, st.st_size);
            write(1, ctime(&st.st_mtime), my_strlen(ctime(&st.st_mtime) - 9));
            my_printf(" %s\n", dirent->d_name);
        }
    }
}
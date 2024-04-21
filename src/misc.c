/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"

int my_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int my_isalnum(int c)
{
    return (my_isalpha(c) || (c >= '0' && c <= '9'));
}

int is_valid_string(const char *str, sta_t *p)
{
    if (*str == '\0' || !my_isalpha(*str)) {
        p->value = 1;
        my_putstr_err("setenv: Variable name must begin with a letter.\n", 2);
        return 0;
    }
    for (str++; *str != '\0'; str++) {
        if (!my_isalnum(*str)) {
            p->value = 1;
            my_putstr_err("setenv: Variable name must contain ", 2);
            my_putstr_err("alphanumeric characters.\n", 2);
            return 0;
        }
    }
    return 1;
}

int env_len(char **env)
{
    int len = 0;
    while (env[len] != NULL) {
        len++;
    }
    return len;
}

char **unset_many(int argc, char **argv, char **env)
{
    for (int k = 0; k < argc; k++) {
        env = unset_env(env, argv[k]);
    }
    return env;
}

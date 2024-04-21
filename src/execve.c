/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"

char **execmd(char **argv, int argc, char **env, sta_t *p)
{
    if (argv[0] == NULL) { return env;
    } if ((my_strncmp(argv[0], "exit", 4) == 1)
    && (my_strlen(argv[0]) == my_strlen("exit"))) {
        exit_command(argv[1]); return env;
    } if (my_strncmp(argv[0], "setenv", 6) == 1
    && (my_strlen(argv[0]) == my_strlen("setenv"))) {
        (argc > 3) ? my_putstr_err("setenv: Too many arguments.\n", 2),
        p->value = 1 : 0;
        (argc == 1) ? my_put_tab(env) : 0;
        (argc == 2) ? env = set_env2(env, argv[1], p) : 0;
        (argc == 3) ? env = set_env1(env, argv[1], argv[2], p) : 0;
        return env;
    } if (my_strncmp(argv[0], "unsetenv", 8) == 1
    && (my_strlen(argv[0]) == my_strlen("unsetenv"))) {
        (argc == 1) ? my_putstr_err("unsetenv: Too few arguments.\n", 2),
        p->value = 1 : 0;
        (argc == 2) ? env = unset_env(env, argv[1]) : 0;
        (argc > 2) ? env = unset_many(argc, argv, env) : 0;
        return env;
    } return help_execmd(argv, argc, env, p);
}

char **help_execmd(char **argv, int argc, char **env, sta_t *p)
{
    if (my_strncmp(argv[0], "cd", 2) == 1
    && (my_strlen(argv[0]) == my_strlen("cd"))) {
        cd_command(argc, argv[1], argv[0], env);
        return env;
    } if (my_strncmp(argv[0], "env", 3) == 1
    && (my_strlen(argv[0]) == my_strlen("env"))) {
        my_put_tab(env);
        return env;
    } else {
        p->value = my_fork_minishell(argv, env, argv[0]);
    }
    return env;
}

int array_len(char **argv)
{
    int k = 0;
    while (argv[k] != NULL) {
        k++;
    }
    return k;
}

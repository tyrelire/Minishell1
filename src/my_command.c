/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"

int cd_command(int argc, char *cmd, char *cmd2, char **env)
{
    char *goofy = my_getpath_home(env);
    if (argc > 2) {
        my_putstr_err(cmd2, 2);
        my_putstr_err(": Too many arguments.\n", 2);
        return 0;
    }
    if (cmd == NULL && argc < 2) {
        chdir(goofy);
    }
    if (chdir(cmd) == -1 && cmd != NULL) {
        my_putstr_err(cmd, 2);
        my_putstr_err(": Not a directory.\n", 2);
        return 0;
    }
    if (cmd) {
        chdir(cmd);
        return 0;
    }
    return 0;
}

void exit_command(char *cmd)
{
    if (!cmd) {
        exit(0);
    } else if (cmd) {
        int nbr = my_get_nbr(cmd);
        exit(nbr);
    }
}

char **set_env1(char **env, char *name, char *value, sta_t *p)
{
    int nlen = my_strlen(name); int i = 0;
    if (is_valid_string(name, p) == 0) { return env;
    } for (i = 0; env[i] != NULL; i++) {
        if ((my_strncmp(env[i], name, nlen) == 1) && (env[i][nlen] == '=')) {
            char *new_entry = malloc(my_strlen(name) + my_strlen(value) + 2);
            new_entry = my_strcpy(new_entry, name);
            new_entry = my_strcat(new_entry, "=");
            new_entry = my_strcat(new_entry, value);
            env[i] = NULL; env[i] = new_entry; return env;
        }
    } char **new_env = malloc(sizeof(char *) * (i + 2)); int j = 0;
    for (j = 0; j != i; j++) {
        new_env[j] = malloc(sizeof(char) * my_strlen(env[j]) + 1);
        new_env[j] = my_strcpy(new_env[j], env[j]);
    } new_env[j] = malloc(my_strlen(name) + my_strlen(value) + 2);
    new_env[j] = my_strcpy(new_env[j], name);
    new_env[j] = my_strcat(new_env[j], "=");
    new_env[j] = my_strcat(new_env[j], value);
    new_env[j][my_strlen(name) + my_strlen(value) + 1] = '\0';
    new_env[j + 1] = NULL; free(env); return new_env;
}

char **set_env2(char **env, char *name, sta_t *p)
{
    if (is_valid_string(name, p) == 0) {
        return env;
    } int nlen = my_strlen(name); int i = 0;
    for (i = 0; env[i] != NULL; i++) {
        if ((my_strncmp(env[i], name, nlen) == 1)
        && (env[i][nlen] == '=')) {
            char *new_entry = malloc(my_strlen(name) + 2);
            new_entry = my_strcpy(new_entry, name);
            new_entry = my_strcat(new_entry, "=");
            env[i] = NULL; env[i] = new_entry; return env;
        } } char **new_env = malloc(sizeof(char *) * (i + 2));
    int j = 0; for (j = 0; j != i; j++) {
        new_env[j] = malloc(sizeof(char) * my_strlen(env[j]) + 1);
        new_env[j] = my_strcpy(new_env[j], env[j]);
    } new_env[j] = malloc(my_strlen(name) + 2);
    new_env[j] = my_strcpy(new_env[j], name);
    new_env[j] = my_strcat(new_env[j], "=");
    new_env[j][my_strlen(name) + 1] = '\0';
    new_env[j + 1] = NULL; free(env); return new_env;
}

char **unset_env(char **env, char *name)
{
    int nlen = my_strlen(name);
    if (env == NULL || name == NULL) {
        return env;
    } int exist = 0;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, nlen) != 1
        && env[i][nlen] == '=') {
            exist = 1;
        }
    } if (exist == 0) {
        return env;
    } int i_env = 0, i_newenv = 0;
    char **new_env = malloc(sizeof(char *) * (env_len(env)));
    for (i_env = 0; env[i_env] != NULL; i_env++) {
        if (my_strncmp(env[i_env], name, nlen) != 1) {
            new_env[i_newenv] = my_strdup(env[i_env]); i_newenv++;
        }
    } new_env[i_newenv] = NULL;
    free(env); return new_env;
}

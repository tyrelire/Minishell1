/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"

int cpt_lign_cpr(char **str)
{
    int cpt = 0;
    for (int k = 0; str[k] != NULL; k++) {
        cpt++;
    }
    return cpt;
}

char **turn_in(char **env)
{
    int i = 0;
    if (env == NULL) {
        env = malloc(sizeof(env) + 1);
        env[0] = my_strdup("PWD=");
        env[1] = my_strdup("HOME=");
        env[2] = NULL;
        return env;
    } else {
        char **array_env = malloc(sizeof(char *) * (cpt_lign_cpr(env) + 1));
        for (i = 0; env[i] != NULL; i++) {
            array_env[i] = my_strdup(env[i]);
        }
        array_env[i] = NULL;
        return array_env;
    }
}

char *my_getpath(char **env)
{
    int k = 0;
    char *strn = my_strdup("");
    for (k = 0; env[k] != NULL; k++) {
        if (my_strncmp(env[k], "PATH=", 5) == 1) {
            strn = my_str_cut(env[k], 5);
            break;
        }
    }
    return strn;
}

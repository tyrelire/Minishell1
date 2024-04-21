/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"

int cpt_lign_home(char **str)
{
    int cpt = 0;
    for (int k = 0; str[k] != NULL; k++) {
        cpt++;
    }
    return cpt;
}

char **turn_in_home(char **env)
{
    int i = 0;
    char **array_env = malloc(sizeof(char *) * (cpt_lign_cpr(env) + 1));
    for (i = 0; env[i] != NULL; i++) {
        array_env[i] = my_strdup(env[i]);
    }
    array_env[i] = NULL;
    return array_env;
}

char *my_getpath_home(char **env)
{
    char *strn;
    int k = 0, i = 5, l = 0;
    for (k = 0; env[k] != NULL; k++) {
        if (my_strncmp(env[k], "HOME=", 5) == 1) {
            strn = my_strdup(env[k]);
            break;
        }
    }
    char *strn2 = malloc(sizeof(char) * ((my_strlen(strn) + 1) - 5));
    while (strn[i] != '\0') {
        strn2[l] = strn[i];
        i++;
        l++;
    }
    strn2[l] = 0;
    return strn2;
}

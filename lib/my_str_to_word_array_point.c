/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** str_to_word_array.c
*/
#include "../include/my.h"

int cpt_col_point(char const *str, int index)
{
    int k = 0;
    while (str[k + index] != '\0' && str[k + index]
    != ':' && str[k + index] != '\n') {
        k++;
    }
    return k;
}

void help_lign_point(char const *str, int *b, int *k)
{
    while (str[*b] == ':' || str[*b] == '\n') {
        *k = 1; *b = *b + 1;
    }
}

int cpt_lign_point(char const *str)
{
    if (str[0] == '\0')
        return 0;
    int cpt = 1; int k = 0;
    for (int b = 0; str[b] != '\0'; b++) {
        k = 0;
        if (str[b] == ':' || str[b] == '\n') {
            cpt++;
            help_lign_point(str, &b, &k);
        } if (k == 1) {
            b = b - 1;
        }
    } if (str[0] == ':' || str[0] == '\n' ) {
        cpt--;
    } if (my_strlen(str) > 0 && (str[my_strlen(str) - 1] == ':' ||
    str[my_strlen(str) - 1] == '\n')) {
        cpt--;
    }
    return cpt;
}

char **my_str_to_word_array_point(char const *str)
{
    int i_str = 0; int i_tab = 0; int col = 0;
    char **tab = malloc(sizeof(char *) * (cpt_lign_point(str) + 1));
    while (i_tab < cpt_lign_point(str)) {
        while (str[i_str] == '\n' || str[i_str] == ':' ) {
            i_str++;
        }
        tab[i_tab] = malloc(sizeof(char) * (cpt_col_point(str, i_str) + 1));
        while (str[i_str] != ':' &&
        str[i_str] != '\0' && str[i_str] != '\n') {
            tab[i_tab][col] = str[i_str];
            i_str++;
            col++;
        }
        tab[i_tab][col] = '\0';
        i_tab++;
        col = 0;
    }
    tab[i_tab] = NULL;
    return tab;
}

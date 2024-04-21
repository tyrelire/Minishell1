/*
** EPITECH PROJECT, 2022
** my_put_tab.c
** File description:
** my_put_tab.c
*/
#include "../include/my.h"

int my_put_tab(char **tab)
{
    for (int k = 0; tab[k] != NULL; k++) {
        my_printf(tab[k]);
        my_printf("\n");
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char const *src)
{
    char *str;
    int x;
    x = 0;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[x] != '\0') {
        str[x] = src[x];
        x = x + 1;
    }
    str[x] = '\0';
    return (str);
}

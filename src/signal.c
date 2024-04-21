/*
** EPITECH PROJECT, 2022
** signal.c
** File description:
** signal
*/

#include "../include/my.h"

int signal_handler(int status, int cored)
{
    if (status == SIGSEGV) {
        my_putstr_err("Segmentation fault", 2);
    }
    if (status == SIGFPE) {
        my_putstr_err("Floating exception", 2);
    }
    if (cored != 0) {
        my_putstr_err(" (coredumped).", 2);
    }
    my_putchar_err('\n', 2);
    return (status + 128);
}

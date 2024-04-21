/*
** EPITECH PROJECT, 2022
** my
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <errno.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>


    typedef struct goof {
        int value;
    } sta_t;

    int env_len(char **env);
    char *my_str_cut(char *str, int k);
    int my_putchar_err(char c, int fd);
    int signal_handler(int status, int cored);
    char **execmd(char **argv, int argc, char **env, sta_t *p);
    char **help_execmd(char **argv, int argc, char **env, sta_t *p);
    char **unset_many(int argc, char **argv, char **env);
    char **unset_env(char **env, char *name);
    int my_fast_putstr(const char *s);
    int my_strlen(char const *str);
    int my_putstr_err(char const *str, int fd);
    int my_putchar(char c);
    int cd_command(int argc, char *cmd, char *cmd2, char **env);
    int my_isalnum(int c);
    int my_isalpha(int c);
    void exit_command(char *cmd);
    int is_valid_string(const char *str, sta_t *p);
    char **my_str_to_word_array(char const *str);
    char **set_env1(char **env, char *name, char *value, sta_t *p);
    char **set_env2(char **env, char *name, sta_t *p);
    char **my_str_to_word_array_point(char const *str);
    char **my_str_to_word_array_space(char const *str);
    int cpt_lign_space(char const *str);
    int cpt_col_space(char const *str, int index);
    int cpt_lign_point(char const *str);
    int my_putstr(const char *s);
    char **my_unsetenv(char *name, char **env);
    int array_len(char **argv);
    int cpt_col_point(char const *str, int index);
    int my_free_word_array(char **tab);
    int cpt_col(char const *str);
    int cpt_lign(char const *str);
    int my_fork_minishell(char **argv, char **env, char *cmd);
    char *my_strcat(char *dest, char *src);
    int my_put_tab(char **tab);
    char *verif_pos(char *cmd, char **env);
    char *my_strcpy(char *d, char const *s);
    int my_strcmp(char *s1, char *s2);
    int my_printf(const char *format, ...);
    unsigned int binaire(unsigned int number);
    int decimal_to_octal(int number);
    int into_hex_max(int number);
    int into_hex_min(int number);
    int my_putstr(char const *str);
    unsigned int non_sign(unsigned int nb);
    char *my_strdup(char const *src);
    int my_strlen(char const *str);
    int nprintable_char(char const *str);
    int my_put_nbr(int nb);
    int my_strncmp(char *str1, char *str2, int len);
    int my_putchar(char c);
    int my_put_tab(char **str);
    ssize_t my_fastput_array(char **tab);
    ssize_t my_fastput_array_v2(char **tab);
    int my_get_nbr(const char *str);
    int mini_shell(int argc, char **argv, char **env);
    char *my_getpath(char **env);
    int cpt_lign_cpr(char **str);
    char *my_getpath_home(char **env);
    int cpt_lign_home(char **str);
    int my_strncmp(char *str1, char *str2, int len);
    int mini_shell(int argc, char **argv, char **env);
    char **turn_in(char **env);
    char **turn_in_home(char **env);

#endif

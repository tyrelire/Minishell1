/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"

int my_fork_minishell(char **argv, char **env, char *cmd)
{
    int status = 0;
    pid_t pid = fork();
    argv[0] = verif_pos(argv[0], env);
    if (pid < 0) {
        my_putstr("Error : Failed fork");
    }
    if (pid == 0) {
        if (execve(argv[0], argv, env) == -1) {
            my_putstr_err(cmd, 2);
            my_putstr_err(": Command not found.\n", 2);
            exit(1);
        }
    } else
        waitpid(pid, &status, WUNTRACED);
    if (WIFSIGNALED(status))
        return signal_handler(WTERMSIG(status), WCOREDUMP(status));
    return (WEXITSTATUS(status));
}

char *verif_pos(char *cmd, char **env)
{
    char *str; char **tab = my_str_to_word_array_point(my_getpath(env));
    for (int k = 0; tab[k] != NULL; k++) {
        str = my_strcat(tab[k], "/");
        str = my_strcat(str, cmd);
        if (access(str, X_OK | F_OK) == 0)
            return str;
    }
    if (access(cmd, X_OK | F_OK) == 0) {
        return cmd;
    }
    return NULL;
}

int mini_shell(int argc, char **argv, char **env)
{
    sta_t *p;
    p = (sta_t*)malloc(sizeof(sta_t));
    p->value = 0;
    char *shell = "$> ";
    char *line = NULL; (void)argv;
    size_t n = 0; ssize_t nchars_read;
    while (1) {
        if (isatty(0)) {
            my_putstr(shell);
        }
        nchars_read = getline(&line, &n, stdin);
        if (nchars_read == -1) {
            (isatty(0)) ? my_putstr("exit") : 0;
            exit(p->value);
        }
        char **new_argv = my_str_to_word_array_space(line);
        argc = array_len(new_argv);
        env = execmd(new_argv, argc, env, p);
    } free(line);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    char **tab = turn_in(env);
    mini_shell(argc, argv, tab);
}

/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** minishell
*/

#include "solver.h"

int nb_height(char *str)
{
    int i = 0;
    int no_alpha = 1;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            no_alpha++;
    }
    return (no_alpha);
}

char **my_str_to_word_array(char *str)
{
    int x = 0;
    int y = 0;
    int i = 0;
    int nb_h = nb_height(str);
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (nb_h + 1));
    for (int i = 0; i <= nb_h; i += 1)
        tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            tab[y][x] = '\0';
            y++;
            x = 0;
        } else {
            tab[y][x] = str[i];
            x++;
        }
    }
    tab[y + 1] = NULL;
    return (tab);
}
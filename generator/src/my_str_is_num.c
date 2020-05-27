/*
** EPITECH PROJECT, 2020
** handling_error
** File description:
** dante
*/

#include "struct.h"

int my_str_is_num(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (84);
    }
    return (0);
}

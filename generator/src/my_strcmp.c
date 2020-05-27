/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** okok
*/

#include "struct.h"

int my_strcmp(char *str1, char *str2)
{
    int x = 0;

    while (str1[x] != '\0' || str2[x] != '\0') {
        if (str1[x] > str2[x])
            return (str1[x] - str2[x]);
        else if (str1[x] < str2[x])
            return (str1[x] - str2[x]);
        else
            x += 1;
    }
    return (0);
}

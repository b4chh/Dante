/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** okok
*/

#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

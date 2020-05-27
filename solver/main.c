/*
** EPITECH PROJECT, 2020
** main
** File description:
** solver
*/

#include "solver.h"

int main(int ac, char **av)
{
    solver_t cnd;
    int value = 0;

    if (ac != 2)
        return (84);
    if (read_file(av[1], &cnd) == 84)
        return (84);
    cnd.maze = NULL;
    parse_maze(&cnd);
    return (0);
}
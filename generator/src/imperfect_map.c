/*
** EPITECH PROJECT, 2019
** Dante's Star
** File description:
** create_imperfect_map.c
*/

#include "struct.h"

void put_other_path(gen_t *gen)
{
    int x = 2;
    int y = 2;

    if ((gen->sec_arg >= 4) && (gen->first_arg >= 4)) {
        while (gen->maze[y][x] != 'X')
            x++;
        gen->maze[y][x] = '*';
        gen->maze[y][x - 1] = '*';
        gen->maze[y + 1][x] = '*';
        gen->maze[y - 1][x] = '*';
        gen->maze[y - 1][x - 1] = '*';
        gen->maze[y + 1][x - 1] = '*';
    }
}

int imperfect_maze(gen_t *gen, cnd_t *cnd)
{
    if (init_maze(gen, cnd) == 1)
        return (1);
    put_other_path(gen);
    return (0);
}

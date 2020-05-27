/*
** EPITECH PROJECT, 2019
** Dante's Star
** File description:
** map.c
*/

#include "struct.h"

int set_maze(gen_t *gen, cnd_t *cnd)
{
    gen->maze[0][0] = '*';
    if (gen->rows_maze <= 2 && gen->cols_maze >= 3)
        return (1);
    if (gen->rows_maze > 3 && gen->cols_maze > 3) {
        put_lime(gen);
        gen->maze[0][0] = '*';
        make_track(gen, cnd);
    }
    return (0);
}

char **walls_maze(gen_t *gen)
{
    gen->cols_maze = gen->first_arg;
    gen->rows_maze = gen->sec_arg;

    gen->maze = malloc(sizeof(char *) * (gen->rows_maze + 1));
    if (gen->maze == NULL)
        return (NULL);
    gen->maze[gen->rows_maze] = NULL;
    for (int x = 0; x < gen->rows_maze; x += 1) {
        if ((gen->maze[x] =
        malloc(sizeof(char) * (gen->cols_maze + 1))) == NULL)
            return (NULL);
        for (int y = 0; y < gen->cols_maze; y += 1)
            gen->maze[x][y] = 'X';
        gen->maze[x][gen->cols_maze] = '\0';
    }
    return (gen->maze);
}

void display_maze(gen_t *gen)
{
    int y = 0;

    while (y < gen->cols_maze) {
        write(1, gen->maze[y], strlen(gen->maze[y]));
        if (y != gen->cols_maze - 1)
            write(1, "\n", 1);
        y += 1;
    }
}
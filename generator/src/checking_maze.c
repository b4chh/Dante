/*
** EPITECH PROJECT, 2019
** Dante's Star
** File description:
** free_struct.c
*/

#include "struct.h"

int get_error(gen_t *gen, int x, int y)
{
    if (x > 1 && y > 1 && y < (gen->rows_maze - 2) && x < (gen->cols_maze - 2)
        && gen->maze[y - 2][x] != '0'
        && gen->maze[y + 2][x] != '0'
        && gen->maze[y][x - 2] != '0'
        && gen->maze[y][x + 2] != '0')
        return (-1);
    return (0);
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    if (array != NULL)
        free(array);
}

void free_struct(gen_t *gen)
{
    free_array(gen->maze);
    free(gen);
}

cnd_t *put_new_cnd(cnd_t *cnd, int x, int y)
{
    cnd_t *new_cnd = NULL;

    new_cnd = malloc(sizeof(cnd_t));
    new_cnd->x = x;
    new_cnd->y = y;
    new_cnd->next = cnd;
    return (new_cnd);
}

int verif_side(gen_t *gen, int x, int y)
{
    if ((x <= 1 && y <= 1 && gen->maze[y + 2][x] != '0' && gen->maze[y][x + 2] != '0')
        || (x >= (gen->cols_maze - 2) && y >= (gen->rows_maze - 2)
            && gen->maze[y - 2][x] != '0' && gen->maze[y][x - 2] != '0')
        || (x <= 1 && y >= (gen->rows_maze - 2) && gen->maze[y - 2][x] != '0'
            && gen->maze[y][x + 2] != '0')
        || (x >= (gen->cols_maze - 2) && y <= 1 && gen->maze[y + 2][x] != '0'
            && gen->maze[y][x - 2] != '0')
        || (x > 1 && x < (gen->cols_maze - 2) && y <= 1
            && gen->maze[y + 2][x] != '0'
            && gen->maze[y][x - 2] != '0' && gen->maze[y][x + 2] != '0')
        || (x > 1 && x < (gen->cols_maze - 2) && y >= (gen->rows_maze - 2)
            && gen->maze[y - 2][x] != '0' && gen->maze[y][x - 2] != '0'
            && gen->maze[y][x + 2] != '0')
        || (x <= 1 && y < (gen->rows_maze - 2) && y > 1
            && gen->maze[y - 2][x] != '0' && gen->maze[y][x + 2] != '0'
            && gen->maze[y + 2][x] != '0')
        || (x >= (gen->cols_maze - 2) && y < (gen->rows_maze - 2) && y > 1
            && gen->maze[y - 2][x] != '0' && gen->maze[y][x - 2] != '0'
            && gen->maze[y + 2][x] != '0'))
        return (-1);
    return (0);
}
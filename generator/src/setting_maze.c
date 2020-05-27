/*
** EPITECH PROJECT, 2019
** Dante's Star
** File description:
** create_perfect_map.c
*/

#include "struct.h"

cnd_t *erase_node(cnd_t *cnd)
{
    cnd_t *tmp = cnd;

    if (cnd == NULL)
        return (NULL);
    cnd = cnd->next;
    free(tmp);
    return (cnd);
}

void put_lime(gen_t *gen)
{
    for (int y = 0; y < gen->rows_maze; y += 2)
        for (int x = 0; x < gen->cols_maze; x += 2)
            gen->maze[y][x] = '0';
}

int verif_limit(gen_t *gen, int rows, int cols)
{
    int a = 0;

    while (1) {
        if ((rows - 2 >= 0 || cols - 2 >= 0)
        || (cols + 2 <= (gen->rows_maze - 1) || rows + 2 <= (gen->cols_maze - 1))) {
            a = rand() % 4;
            if (cols - 2 >= 0 && gen->maze[cols - 2][rows] == '0' && a == 0)
                return (0);
            if (rows - 2 >= 0 && gen->maze[cols][rows - 2] == '0' && a == 1)
                return (1);
            if (cols + 2 <= (gen->rows_maze - 1) && gen->maze[cols + 2][rows] == '0' && a == 2)
                return (2);
            if (rows + 2 <= (gen->cols_maze - 1) && gen->maze[cols][rows + 2] == '0' && a == 3)
                return (3);
        }
        if (verif_side(gen, rows, cols) == -1)
            return (-1);
        if (get_error(gen, rows, cols) == -1)
            return (-1);
    }
}

void make_track(gen_t *gen, cnd_t *cnd)
{
    int i = 0, rows = 0, cols = 0;

    srand(time(NULL));
    for (;cnd != NULL;) {
        i = verif_limit(gen, cols, rows);
        if (i == 0) {
            rows -= 2;
            cnd = put_new_cnd(cnd, cols, rows);
            gen->maze[cnd->y + 1][cnd->x] = '*';
        }
        if (i == 1) {
            cols -= 2;
            cnd = put_new_cnd(cnd, cols, rows);
            gen->maze[cnd->y][cnd->x + 1] = '*';
        }
        if (i == 2) {
            rows += 2;
            cnd = put_new_cnd(cnd, cols, rows);
            gen->maze[cnd->y - 1][cnd->x] = '*';
        }
        if (i == 3) {
            cols += 2;
            cnd = put_new_cnd(cnd, cols, rows);
            gen->maze[cnd->y][cnd->x - 1] = '*';
        }
        gen->maze[cnd->y][cnd->x] = '*';
        if (i == -1) {
            cnd = erase_node(cnd);
            if (cnd != NULL) {
                cols = cnd->x;
                rows = cnd->y;
            }
        }
    }
}

int init_maze(gen_t *gen, cnd_t *cnd)
{
    walls_maze(gen);

    cnd = put_new_cnd(cnd, 0, 0);
    gen->maze[0][0] = '*';
    set_maze(gen, cnd);
    gen->maze[gen->rows_maze - 1][gen->cols_maze - 1] = '*';
    if (gen->cols_maze > 1 && gen->rows_maze >= 2)
        gen->maze[gen->rows_maze - 1][gen->cols_maze - 2] = '*';
    return (0);
}
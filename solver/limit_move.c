/*
** EPITECH PROJECT, 2020
** limite_move
** File description:
** dante
*/

#include "solver.h"

int limit_side_l(solver_t *cnd)
{
    if (cnd->maze[cnd->y - 1][cnd->x] == '*') {
        cnd->y--;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (1);
    } else if (cnd->maze[cnd->y][cnd->x + 1] == '*') {
        cnd->x++;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (2);
    } else {
        int i = 0;
    }
}

int limit_side_r(solver_t *cnd)
{
    if (cnd->maze[cnd->y - 1][cnd->x] == '*') {
        cnd->y--;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (1);
    } else if (cnd->maze[cnd->y][cnd->x - 1] == '*') {
        cnd->x--;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (2);
    } else {
        int i = 0;
    }
}

int limit_side_up(solver_t *cnd)
{
    if (cnd->maze[cnd->y - 1][cnd->x] == '*') {
        cnd->y--;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (1);
    } else if (cnd->maze[cnd->y][cnd->x - 1] == '*') {
        cnd->x--;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (2);
    } else {
        int i = 0;
    }
}

int limit_side_down(solver_t *cnd)
{
    if (cnd->maze[cnd->y + 1][cnd->x] == '*') {
        cnd->y++;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (1);
    } else if (cnd->maze[cnd->y][cnd->x - 1] == '*') {
        cnd->x--;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (2);
    } else {
        int i = 0;
    }
}

int limit_side(solver_t *cnd)
{
    if ((cnd->y == cnd->height) && cnd->x >= 1 && cnd->x <= cnd->width - 1)
        limit_side_down(cnd);
    if ((cnd->y == 0) && cnd->x >= 1 && cnd->x <= cnd->width - 1)
        limit_side_up(cnd);
    if ((cnd->x == cnd->width - 1)
    && (cnd->y >= 1 && cnd->y <= cnd->height - 1))
        limit_side_r(cnd);
    if ((cnd->x == 0) && cnd->y >= 1 && cnd->y <= cnd->height - 1)
        limit_side_l(cnd);
}

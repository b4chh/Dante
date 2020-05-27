/*
** EPITECH PROJECT, 2020
** check_all_way
** File description:
** dante
*/

#include "solver.h"

int check_way(solver_t *cnd)
{
    if (cnd->maze[cnd->y][cnd->x + 1] == '*') {
        cnd->x++;
        cnd->visited[cnd->y][cnd->x] = 'o';
    } else if (cnd->maze[cnd->y + 1][cnd->x] == '*') {
        cnd->y++;
        cnd->visited[cnd->y][cnd->x] = 'o';
    }
    if (cnd->maze[cnd->y + 1][cnd->x] != '*'
    || cnd->maze[cnd->y][cnd->x + 1] != '*')
        return (-1);
}

int choice_dir(solver_t *cnd)
{
    if (cnd->maze[cnd->y][cnd->x + 1] == '*') {
        cnd->x++;
        cnd->visited[cnd->y][cnd->x] = 'o';
    } else if (cnd->maze[cnd->y - 1][cnd->x] == '*') {
        cnd->y--;
        cnd->visited[cnd->y][cnd->x] = 'o';
    }
}

int other_dir(solver_t *cnd)
{
    if (cnd->maze[cnd->y][cnd->x - 1] == '*') {
        cnd->x--;
        cnd->visited[cnd->y][cnd->x] = 'o';
    } else if (cnd->maze[cnd->y + 1][cnd->x] == '*') {
        cnd->y++;
        cnd->visited[cnd->y][cnd->x] = 'o';
    }
}

int move_all_dir(solver_t *cnd)
{
    if (cnd->maze[cnd->y - 1][cnd->x] == '*') {
        cnd->y--;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (1);
    }
    if (cnd->maze[cnd->y][cnd->x - 1] == '*') {
        cnd->x--;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (2);
    }
    if (cnd->maze[cnd->y][cnd->x + 1] == '*') {
        cnd->x++;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (3);
    }
    if (cnd->maze[cnd->y + 1][cnd->x] == '*') {
        cnd->y++;
        cnd->visited[cnd->y][cnd->x] = 'o';
        return (4);
    }
}

int find_way(solver_t *cnd)
{
    cnd->x = 0;
    cnd->y = 0;

    for (; cnd->y < cnd->height; cnd->y += 1, cnd->x = 0) {
        while (cnd->x < cnd->width) {
            if (cnd->x == 0 && cnd->y == 0) {
                if (check_way(cnd) == -1)
                    return -1;
            }
            limit_side(cnd);
            if ((cnd->x >= 1 && cnd->y >= 1)
            && cnd->x != cnd->width && cnd->y != cnd->height)
                move_all_dir(cnd);
            if (cnd->x == cnd->width - 1 && cnd->y == 0)
                choice_dir(cnd);
            if (cnd->x == 0 && cnd->y == cnd->height - 1)
                other_dir(cnd);
        }
    }
}
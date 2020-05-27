/*
** EPITECH PROJECT, 2020
** algorithm
** File description:
** dante
*/

#include "solver.h"

int parse_maze(solver_t *cnd)
{
    int x = 0;
    int y = 0;

    cnd->maze = my_str_to_word_array(cnd->buffer);
    display_maze(cnd);
    free(cnd->buffer);
}

int add_path(solver_t *cnd)
{
    int x = 0;
    int y = 0;

    for (; y < cnd->height; y += 1, x = 0) {
        for (; x < cnd->width; x++) {
            if (y != 0 && x != 0) {
                if (cnd->visited[y][x] == path)
                    cnd->maze[y][x] = 'o';
            }
        }
    }
}

void display_maze(solver_t *cnd)
{
    int x = 0;
    int y = 0;

    while (cnd->maze[y] != NULL) {
        while (cnd->maze[y][x] != '\0') {
            my_putchar(cnd->maze[y][x]);
            x++;
        }
        my_putchar('\n');
        x = 0;
        y += 1;
    }
}

int take_size(solver_t *cnd)
{
    int y = 0;
    int x = 0;

    for (; cnd->maze[y] != NULL; y += 1);
    cnd->height = y;
    for (int i = 0; cnd->maze[i] != NULL; i += 1, x = 0) {
        for (; cnd->maze[i][x] != '\0'; x++);
        cnd->width = x;
    }
}

void check_visited(solver_t *cnd)
{
    int x = 0;
    int y = 0;

    cnd->visited = malloc(sizeof(int) * (cnd->height + 1));
    for (int y = 0; y < cnd->height; y += 1)
        cnd->visited[y] = malloc(sizeof(int)  * (cnd->width + 1));
    for (; cnd->maze[y] != NULL; y += 1, x = 0) {
        for (; cnd->maze[y][x] != '\0'; x++) {
            if (cnd->maze[y][x] == 'X')
                cnd->visited[y][x] = wall;
            else if (y == cnd->height - 1 && x == cnd->width - 1)
                cnd->visited[y][x] = goal;
            else
                cnd->visited[y][x] = free_space;
        }
    }
}

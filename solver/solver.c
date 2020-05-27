/*
** EPITECH PROJECT, 2020
** solver
** File description:
** dante
*/

#include "solver.h"

int error_handling(solver_t *cnd)
{
    for (int x = 0; cnd->buffer[x] != '\0'; x++) {
        if (cnd->buffer[x] != '*' && cnd->buffer[x] != 'X'
        && cnd->buffer[x] != '\n')
            return (84);
    }
}

int read_file(char const *filepath, solver_t *cnd)
{
    struct stat stats;
    stat(filepath, &stats);
    int i = stats.st_size;
    int fd = open(filepath, O_RDONLY);
    cnd->buffer = malloc(sizeof(char *) * i + 1);
    cnd->buffer[i + 1] = '\0';
    int sread = read(fd, cnd->buffer, i);
    if (fd == -1 || sread == -1)
        return (84);
    if (error_handling(cnd) == 84)
        return (84);
    close(fd);
}
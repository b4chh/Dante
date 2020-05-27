/*
** EPITECH PROJECT, 2019
** Dante's Star
** File description:
** main.c
*/

#include "struct.h"

int check_error(gen_t *gen, int ac, char **av)
{
    if (ac != 4 && ac != 3)
        return (84);
    gen->first_arg = atoi(av[1]);
    gen->sec_arg = atoi(av[2]);
    if (my_str_is_num(av[1]) != 0 || my_str_is_num(av[2]) != 0)
        return (84);
    return (0);
}

int maze_selection(gen_t *gen, cnd_t *cnd, int ac, char **av)
{
    gen->maze = NULL;
    if (ac == 4 && my_strcmp(av[3], "perfect") == 0) {
        if (init_maze(gen, cnd) == 1)
            return (1);
    } else if (ac == 4 && my_strcmp(av[3], "perfect") != 0)
        return (84);
    if (ac == 3) {
        if (imperfect_maze(gen, cnd) == 1)
            return 1;
    }
    return (0);
}

int main(int ac, char **av)
{
    cnd_t *cnd = NULL;
    gen_t *gen = malloc(sizeof(gen_t));

    if (check_error(gen, ac, av) == 84)
        return (84);
    if (maze_selection(gen, cnd, ac, av) == 84)
        return (84);
    display_maze(gen);
    free_struct(gen);
    return (0);
}
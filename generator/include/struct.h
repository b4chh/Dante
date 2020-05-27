/*
** EPITECH PROJECT, 2019
** struct
** File description:
** dante
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct gen_s
{
    int cols_maze;
    int rows_maze;
    int first_arg;
    char **maze;
    int sec_arg;
} gen_t;

typedef struct cnd_s
{
    int x;
    int y;
    struct cnd_s *next;
} cnd_t;

void display_maze(gen_t *gen);
int imperfect_maze(gen_t *gen, cnd_t *cnd);
int set_maze(gen_t *gen, cnd_t *cnd);
int init_maze(gen_t *gen, cnd_t *cnd);
int verif_limit(gen_t *gen, int rows, int cols);
cnd_t *put_new_cnd(cnd_t *cnd, int x, int y);
char **walls_maze(gen_t *gen);
void put_lime(gen_t *gen);
int verif_side(gen_t *gen, int x, int y);
int get_error(gen_t *gen, int x, int y);
cnd_t *erase_node(cnd_t *cnd);
void free_struct(gen_t *gen);
int my_strcmp(char *str1, char *str2);
int my_str_is_num(char *str);
int check_error(gen_t *gen, int ac, char **av);
int maze_selection(gen_t *gen, cnd_t *cnd, int ac, char **av);
void put_other_path(gen_t *gen);
void make_track(gen_t *gen, cnd_t *cnd);

#endif /* STRUCT_H */

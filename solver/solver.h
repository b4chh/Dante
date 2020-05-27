/*
** EPITECH PROJECT, 2020
** solver
** File description:
** structure
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct solver_s
{
    int x;
    int y;
    int height;
    int width;
    char **maze;
    char *buffer;
    int **visited;
} solver_t;

enum choice {
    free_space,
    wall,
    goal,
    path,
};

int limit_side_down(solver_t *cnd);
int limit_side_up(solver_t *cnd);
int limit_side_r(solver_t *cnd);
int limit_side_l(solver_t *cnd);
int limit_side(solver_t *cnd);
int check_way(solver_t *cnd);
int find_way(solver_t *cnd);
int add_path(solver_t *cnd);
void display_maze(solver_t *cnd);
void check_visited(solver_t *cnd);
int parse_maze(solver_t *cnd);
int take_size(solver_t *cnd);
int error_handling(solver_t *cnd);
int open_maze(char **av);
void my_putchar(char c);
int my_strlen(char *str);
int read_file(char const *filepath, solver_t *cnd);
char **my_str_to_word_array(char *str);
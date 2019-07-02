/*
** EPITECH PROJECT, 2019
** solver.h
** File description:
** .h
*/

#include <stdbool.h>
#include <stdio.h>

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct maze_s
{
    char **map;
    char **was_here;
    char **correct_path;
    int end_x;
    int end_y;
} maze_t;


///* SOLVER.C *///
bool recursive(maze_t *maze, int x, int y);
void my_solver(char *file);

///* MAZE.C *///
char **create_maze(char *file);

#endif /* !SOLVER_H_ */

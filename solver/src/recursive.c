/*
** EPITECH PROJECT, 2019
** recursive.c
** File description:
** recursive solve
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "solver.h"

bool recursive2(maze_t *maze, int x, int y)
{
    if (x != (maze->end_x - 1)) {
        if (recursive(maze, x + 1, y)) {
            maze->correct_path[y][x] = '2';
            return (true);
        }
    }
    if (y != 0)  {
        if (recursive(maze, x, y - 1)) {
            maze->correct_path[y][x] = '2';
            return (true);
        }
    }
    if (y != (maze->end_y - 1)) {
        if (recursive(maze, x, y + 1)) {
            maze->correct_path[y][x] = '2';
            return (true);
        }
    }
    return (false);
}

bool recursive(maze_t *maze, int x, int y)
{
    if (x == maze->end_x - 1 && y == maze->end_y - 1) {
        return (true);
    }
    if (maze->map[y][x] == 'X' || maze->was_here[y][x] == '2') {
        return (false);
    }
    maze->was_here[y][x] = '2';
    if (x != 0) {
        if (recursive(maze, x - 1, y)) {
            maze->correct_path[y][x] = '2';
            return (true);
        }
    }
    return (recursive2(maze, x, y));
}

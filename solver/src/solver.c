/*
** EPITECH PROJECT, 2019
** solver.c
** File description:
** solve the maze
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "solver.h"

maze_t *maze_structure(char *file)
{
    maze_t *maze = malloc(sizeof(maze_t));
    char **maze_map = create_maze(file);
    char **here = create_maze(file);
    char **path = create_maze(file);
    int i = 0;
    int j = 0;

    for (i = 0; here[i] != NULL; i++) {
        for (j = 0; here[i][j] != '\0'; j++) {
            here[i][j] = '1';
            path[i][j] = '1';
        }
    }
    maze->map = maze_map;
    maze->end_x = j;
    maze->end_y = i;
    maze->correct_path = path;
    maze->was_here = here;
    return (maze);
}

char *solved_str(maze_t *maze)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    char *str = NULL;

    for (i = 0; maze->map[i] != NULL; i++);
    for (j = 0; maze->map[0][j] != '\0'; j++);
    count = ((i + 1) * j) + 1;
    str = malloc(sizeof(char) * count);
    for (i = 0; maze->correct_path[i] != NULL; i++) {
        if (i != 0)
            k++;
        for (j = 0; maze->correct_path[i][j] != '\0'; j++, k++)
            str[k] = maze->correct_path[i][j];
        str[k] = '\n';
    }
    str[k] = '\0';
    return (str);
}

void print_solved_maze(maze_t *maze)
{
    int i = 0;
    int j = 0;
    char *str = NULL;
    for (i = 0; maze->correct_path[i] != NULL; i++) {
        for (j = 0; maze->correct_path[i][j] != '\0'; j++) {
            if (maze->correct_path[i][j] == '2')
                maze->correct_path[i][j] = 'o';
            else
            maze->correct_path[i][j] = maze->map[i][j];
        }
    }
    maze->correct_path[i- 1][j- 1] = 'o';
    str = solved_str(maze);
    printf("%s", str);
}

void my_solver(char *file)
{
    maze_t *maze = maze_structure(file);
    int x = 0;
    int y = 0;
    bool i = true;

    i = recursive(maze, x, y);

    if (i == false)
        printf("no solution found");
    else
        print_solved_maze(maze);
}
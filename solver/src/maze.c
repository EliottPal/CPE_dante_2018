/*
** EPITECH PROJECT, 2019
** maze.c
** File description:
** mazes
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "solver.h"

char **fill_maze(char **maze, char *file, int lines)
{
    FILE *fd = fopen(file, "r");
    char *buffer = NULL;
    size_t len = 0;
    int line_len = 0;
    int count = 0;
    int i = 0;

    for (count = 0; count != lines; count++) {
        getline(&buffer, &len, fd);
        line_len = strlen(buffer) - 1;
        if (buffer[line_len] != '\n')
            line_len++;
        maze[count] = malloc(sizeof(char) * (line_len + 1));
        memset(maze[count], 0, line_len + 1);
        for (i = 0; i != line_len; i++)
            maze[count][i] = buffer[i];
    }
    maze[count] = NULL;
    fclose(fd);
    return (maze);
}

char **create_maze(char *file)
{
    FILE *fd = fopen(file, "r");
    size_t len = 0;
    int count = 0;
    char *buffer = NULL;
    char **maze;

    for (count = 0; getline(&buffer, &len, fd) != -1; count++);
    fclose(fd);
    maze = malloc(sizeof(char *) * (count + 1));

    fill_maze(maze, file, count);
    return (maze);
}
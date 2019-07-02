/*
** EPITECH PROJECT, 2019
** main
** File description:
** main function for solver
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "solver.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        printf("You must specify a file \n");
        return (84);
    }
    if (ac > 2) {
        printf("Only one argument is needed\n");
        return (84);
    }
    if (open(av[1], O_RDONLY) == -1) {
        printf("Can't open map\n");
        return (84);
    }
    my_solver(av[1]);
    return (0);
}

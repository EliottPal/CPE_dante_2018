/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../inc/generator.h"

int error_generator(int ac, char **av)
{
    int i = 0;

    if (ac < 3 || ac > 4) {
        printf("we need coordinate!\n");
        return (84);
    }

    for (i = 0; av[1][i] != '\0'; i++) {
    if (av[1][i] < '0' || av[1][i] > '9')
        return (84);
    }
    i = 0;
    for (i = 0; av[2][i] != '\0'; i++) {
    if (av[2][i] < '0' || av[2][i] > '9')
        return (84);
    }

    return (0);
}

int main(int ac, char **av)
{
    srand(time(NULL));

    if (error_generator(ac, av) == 84)
        return (84);

    if (ac == 4) {
        if (strcmp(av[3], "perfect") == 0) {
            my_generator_perfect(av);
        }
    }
    else if (ac == 3)
            my_generator_imperfect(av);
    else
        return (84);
}
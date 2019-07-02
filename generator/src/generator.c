/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generate mazes
*/

#include "../inc/generator.h"

char **my_generator(gene_t *gene)
{
    for (int j = 0; j < gene->y; j++) {
        for (int i = 0; i < gene->x; i++) {
            gene->array[j][i] = 'X';
        }
    }
    for (int i = 0; i < gene->x; i++)
        gene->array[0][i] = '*';
    for (int j = 0; j < gene->y; j++)
        gene->array[j][0] = '*';

    gene->array[gene->y - 1][gene->x - 1] = '*';

    return (gene->array);
}

char **malloc_array(char **av, gene_t *gene)
{
    int i = 0;

    gene->array = malloc(sizeof(char *) * atoi(av[1]));

    for (i = 0; i != atoi(av[1]); i++)
        gene->array[i] = malloc(sizeof(char) * atoi(av[2]) + 1);

    return (gene->array);
}

void my_generator_perfect(char **av)
{
    gene_t *gene = malloc(sizeof(gene_t));
    gene->array = malloc_array(av, gene);
    gene->x = atoi(av[1]);
    gene->y = atoi(av[2]);
    int k = 0;

    my_generator(gene);
    algorithm(gene);

    for (k = 0; k != gene->y - 1; k++) {
        printf("%s\n", gene->array[k]);
    }
    printf("%s", gene->array[k]);
}

void my_generator_imperfect(char **av)
{
    gene_t *gene = malloc(sizeof(gene_t));
    gene->array = malloc_array(av, gene);
    gene->x = atoi(av[1]);
    gene->y = atoi(av[2]);
    int k = 0;

    my_generator(gene);
    algorithm(gene);

    for (int j = 0; j < gene->y; j++) {
        for (int i = 0; i < gene->x; i++) {
            algorithm_imperfect(i, j, gene);
        }
    }

    for (k = 0; k != gene->y - 1; k++) {
        printf("%s\n", gene->array[k]);
    }
    printf("%s", gene->array[k]);
}
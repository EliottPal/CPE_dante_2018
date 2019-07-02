/*
** EPITECH PROJECT, 2019
** algo
** File description:
** algo
*/

#include "../inc/generator.h"

void algorithm_imperfect(int i, int j, gene_t  *gene)
{
    int random = rand() % (gene->x * 10);

    if (random == 0) {
        gene->array[j][i] = '*';
    }
    gene->array[1][2] = '*';
    gene->array[2][2] = '*';
    gene->array[2][1] = '*';
}

void algorithm_next(int i, int j, gene_t *gene)
{
    int random = rand() % 2;

    if (random == 0) {
        gene->array[j][i] = '*';
        gene->array[j - 1][i] = '*';
    }
    else {
        gene->array[j][i] = '*';
        gene->array[j][i - 1] = '*';
    }
}

void algorithm(gene_t *gene)
{
    for (int j = 2; j < gene->y; j += 2) {
        for (int i = 2; i < gene->x; i += 2) {
            algorithm_next(i, j, gene);
        }
    }
    int random = rand() % 2;

    if (random == 0) {
        gene->array[gene->y - 2][gene->x - 1] = '*';
    }
    else {
        gene->array[gene->y - 1][gene->x - 2] = '*';
    }
}
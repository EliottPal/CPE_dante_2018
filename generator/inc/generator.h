/*
** EPITECH PROJECT, 2019
** generator.h
** File description:
** .h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structure.h"

#ifndef GENERATOR_H_
#define GENERATOR_H_

int main(int ac, char **av);
void my_generator_imperfect(char **av);
void my_generator_perfect(char **av);
void algorithm(gene_t *gene);
void algorithm_imperfect(int i, int j, gene_t  *gene);
void  my_putchar(char c);

#endif /* !GENERATOR_H_ */

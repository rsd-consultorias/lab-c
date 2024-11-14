#pragma once
#ifndef GAUSS_ELIMINATION_H
#define GAUSS_ELIMINATION_H

#include <stdio.h>
#include <math.h>

// Função para eliminação de Gauss
void gaussElimination(int n, double matrix[n][n+1], double x[]);

#endif // GAUSS_ELIMINATION_H

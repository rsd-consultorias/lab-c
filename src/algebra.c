#include <stdio.h>
#include <math.h>

void gaussElimination(int n, double matrix[n][n+1], double x[]) {
    
    for (int i = 0; i < n; i++) {
        // Pivotamento parcial
        double maxEl = fabs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > maxEl) {
                maxEl = fabs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Troca de linhas
        for (int k = i; k < n + 1; k++) {
            double tmp = matrix[maxRow][k];
            matrix[maxRow][k] = matrix[i][k];
            matrix[i][k] = tmp;
        }

        // Eliminação
        for (int k = i + 1; k < n; k++) {
            double c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; j++) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += c * matrix[i][j];
                }
            }
        }
    }

    // Substituição retroativa
    for (int i = n - 1; i >= 0; i--) {
        x[i] = matrix[i][n] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--) {
            matrix[k][n] -= matrix[k][i] * x[i];
        }
    }
}

int teste() {
    int n = 2; // Número de equações
    double matrix[2][3] = {
        {2.061, -0.354, 1.0},
        {-0.354, 1.061, 0.0}
    };
    double x[3];

    gaussElimination(n, matrix, x);

    printf("Soluções: ");
    for (int i = 0; i < n; i++) {
        printf("%lf ", x[i]);
    }
    printf("\n");

    return 0;
}

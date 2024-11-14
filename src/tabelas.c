#include "tabelas.h"

Coeficientes LAJES_COEFICIENTE_ALFA[NUM_LAMBDA] = {
    {1.00, {4.76, 3.26, 3.26, 2.46, 2.25, 2.25, 1.84, 1.84, 1.49}},
    {1.05, {5.26, 3.68, 3.48, 2.72, 2.60, 2.35, 2.08, 1.96, 1.63}},
    {1.10, {5.74, 4.11, 3.70, 2.96, 2.97, 2.45, 2.31, 2.08, 1.77}},
    {1.15, {6.20, 4.55, 3.89, 3.18, 3.35, 2.53, 2.54, 2.18, 1.90}},
    {1.20, {6.64, 5.00, 4.09, 3.40, 3.74, 2.61, 2.77, 2.28, 2.02}},
    {1.25, {7.08, 5.44, 4.26, 3.61, 4.14, 2.68, 3.00, 2.37, 2.14}},
    {1.30, {7.49, 5.88, 4.43, 3.80, 4.56, 2.74, 3.22, 2.46, 2.24}},
    {1.35, {7.90, 6.32, 4.58, 3.99, 5.01, 2.77, 3.42, 2.53, 2.34}},
    {1.40, {8.29, 6.74, 4.73, 4.15, 5.41, 2.80, 3.62, 2.61, 2.41}},
    {1.45, {8.67, 7.15, 4.87, 4.31, 5.83, 2.85, 3.80, 2.67, 2.49}},
    {1.50, {9.03, 7.55, 5.01, 4.46, 6.25, 2.89, 3.98, 2.73, 2.56}},
    {1.55, {9.39, 7.95, 5.09, 4.61, 6.66, 2.91, 4.14, 2.78, 2.62}},
    {1.60, {9.71, 8.32, 5.18, 4.73, 7.06, 2.92, 4.30, 2.82, 2.68}},
    {1.65, {10.04, 8.68, 5.22, 4.86, 7.46, 2.92, 4.45, 2.83, 2.73}},
    {1.70, {10.34, 9.03, 5.26, 4.97, 7.84, 2.93, 4.59, 2.84, 2.77}},
    {1.75, {10.62, 9.36, 5.36, 5.06, 8.21, 2.93, 4.71, 2.86, 2.81}},
    {1.80, {10.91, 9.69, 5.46, 5.16, 8.58, 2.94, 4.84, 2.88, 2.85}},
    {1.85, {11.16, 10.00, 5.53, 5.25, 8.93, 2.94, 4.96, 2.90, 2.88}},
    {1.90, {11.41, 10.29, 5.60, 5.33, 9.25, 2.95, 5.07, 2.92, 2.90}},
    {1.95, {11.65, 10.58, 5.68, 5.41, 9.58, 2.95, 5.17, 2.94, 2.93}},
    {2.00, {11.89, 10.87, 5.76, 5.49, 9.90, 2.96, 5.28, 2.96, 2.96}},
    {0.00, {15.63, 15.63, 6.50, 6.50, 15.63, 3.13, 6.50, 3.13, 3.13}}};

Coeficientes27 LAJES_REACOES_APOIO_CARGA_UNIFORME[NUM_LAMBDA] = {
    //      0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25
    {1.00, {2.50, 2.50, 1.83, 2.75, 4.02, 2.75, 4.02, 1.83, 1.00, 2.17, 3.17, 2.17, 3.17, 1.44, 3.56, 3.56, 1.44, 1.00, 1.71, 1.05, 1.79, 1.10, 1.71, 2.50, 2.50, 2.50}},
    {1.05, {2.62, 2.50, 1.92, 2.80, 4.10, 2.82, 4.13, 1.83, 1.05, 2.27, 3.32, 2.17, 3.17, 1.52, 3.66, 3.63, 1.44, 1.88, 1.15, 1.96, 1.20, 2.05, 1.71, 2.50, 2.62, 2.50}},
    {1.10, {2.73, 2.50, 2.01, 2.85, 4.17, 2.89, 4.23, 1.83, 1.10, 2.36, 3.46, 2.17, 3.17, 1.59, 3.75, 3.69, 1.44, 1.25, 2.13, 1.30, 2.22, 1.35, 1.71, 2.50, 2.73, 2.50}},
    {1.15, {2.83, 2.50, 2.10, 2.88, 4.22, 2.95, 4.32, 1.83, 1.15, 2.45, 3.58, 2.17, 3.17, 1.66, 3.84, 3.74, 1.44, 2.30, 1.40, 2.37, 1.45, 2.44, 1.71, 2.50, 2.83, 2.50}},
    {1.20, {2.92, 2.50, 2.20, 2.91, 4.27, 3.01, 4.41, 1.83, 1.20, 2.53, 3.70, 2.17, 3.17, 1.73, 3.92, 3.80, 1.44, 1.50, 2.50, 1.55, 2.56, 1.60, 1.71, 2.50, 2.92, 2.50}},
    {1.25, {3.00, 2.50, 2.29, 2.94, 4.30, 3.06, 4.48, 1.83, 1.25, 2.60, 3.80, 2.17, 3.17, 1.80, 3.99, 3.85, 1.44, 2.61, 1.65, 2.67, 1.70, 2.72, 1.71, 2.50, 3.00, 2.50}},
    {1.30, {3.08, 2.50, 2.38, 2.95, 4.32, 3.11, 4.55, 1.83, 1.30, 2.63, 3.90, 2.17, 3.17, 1.88, 4.06, 3.89, 1.44, 1.75, 2.76, 1.80, 2.80, 1.85, 1.71, 2.50, 3.08, 2.50}},
    {1.35, {3.15, 2.50, 2.47, 2.96, 4.33, 3.16, 4.62, 1.83, 1.35, 2.73, 3.99, 2.17, 3.17, 1.95, 4.12, 3.93, 1.44, 2.85, 1.90, 2.89, 1.95, 2.92, 1.71, 2.50, 3.15, 2.50}},
    {1.40, {3.21, 2.50, 2.56, 2.96, 4.33, 3.20, 4.68, 1.83, 1.40, 2.78, 4.08, 2.17, 3.17, 2.02, 4.17, 3.97, 1.44, 2.00, 2.96, 2.00, 4.38, 2.50, 1.71, 2.50, 3.21, 2.50}},
    {1.45, {3.28, 2.50, 2.64, 2.96, 4.33, 3.24, 4.74, 1.83, 1.45, 2.84, 4.15, 2.17, 3.17, 2.09, 4.22, 4.00, 1.44, 3.03, 3.03, 2.63, 3.08, 3.12, 1.71, 2.50, 3.28, 2.50}},
    {1.50, {3.33, 2.50, 2.72, 2.96, 4.33, 3.27, 4.79, 1.83, 1.50, 2.89, 4.23, 2.17, 3.17, 2.17, 4.25, 4.04, 1.44, 2.75, 3.11, 3.21, 2.88, 3.14, 1.71, 2.50, 3.33, 2.50}},
    {1.55, {3.39, 2.50, 2.80, 2.96, 4.33, 3.31, 4.84, 1.83, 1.55, 2.93, 4.29, 2.17, 3.17, 2.24, 4.28, 4.07, 1.44, 3.29, 3.00, 3.16, 3.36, 3.13, 1.71, 2.50, 3.39, 2.50}},
    {1.60, {3.44, 2.50, 2.87, 2.96, 4.33, 3.34, 4.89, 1.83, 1.60, 2.98, 4.36, 2.17, 3.17, 2.31, 4.30, 4.10, 1.44, 3.17, 3.42, 3.25, 3.17, 3.48, 1.71, 2.50, 3.44, 2.50}},
    {1.65, {3.48, 2.50, 2.93, 2.96, 4.33, 3.37, 4.93, 1.83, 1.65, 3.02, 4.42, 2.17, 3.17, 2.38, 4.32, 4.13, 1.44, 3.36, 3.17, 3.54, 3.47, 3.17, 1.71, 2.50, 3.48, 2.50}},
    {1.70, {3.53, 2.50, 2.99, 2.96, 4.33, 3.40, 4.97, 1.83, 1.70, 3.06, 4.48, 2.17, 3.17, 2.45, 4.33, 4.15, 1.44, 3.59, 3.57, 3.17, 3.64, 3.66, 1.71, 2.50, 3.53, 2.50}},
    {1.75, {3.57, 2.50, 3.05, 2.96, 4.33, 3.42, 5.01, 1.83, 1.75, 3.09, 4.53, 2.17, 3.17, 2.53, 4.33, 4.18, 1.44, 3.17, 3.69, 3.75, 3.17, 3.73, 1.71, 2.50, 3.57, 2.50}},
    {1.80, {3.61, 2.50, 3.10, 2.96, 4.33, 3.45, 5.05, 1.83, 1.80, 3.13, 4.58, 2.17, 3.17, 2.59, 4.33, 4.20, 1.44, 3.83, 3.17, 3.77, 3.90, 3.17, 1.71, 2.50, 3.61, 2.50}},
    {1.85, {3.65, 2.50, 3.15, 2.96, 4.33, 3.47, 5.09, 1.83, 1.85, 3.16, 4.63, 2.17, 3.17, 2.63, 4.33, 4.22, 1.44, 3.81, 3.98, 3.17, 3.84, 4.04, 1.71, 2.50, 3.65, 2.50}},
    {1.90, {3.68, 2.50, 3.20, 2.96, 4.33, 3.50, 5.12, 1.83, 1.90, 3.19, 4.67, 2.17, 3.17, 2.72, 4.33, 4.24, 1.44, 3.17, 3.87, 4.11, 3.17, 3.90, 1.71, 2.50, 3.68, 2.50}},
    {1.95, {3.72, 2.50, 3.25, 2.96, 4.33, 3.52, 5.15, 1.83, 1.95, 3.22, 4.71, 2.17, 3.17, 2.78, 4.33, 4.26, 1.44, 4.17, 3.17, 3.93, 4.22, 3.17, 1.71, 2.50, 3.72, 2.50}},
    {2.00, {3.75, 2.50, 3.29, 2.96, 4.33, 3.54, 5.18, 1.83, 2.00, 3.25, 4.75, 2.17, 3.17, 2.83, 4.33, 4.28, 1.44, 3.96, 4.28, 3.17, 3.99, 4.33, 1.71, 2.50, 3.75, 2.50}},
    {2.00, {5.00, 2.50, 5.00, 2.96, 4.33, 4.38, 6.25, 1.83, 2.00, 4.38, 6.25, 2.17, 3.17, 5.00, 4.33, 5.00, 1.44, 3.17, 4.01, 6.25, 3.17, 5.00, 1.71, 2.50, 5.00, 2.50}}};

float lajes_coeficiente_alfa(double lambda, int caso)
{
    if (lambda < 2.0)
    {
        for (int i = 0; i < NUM_LAMBDA; ++i)
        {
            if (LAJES_COEFICIENTE_ALFA[i].lambda > lambda)
            {
                return LAJES_COEFICIENTE_ALFA[i - 1].values[caso - 1];
            }
        }
    }
    else
    {
        return LAJES_COEFICIENTE_ALFA[21].values[caso - 1];
    }

    return 90.00;
}

CoeficienteLajeApoio lajes_coeficiente_reacoes_apoio_carga_uniforme(double lambda, int caso)
{
    if (lambda < 2.0)
    {
        for (int i = 0; i < NUM_LAMBDA; ++i)
        {
            if (LAJES_REACOES_APOIO_CARGA_UNIFORME[i].lambda > lambda)
            {
                CoeficienteLajeApoio coeficiente;
                switch (caso)
                {
                case 1:
                    coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[0];
                    coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[1];
                    break;
                case 2:
                    coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[2];
                    coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[3];
                    coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[4];
                    break;
                case 3:
                    coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[5];
                    coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[6];
                    coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[7];
                    break;
                case 4:
                    coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[9];
                    coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[10];
                    coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[11];
                    coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[12];
                    break;
                case 5:
                    coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[13];
                    coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[14];
                    break;
                case 6:
                    coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[15];
                    coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[16];
                    break;
                case 7:
                    coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[18];
                    coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[19];
                    coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[20];
                    break;
                case 8:
                    coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[21];
                    coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[22];
                    coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[23];
                    break;
                case 9:
                    coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[24];
                    coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[i - 1].values[25];
                    break;
                }

                return coeficiente;
            }
        }
    }
    else
    {
        CoeficienteLajeApoio coeficiente;
        switch (caso)
        {
        case 1:
            coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[0];
            coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[1];
            break;
        case 2:
            coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[2];
            coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[3];
            coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[4];
            break;
        case 3:
            coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[5];
            coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[6];
            coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[7];
            break;
        case 4:
            coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[9];
            coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[10];
            coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[11];
            coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[12];
            break;
        case 5:
            coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[13];
            coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[14];
            break;
        case 6:
            coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[15];
            coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[16];
            break;
        case 7:
            coeficiente.vx = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[18];
            coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[19];
            coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[20];
            break;
        case 8:
            coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[21];
            coeficiente.vy = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[22];
            coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[23];
            break;
        case 9:
            coeficiente.v_x = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[24];
            coeficiente.v_y = LAJES_REACOES_APOIO_CARGA_UNIFORME[21].values[25];
            break;
        }
        return coeficiente;
    }
}
// int main() {
//     print_coefs(1.00);
//     print_coefs(1.45);
//     return 0;
// }

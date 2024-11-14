#pragma once
#define NUM_LAMBDA 22

typedef struct CoeficienteLajeApoio {
    float vx;
    float vy;
    float v_x;
    float v_y;
} CoeficienteLajeApoio;

typedef struct Coeficientes
{
    double lambda;
    double values[9];
} Coeficientes;

typedef struct Coeficientes27
{
    double lambda;
    double values[27];
} Coeficientes27;

float lajes_coeficiente_alfa(double lambda, int caso);
CoeficienteLajeApoio lajes_coeficiente_reacoes_apoio_carga_uniforme(double lambda, int caso);
#pragma once
#include <locale.h>

typedef struct LajeMacica
{
    char id[7];
    float lx;
    float ly;
    float h;
    float E;
    int caso;
    float Q;
} LajeMacica;

typedef struct LajeMacicasFlechasResult
{
    char is_ok;
    char verificacao[20];
    float lambda;
    float alfa;
    float flechaImediata;
    float flechaTotal;
    float flechaFinal;
    float flechaLimite;
} LajeMacicasFlechasResult;

typedef struct LajeMacicaReacoesResult
{
    float lambda;
    float vx;
    float vy;
    float v_x;
    float v_y;
} LajeMacicaReacoesResult;

typedef struct LajeMacicaCortantesResult
{
} LajeMacicaCortantesResult;

typedef struct LajeMacicaMomentosResult
{
} LajeMacicaMomentosResult;

typedef struct LajeMacicaArmadurasResult
{
} LajeMacicaArmadurasResult;
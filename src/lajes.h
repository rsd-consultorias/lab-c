#pragma once
#include "types.h"
#include "tabelas.h"
#include "cliutil.h"
#include "file.h"
#include <math.h>
#include "tabelas.h"

void lajes_load();
void lajes_menu();

void lajes_adicionar();
void lajes_editar(char id);
void lajes_remover(char id);

void lajes_listar();
void lajes_listar_armaduras();
void lajes_listar_reacoes();
void lajes_listar_cortantes();
void lajes_listar_momentos();
void lajes_listar_flechas();

// Core functions
LajeMacicasFlechasResult *lajes_calcular_flechas(LajeMacica *laje);
LajeMacicaCortantesResult *lajes_calcular_cortantes(LajeMacica *laje);
LajeMacicaMomentosResult *lajes_calcular_momentos(LajeMacica *laje);
LajeMacicaReacoesResult *lajes_calcular_reacoes(LajeMacica *laje);
LajeMacicaArmadurasResult *lajes_calcular_armaduras(LajeMacica *laje);
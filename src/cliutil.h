#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
// Cores para os textos
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
//

void cli_clear_console();
void cli_text_color(char color[8]);
void cli_text_reset();
void cli_print_label();
void cli_print_label_programa(char titulo[]);
void cli_opcao_menu(char key1[1], char descricao1[24]);
void cli_opcoes_2menu(char key1[1], char descricao1[24], char key2[1], char descricao2[24]);
void cli_opcoes_3menu(char key1[1], char descricao1[24], char key2[1], char descricao2[24], char key3[1], char descricao3[24]);
int cli_read_float(char label[], float *valor, int tamanho);
int cli_read_char(char label[], char *valor, int tamanho);
int cli_read_int(char label[], int *valor, int tamanho);
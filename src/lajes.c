#include "lajes.h"
#include <string.h>

LajeMacica *lajes[1];
int lajes_contador = 0;

void lajes_load()
{
  carregar_projeto(lajes, &lajes_contador);
}

void lajes_listar()
{
  cli_clear_console();
  cli_text_color(YEL);
  cli_print_label_programa("CÁLCULO E DIMENSIONAMENTO DE LAGES MACIÇAS");
  cli_text_reset();
  cli_text_color(CYN);
  printf("ID     Caso  lx         ly         h          Q         \n");
  printf("       [1~9] (m)        (m)        (cm)       (kN/m²)   \n");
  printf("------ ----- ---------- ---------- ---------- ----------\n");
  cli_text_reset();

  for (int i = 0; i < lajes_contador; i++)
  {
    float lx = lajes[i]->lx;
    float ly = lajes[i]->ly;
    float h = lajes[i]->h;
    float Q = lajes[i]->Q;

    printf("%-6s %3d   %10.2f %10.2f %10.2f %10.2f\n", lajes[i]->id, lajes[i]->caso, lajes[i]->lx, lajes[i]->ly, lajes[i]->h, Q);
    cli_text_reset();
  }
  printf("\n%d lajes\n\n", lajes_contador);
}

void lajes_listar_armaduras()
{
  cli_clear_console();
  cli_text_color(YEL);
  cli_print_label_programa("CÁLCULO E DIMENSIONAMENTO DE LAGES MACIÇAS - ARMADURAS");
  cli_text_reset();
  cli_text_color(CYN);
  printf("ID     Caso  lx         ly         h          Q          Ecs        λ      α          Flecha Ime αf Flecha  Flecha     Flecha Li  Verificação\n");
  printf("       [1~9] (m)        (m)        (cm)       (kN/m²)    (GPa)                        diata (cm) Total      Final (cm) mite (cm)  \n");
  printf("------ ----- ---------- ---------- ---------- ---------- ---------- ------ ---------- ---------- ---------- ---------- ---------- --------------------\n");
  cli_text_reset();
  printf("\n%d lajes\n\n", lajes_contador);
}

void lajes_listar_reacoes()
{
  cli_clear_console();
  cli_text_color(YEL);
  cli_print_label_programa("CÁLCULO E DIMENSIONAMENTO DE LAGES MACIÇAS - REAÇÕES DE APOIO");
  cli_text_reset();
  cli_text_color(CYN);
  printf("ID     Caso  lx         ly         h          Q          Ecs        λ      Vx         V'x        Vy         V'y\n");
  printf("       [1~9] (m)        (m)        (cm)       (kN/m²)    (GPa)             (kN/m)     (kN/m)     (kN/m)     (kN/m)\n");
  printf("------ ----- ---------- ---------- ---------- ---------- ---------- ------ ---------- ---------- ---------- ----------\n");
  cli_text_reset();

  for (int i = 0; i < lajes_contador; i++)
  {
    float lx = lajes[i]->lx;
    float ly = lajes[i]->ly;
    float h = lajes[i]->h;
    float Q = lajes[i]->Q;

    LajeMacicaReacoesResult *result = lajes_calcular_reacoes(lajes[i]);

    printf("%-6s %3d   %10.2f %10.2f %10.2f %10.2f %10.2f %6.2f %10.2f %10.3f %10.3f %10.3f\n", lajes[i]->id, lajes[i]->caso, lajes[i]->lx, lajes[i]->ly, lajes[i]->h, Q, 24.0f, result->lambda, result->vx, result->v_x, result->vy, result->v_y);
    cli_text_reset();

    result = NULL;
    free(result);
  }
  printf("\n%d lajes\n\n", lajes_contador);
}

void lajes_listar_cortantes()
{
  cli_clear_console();
  cli_text_color(YEL);
  cli_print_label_programa("CÁLCULO E DIMENSIONAMENTO DE LAGES MACIÇAS - CORTANTES");
  cli_text_reset();
  cli_text_color(CYN);
  printf("ID     Caso  lx         ly         h          Q          Ecs        λ      α          Flecha Ime αf Flecha  Flecha     Flecha Li  Verificação\n");
  printf("       [1~9] (m)        (m)        (cm)       (kN/m²)    (GPa)                        diata (cm) Total      Final (cm) mite (cm)  \n");
  printf("------ ----- ---------- ---------- ---------- ---------- ---------- ------ ---------- ---------- ---------- ---------- ---------- --------------------\n");
  cli_text_reset();
  printf("\n%d lajes\n\n", lajes_contador);
}

void lajes_listar_momentos()
{
  cli_clear_console();
  cli_text_color(YEL);
  cli_print_label_programa("CÁLCULO E DIMENSIONAMENTO DE LAGES MACIÇAS - MOMENTOS");
  cli_text_reset();
  cli_text_color(CYN);
  printf("ID     Caso  lx         ly         h          Q          Ecs        λ      α          Flecha Ime αf Flecha  Flecha     Flecha Li  Verificação\n");
  printf("       [1~9] (m)        (m)        (cm)       (kN/m²)    (GPa)                        diata (cm) Total      Final (cm) mite (cm)  \n");
  printf("------ ----- ---------- ---------- ---------- ---------- ---------- ------ ---------- ---------- ---------- ---------- ---------- --------------------\n");
  cli_text_reset();
  printf("\n%d lajes\n\n", lajes_contador);
}

void lajes_listar_flechas()
{
  cli_clear_console();
  cli_text_color(YEL);
  cli_print_label_programa("CÁLCULO E DIMENSIONAMENTO DE LAGES MACIÇAS - FLECHAS");
  cli_text_reset();
  cli_text_color(CYN);
  printf("ID     Caso  lx         ly         h          Q          Ecs        λ      α          Flecha Ime αf Flecha  Flecha     Flecha Li  Verificação\n");
  printf("       [1~9] (m)        (m)        (cm)       (kN/m²)    (GPa)                        diata (cm) Total      Final (cm) mite (cm)  \n");
  printf("------ ----- ---------- ---------- ---------- ---------- ---------- ------ ---------- ---------- ---------- ---------- ---------- --------------------\n");
  cli_text_reset();

  for (int i = 0; i < lajes_contador; i++)
  {
    float lx = lajes[i]->lx;
    float ly = lajes[i]->ly;
    float h = lajes[i]->h;
    float Q = lajes[i]->Q;

    LajeMacicasFlechasResult *result = lajes_calcular_flechas(lajes[i]);
    float lambda = result->lambda;
    float alfa = result->alfa;
    float flechaImediata = result->flechaImediata;
    float flechaTotal = result->flechaTotal;
    float flechaFinal = result->flechaFinal;
    float flechaLimite = result->flechaLimite;
    char verificacao[20];
    strcpy(verificacao, result->verificacao);

    if (flechaLimite > flechaFinal)
    {
      cli_text_color(GRN);
    }
    else
    {
      cli_text_color(RED);
    }

    printf("%-6s %3d   %10.2f %10.2f %10.2f %10.2f %10.2f %6.2f %10.2f %10.3f %10.3f %10.3f %10.3f %-20s\n", lajes[i]->id, lajes[i]->caso, lajes[i]->lx, lajes[i]->ly, lajes[i]->h, Q, 24.0f, lambda, alfa, flechaImediata, flechaTotal, flechaFinal, flechaLimite, verificacao);
    cli_text_reset();
    result = NULL;
    free(result);
  }
  printf("\n%d lajes\n\n", lajes_contador);
}

void lajes_menu()
{
  char lajes_opcao_selecionada[1] = {'\0'};
  char lajes_descricao_opcao[24] = "";
  cli_clear_console();

  while (lajes_opcao_selecionada[0] != 'X')
  {
    switch (lajes_opcao_selecionada[0])
    {
    case 'N':
    {
      LajeMacica *laje = malloc(sizeof(LajeMacica));
      while (lajes_opcao_selecionada[0] != 'X')
      {
        cli_clear_console();
        cli_text_color(YEL);
        lajes_listar();

        if (cli_read_char("ID", &laje->id, 6) < 0)
        {
          break;
        };
        if (cli_read_int("Caso (1~9)", &laje->caso, 5) < 0)
        {
          break;
        };
        if (cli_read_float("lx (m)", &laje->lx, 10) < 0)
        {
          break;
        };
        if (cli_read_float("ly (m)", &laje->ly, 10) < 0)
        {
          break;
        };
        if (cli_read_float("h (cm)", &laje->h, 10) < 0)
        {
          break;
        };
        if (cli_read_float("Carga (kN/m²)", &laje->Q, 10) < 0)
        {
          break;
        };

        lajes[lajes_contador] = laje;
        lajes_contador++;

        cli_text_color(CYN);
        printf("\nNova laje? [S] Sim/[X] Não: ");
        cli_text_reset();
        scanf(" %1s", &lajes_opcao_selecionada);
      }
    }
    // strcpy(&lajes_descricao_opcao, "Nova laje");
    break;
    case 'E':
      // strcpy(lajes_descricao_opcao, "Editar laje");
      break;
    case 'R':
      // strcpy(lajes_descricao_opcao, "Remover laje");
      break;
    case 'L':
      // carregar_projeto(lajes, &lajes_contador);
      break;
    case 'C':
      while (lajes_opcao_selecionada[0] != 'X')
      {
        switch (lajes_opcao_selecionada[0])
        {
        case 'F':
          lajes_listar_flechas();
          break;
        case 'M':
          lajes_listar_momentos();
          break;
        case 'R':
          lajes_listar_reacoes();
          break;
        case 'V':
          lajes_listar_cortantes();
          break;
        case 'D':
          lajes_listar_armaduras();
          break;
        default:
          lajes_listar_flechas();
          break;
        }

        cli_opcoes_3menu("F", "Flechas", "M", "Momentos", "V", "Cortantes");
        cli_opcoes_2menu("R", "Reações de apoio", "D", "Dimensionamentos");
        cli_text_color(CYN);
        printf("[X] para voltar: ");
        cli_text_reset();
        scanf(" %1s", &lajes_opcao_selecionada);
        cli_text_reset();
      }
      break;
    case 'X':
      break;
    default:
      break;
    }

    cli_clear_console();
    cli_text_color(YEL);
    cli_print_label_programa("CÁLCULO E DIMENSIONAMENTO DE LAGES MACIÇAS");
    cli_opcoes_3menu("N", "Nova laje", "E", "Editar laje", "L", "Carregar lajes");
    cli_opcoes_2menu("R", "Remover laje", "C", "Calcular");
    cli_opcao_menu("X", "Menu principal");
    cli_text_color(CYN);
    printf("\nComando [%1s]: ", &lajes_opcao_selecionada);
    cli_text_reset();
    scanf(" %1s", &lajes_opcao_selecionada);
    cli_text_reset();
  };
}

void lajes_adicionar() {}
void lajes_editar(char id) {}
void lajes_remover(char id) {}

LajeMacicasFlechasResult *lajes_calcular_flechas(LajeMacica *laje)
{
  LajeMacicasFlechasResult *result = malloc(sizeof(LajeMacicasFlechasResult));
  float lx = laje->lx;
  float ly = laje->ly;
  float h = laje->h;
  float Q = laje->Q;
  float lambda = laje->ly / laje->lx;
  float alfa = lajes_coeficiente_alfa(lambda, laje->caso);
  result->flechaImediata = 100.0 * ((Q * 10e3) * ((powf(lx, 4)) * alfa) / ((24 * 10e9) * (powf((h / 100), 3)) * 100));
  result->flechaTotal = 1.46;
  result->flechaFinal = (result->flechaImediata * result->flechaTotal) + result->flechaImediata;
  result->flechaLimite = (100.0 * lx) / 250.0;
  result->verificacao[20] = "";
  result->is_ok = 0;
  result->lambda = lambda;
  result->alfa = alfa;

  if (result->flechaLimite > result->flechaFinal)
  {
    result->is_ok = 1;
    strcpy(result->verificacao, "OK");
  }
  else
  {
    strcpy(result->verificacao, "NOK FLECHA");
  }

  return result;
}

LajeMacicaReacoesResult *lajes_calcular_reacoes(LajeMacica *laje)
{
  LajeMacicaReacoesResult *result = malloc(sizeof(LajeMacicaReacoesResult));
  float lx = laje->lx;
  float ly = laje->ly;
  float h = laje->h;
  float Q = laje->Q;
  float lambda = laje->ly / laje->lx;
  CoeficienteLajeApoio coeficiente = lajes_coeficiente_reacoes_apoio_carga_uniforme(lambda, laje->caso);

  result->lambda = lambda;
  result->vx = (lx * Q * coeficiente.vx) / 10.0;
  result->vy = (lx * Q * coeficiente.vy) / 10.0;
  result->v_x = (lx * Q * coeficiente.v_x) / 10.0;
  result->v_y = (lx * Q * coeficiente.v_y) / 10.0;

  return result;
}
#include "cliutil.h"

// Função para limpar o buffer de entrada
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void cli_clear_console()
{
    printf("\033c");
}

void cli_text_color(char color[8])
{
    printf("%s", color);
}

void cli_text_reset()
{
    printf("\033[0m");
}

void cli_print_label()
{
    cli_text_color(CYN);
    printf("\n");
    printf("                ____  ____  ____    _____ ___   ___  _     ____  \n");
    printf("               |  _ \\/ ___||  _ \\  |_   _/ _ \\ / _ \\| |   / ___| \n");
    printf("               | |_) \\___ \\| | | |   | || | | | | | | |   \\___ \\ \n");
    printf("               |  _ < ___) | |_| |   | || |_| | |_| | |___ ___) |\n");
    printf("               |_| \\_\\____/|____/    |_| \\___/ \\___/|_____|____/ \n\n");
    printf("                                                            v1.0.0\n");
    cli_text_color(RED);
    printf("\n               RSD Tools - CÁLCULO E DIMENSIONAMENTO DE ESTRUTURAS\n");
    cli_text_reset();
}

void cli_print_label_programa(char titulo[])
{
    cli_text_color(RED);
    printf("\n               RSD Tools - CÁLCULO E DIMENSIONAMENTO DE ESTRUTURAS\n");
    printf("                                                            v1.0.0\n");
    cli_text_color(YEL);
    wprintf(L"\n%s\n\n", titulo);
    cli_text_reset();
}

void cli_opcao_menu(char key1[1], char descricao1[24])
{
    cli_text_color(CYN);
    printf("[%s]", key1);
    cli_text_reset();
    wprintf(L" %-24s\n", descricao1);
}

void cli_opcoes_2menu(char key1[1], char descricao1[24], char key2[1], char descricao2[24])
{
    cli_text_color(CYN);
    printf("[%s]", key1);
    cli_text_reset();
    wprintf(L" %-24s", descricao1);

    cli_text_color(CYN);
    printf("[%s]", key2);
    cli_text_reset();
    wprintf(L" %-24s\n", descricao2);
}

void cli_opcoes_3menu(char key1[1], char descricao1[24], char key2[1], char descricao2[24], char key3[1], char descricao3[24])
{
    cli_text_color(CYN);
    printf("[%s]", key1);
    cli_text_reset();
    wprintf(L" %-24s", descricao1);

    cli_text_color(CYN);
    printf("[%s]", key2);
    cli_text_reset();
    wprintf(L" %-24s", descricao2);

    cli_text_color(CYN);
    printf("[%s]", key3);
    cli_text_reset();
    wprintf(L" %-24s\n", descricao3);
}

int cli_read_int(char label[], int *valor, int tamanho)
{
    char buffer[tamanho + 1]; // Adicionar espaço para o caractere nulo

    printf("%s: ", label);
    scanf("%s", buffer);

    // Remover o caractere de nova linha, se presente
    buffer[strcspn(buffer, "\n")] = '\0';

    // Garantir que buffer está nulo terminado
    buffer[tamanho] = '\0';

    // Verificar se o primeiro caractere é 'X'
    if (buffer[0] == 'X')
    {
        return -1;
    }

    // Limpar o buffer de entrada se a entrada excedeu o tamanho permitido
    if (strlen(buffer) >= tamanho)
    {
        limpar_buffer();
    }

    // Converter a entrada para int
    *valor = atoi(buffer);
    return 0;
}

int cli_read_float(char label[], float *valor, int tamanho)
{
    char buffer[tamanho + 1]; // Adicionar espaço para o caractere nulo

    printf("%s: ", label);
    scanf("%s", buffer);

    // Remover o caractere de nova linha, se presente
    buffer[strcspn(buffer, "\n")] = '\0';

    // Garantir que buffer está nulo terminado
    buffer[tamanho] = '\0';

    // Verificar se o primeiro caractere é 'X'
    if (buffer[0] == 'X')
    {
        return -1;
    }

    // Limpar o buffer de entrada se a entrada excedeu o tamanho permitido
    if (strlen(buffer) >= tamanho)
    {
        limpar_buffer();
    }

    // Converter a entrada para float
    *valor = strtof(buffer, NULL);
    return 0;
}

int cli_read_char(char label[], char *valor, int tamanho)
{
    char buffer[tamanho + 1]; // Adicionar espaço para o caractere nulo

    printf("%s: ", label);
    scanf("%s", buffer);

    // Remover o caractere de nova linha, se presente
    buffer[strcspn(buffer, "\n")] = '\0';

    // Limpar o buffer de entrada se a entrada excedeu o tamanho permitido
    if (strlen(buffer) >= tamanho)
    {
        limpar_buffer();
    }

    // Verificar se o primeiro caractere é 'X'
    if (buffer[0] == 'X')
    {
        return -1;
    }

    // Copiar a entrada segura para o valor
    strncpy(valor, buffer, tamanho);
    valor[tamanho] = '\0'; // Garantir que a string está nulo terminada

    return 0;
}

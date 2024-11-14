#include "main.h"

// #define MAX_NODES 100
// #define MAX_ELEMENTS 100

void print_main_menu()
{
    cli_text_color(YEL);
    printf("\nMENU PRINCIPAL\n\n");
    cli_text_reset();

    cli_opcoes_2menu("N", "Novo projeto", "C", "Carregar projeto");
    cli_opcoes_3menu("L", "Lajes", "V", "Vigas", "P", "Pilares");
    cli_opcoes_3menu("F", "Fundações", "T", "Contenções", "S", "Estratigrafia do solo");
    cli_opcoes_3menu("Q", "Combinações de cargas", "W", "Cargas de vento", "B", "Materiais");
    printf("\n");
    cli_opcoes_3menu("E", "Analisar estrutura", "M", "Memória de cálculo", "N", "Quantitativos");
    printf("\n");
    cli_opcao_menu("Z", "Encerrar programa");
}

int main(int arg, char const *args[])
{
    char opcao_selecionada[1] = {'\0'};
    char descricao_opcao[24] = "";
    cli_clear_console();
    setlocale(LC_ALL, "pt_BR.UTF-8");
    // setlocale(LC_ALL, "");
    lajes_load();

    while (opcao_selecionada[0] != 'X')
    {
        cli_clear_console();
        cli_print_label();
        print_main_menu();
        cli_text_color(CYN);
        printf("\nComando [%1s]: ", &opcao_selecionada);
        cli_text_reset();
        scanf(" %1s", &opcao_selecionada);
        cli_text_reset();

        switch (opcao_selecionada[0])
        {
        case 'N':
            // strcpy(descricao_opcao, "Novo projeto");
            break;
        case 'C':
            // strcpy(descricao_opcao, "Carregar projeto");
            break;
        case 'L':
            lajes_menu();
            break;
        case 'V':
            // strcpy(descricao_opcao, "Vigas");
            break;
        case 'P':
            // strcpy(descricao_opcao, "Pilares");
            break;
        case 'F':
            // strcpy(descricao_opcao, "Fundações");
            break;
        case 'T':
            // strcpy(descricao_opcao, "Contenções");
            break;
        case 'E':
            // strcpy(descricao_opcao, "Verificar elementos");
            break;
        case 'M':
            // strcpy(descricao_opcao, "Memória de cálculo");
            break;
        case 'Z':
            cli_clear_console();
            exit(0);
            break;
        default:
            // strcpy(descricao_opcao, "Opção não existe");
            break;
        }
    };

    // Antes de encerrar o programa liberar a memória
    cli_clear_console();

    // for (int i = 0; i < sizeof(&args); i++)
    // {
    // printf("%s\n", args[i]);
    // }

    // Node nodes[MAX_NODES];
    // Element elements[MAX_ELEMENTS];
    // int nodeCount = 0, elementCount = 0;

    // // Adicionar nós
    // addNode(nodes, &nodeCount, 1, 0.0, 0.0);
    // addNode(nodes, &nodeCount, 2, 5.0, 0.0);
    // addNode(nodes, &nodeCount, 3, 5.0, 5.0);

    // // Adicionar elementos
    // addElement(elements, &elementCount, 1, &nodes[0], &nodes[1], 10.0);
    // addElement(elements, &elementCount, 2, &nodes[1], &nodes[2], 20.0);

    // // Calcular reações
    // calculateReactions(elements, elementCount);

    // // Calcular matriz de rigidez global
    // calculateGlobalStiffnessMatrix(nodes, elements, nodeCount, elementCount);

    // // Exibir resumo
    // printSummary(elements, elementCount);
    // printf("");

    return 0;
}

// char sel_option;

// void calculate_sha256(const char *str, unsigned char hash[SHA256_DIGEST_LENGTH])
// {
//     SHA256_CTX sha256;
//     SHA256_Init(&sha256);
//     SHA256_Update(&sha256, str, strlen(str));
//     SHA256_Final(hash, &sha256);
// }

// void print_hash(unsigned char hash[SHA256_DIGEST_LENGTH])
// {
//     for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
//     {
//         printf("%02x", hash[i]);
//     }
//     printf("\n");
// }

// int main1()
// {
//     const char *str = "Hello, world!";
//     unsigned char hash[SHA256_DIGEST_LENGTH];

//     calculate_sha256(str, hash);
//     printf("SHA-256 hash: ");
//     print_hash(hash);

//     //////
//     float *cargas = malloc(5 * sizeof(float));
//     char input[50];
//     int sequence = 0;

//     // Verifica se a entrada é 'c'
//     do
//     {
//         printf(" \\>: ");
//         fgets(input, 50, stdin);

//         if (input[0] == 'x' && input[1] == '\n')
//         {
//             return 0;
//         }
//         else if (input[0] == 'c' && input[1] == '\n')
//         {
//             sequence = 0;
//             fundacao_direta(cargas);
//             free(cargas);
//             cargas = malloc(5 * sizeof(float));
//         }
//         else
//         {
//             char *endptr;
//             float num = strtof(input, &endptr);

//             // Se a conversão for bem-sucedida e endptr apontar para o final da string (ou seja, '\n')
//             if (endptr != input && *endptr == '\n')
//             {
//                 cargas[sequence] = num;
//                 sequence += 1;
//             }
//             else
//             {
//                 printf("Entrada inválida\n");
//             }
//         }
//     } while (input[0] != 'x');

//     return 0;
// }
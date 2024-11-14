#include "file.h"

FILE *tempFile;

void carregar_projeto(LajeMacica *lajes[], int *count)
{
    FILE *tempFile;
    char linha[140];
    const char DELIMITADOR[] = ";";

    tempFile = fopen("projeto.dat", "r");
    if (tempFile != NULL)
    {
        while (fgets(linha, sizeof(linha), tempFile))
        {
            // Remover o caractere de nova linha, se houver
            linha[strcspn(linha, "\n")] = '\0';
            LajeMacica *laje = malloc(sizeof(LajeMacica));
            char *token;
            char *rest = linha;

            // Ignorar o primeiro token (ELEMENTO)
            token = strtok_r(rest, DELIMITADOR, &rest);
            if (strcmp(token, "LAJE") == 0)
            {
                // Ler ID
                token = strtok_r(rest, DELIMITADOR, &rest);
                strcpy(laje->id, token);

                // Ler LX
                token = strtok_r(rest, DELIMITADOR, &rest);
                laje->lx = atof(token);

                // Ler LY
                token = strtok_r(rest, DELIMITADOR, &rest);
                laje->ly = atof(token);

                // Ler H
                token = strtok_r(rest, DELIMITADOR, &rest);
                laje->h = atof(token);

                // Ler Caso
                token = strtok_r(rest, DELIMITADOR, &rest);
                laje->caso = atoi(token);

                // Ler Carga (Q)
                token = strtok_r(rest, DELIMITADOR, &rest);
                laje->Q = atof(token);

                lajes[*count] = laje;
                (*count)++;
            }
        }
        fclose(tempFile);
        tempFile = NULL;
        free(tempFile);
    }
    else
    {
        perror("Erro ao abrir o arquivo");
    }
}
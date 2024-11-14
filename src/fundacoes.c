#include "fundacoes.h"

void addNode(Node *nodes, int *nodeCount, int id, double x, double y) {
    nodes[*nodeCount].id = id;
    nodes[*nodeCount].x = x;
    nodes[*nodeCount].y = y;
    (*nodeCount)++;
}

void addElement(Element *elements, int *elementCount, int id, Node *node1, Node *node2, double load) {
    elements[*elementCount].id = id;
    elements[*elementCount].node1 = node1;
    elements[*elementCount].node2 = node2;
    elements[*elementCount].load = load;
    (*elementCount)++;
}

void calculateReactions(Element *elements, int elementCount) {
    for (int i = 0; i < elementCount; i++) {
        // Comprimento do elemento
        double length = sqrt(pow(elements[i].node2->x - elements[i].node1->x, 2) + pow(elements[i].node2->y - elements[i].node1->y, 2));
        
        // Cálculo das reações de cortante e momento
        // Simplesmente como exemplo, assumimos uma carga distribuída uniforme ao longo do elemento
        double shearForce = elements[i].load * length / 2;
        double moment = elements[i].load * pow(length, 2) / 8;

        printf("Elemento %d:\n", elements[i].id);
        printf("  Reação de Cortante: %.2lf kN\n", shearForce);
        printf("  Momento: %.2lf kNm\n", moment);
    }
}

void calculateGlobalStiffnessMatrix(Node *nodes, Element *elements, int nodeCount, int elementCount) {
    // Inicialização da matriz de rigidez global (2 graus de liberdade por nó: x e y)
    double globalStiffnessMatrix[2 * nodeCount][2 * nodeCount];
    for (int i = 0; i < 2 * nodeCount; i++) {
        for (int j = 0; j < 2 * nodeCount; j++) {
            globalStiffnessMatrix[i][j] = 0;
        }
    }

    // Montagem da matriz de rigidez global
    for (int e = 0; e < elementCount; e++) {
        double length = sqrt(pow(elements[e].node2->x - elements[e].node1->x, 2) + pow(elements[e].node2->y - elements[e].node1->y, 2));
        double stiffness = 1.0;  // Para simplificação, consideramos rigidez unitária

        // Contribuição do elemento para a matriz de rigidez global
        int n1 = elements[e].node1->id - 1;
        int n2 = elements[e].node2->id - 1;

        globalStiffnessMatrix[2 * n1][2 * n1] += stiffness;
        globalStiffnessMatrix[2 * n1][2 * n2] -= stiffness;
        globalStiffnessMatrix[2 * n2][2 * n1] -= stiffness;
        globalStiffnessMatrix[2 * n2][2 * n2] += stiffness;
    }

    // Exibição da matriz de rigidez global
    printf("Matriz de Rigidez Global:\n");
    for (int i = 0; i < 2 * nodeCount; i++) {
        for (int j = 0; j < 2 * nodeCount; j++) {
            printf("%.2lf ", globalStiffnessMatrix[i][j]);
        }
        printf("\n");
    }
}

void printSummary(Element *elements, int elementCount) {
    for (int i = 0; i < elementCount; i++) {
        printf("Elemento %d:\n", elements[i].id);
        printf("  Nó 1: (%lf, %lf)\n", elements[i].node1->x, elements[i].node1->y);
        printf("  Nó 2: (%lf, %lf)\n", elements[i].node2->x, elements[i].node2->y);
        printf("  Carga: %lf\n", elements[i].load);
    }
}

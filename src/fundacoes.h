#pragma once
#ifndef STRUCTURE_ANALYSIS_H
#define STRUCTURE_ANALYSIS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição das estruturas de dados
typedef struct Node {
    int id;
    double x, y;
} Node;

typedef struct Element {
    int id;
    Node *node1;
    Node *node2;
    double load;
} Element;

// Funções
void addNode(Node *nodes, int *nodeCount, int id, double x, double y);
void addElement(Element *elements, int *elementCount, int id, Node *node1, Node *node2, double load);
void calculateReactions(Element *elements, int elementCount);
void calculateGlobalStiffnessMatrix(Node *nodes, Element *elements, int nodeCount, int elementCount);
void printSummary(Element *elements, int elementCount);

#endif // STRUCTURE_ANALYSIS_H

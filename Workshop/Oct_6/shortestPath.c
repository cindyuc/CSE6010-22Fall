#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
    int v;
    int weight;
} AdjListNode;

void initial_AdjListNode (int v, int weight, AdjListNode node) {
    node.v = v;
    node.weight = weight;
}


typedef struct Graph {
    int V;
    AdjListNode adj[];
} Graph;

void shortestPath(int s) {
}

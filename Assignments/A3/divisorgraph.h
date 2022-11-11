#include <stdbool.h>
#include <stdlib.h>

typedef struct Vertex {
  int value;
  int weight;
  int max_weightPath; // maximum weight path from source node computed so far
  struct Vertex
      *predecossor; // predecessor in maximum weight path computer so far
  struct Vertex *next;
} Vertex;

Vertex *newVertex(int value);

void initialize(Vertex **vertexarray);

void buildGraph(Vertex **vertexarray, int numvertices);

bool relax(Vertex *u, Vertex *v, int *distance, int *predecessor, int *set_Q);

void findPaths(Vertex **vertexarray, int numvertices, char bf);

void finalize(Vertex **vertexarray);

void printMaximumPath(int *distance, int *predecessor, int numvertices);

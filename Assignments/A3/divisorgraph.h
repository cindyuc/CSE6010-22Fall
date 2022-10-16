#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex {
  int value;
  int weight;
  int max_weightPath; // maximum weight path from source node computed so far
  struct Vertex
      *predecossor; // predecessor in maximum weight path computer so far
  struct Vertex *next;
} Vertex;

Vertex *initializeVertex(int value);

void initialize(Vertex **vertexarray);

void buildGraph(Vertex **vertexarray, int numvertices);

bool relax(Vertex* u, Vertex* v);

void findPaths(Vertex **vertexarray, int numvertices, char bf);

void finalize(Vertex **vertexarray);

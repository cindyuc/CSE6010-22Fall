#include "divisorgraph.h"
#include <stdio.h>
#include <string.h>

#define MAXVALUE 1000
#define UNUSED(x) (void)(x)

int main(int argc, char *argv[]) {
  int numvertices = MAXVALUE;
  char bf = 'd';
  char dij[] = "Dijkstra's algorithm";
  char bell[] = "Bellman-Ford algorithm";
  char algorithm[40];
  strcpy(algorithm, dij);

  if (argc == 2) {
    if (*argv[1] == 'd') {
      numvertices = MAXVALUE;
    } else if (*argv[1] == 'b') {
      bf = 'b';
      numvertices = MAXVALUE;
    } else {
      numvertices = atoi(argv[1]);
    }
  } else if (argc == 3) {
    numvertices = atoi(argv[1]);
    bf = *argv[2];
  }

  if (bf == 'b') {
    strcpy(algorithm, bell);
  }

  

  printf("The number of vertices in graph is %d, the search algorithm used is %s\n", numvertices, algorithm);

  Vertex *vertexarray[MAXVALUE+5] = {NULL};

  initialize(vertexarray);
  buildGraph(vertexarray, numvertices);
  findPaths(vertexarray, numvertices, bf);
  finalize(vertexarray);

  return 0;
}
#include "divisorgraph.h"
#include <stdio.h>

#define MAXVALUE 7
#define UNUSED(x) (void)(x)

int main(int argc, char *argv[]) {
  int numvertices = MAXVALUE;
  char bf = 'd';
  if (argc == 1) {
    printf("the number of vertices in graph and algorithms are default.\n");
  } else if (argc == 2) {
    if (*argv[1] == 'd') {
      bf = 'd';
    } else if (*argv[1] == 'b') {
      bf = 'b';
    } else {
      numvertices = *argv[1];
    }
  } else {
    numvertices = *argv[1];
    bf = *argv[2];
  }

  printf("%d, %c\n", numvertices, bf);

  Vertex *vertexarray[MAXVALUE] = {NULL};

  // UNUSED(vertexarray);
  initialize(vertexarray);
  printf("ini");
  buildGraph(vertexarray, numvertices);

  // findPaths(vertexarray, numvertices, bf);

  //   finalize(vertexarray);

  return 0;
}
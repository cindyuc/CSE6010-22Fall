#include "divisorgraph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNUSED(x) (void)(x)

#define MAXVERTEX 7

Vertex *initializeVertex(int value) {
  Vertex *newVertex = malloc(sizeof(Vertex));
  if (newVertex == NULL) {
    printf("Allocation failure");
  } else {
    newVertex->value = value;
    newVertex->weight = 1;
    newVertex->max_weightPath = 0;
    newVertex->predecossor = NULL;
    newVertex->next = NULL;
  }

  return newVertex;
}

void initialize(Vertex **vertexarray) {
  vertexarray = malloc((MAXVERTEX + 5) * sizeof(Vertex *));
  if (vertexarray == NULL) {
    printf("Allocation failure");
  }
  for (int i = 0; i < MAXVERTEX+ 5; i++) {
    Vertex * newVertex = initializeVertex(i + 1);
    vertexarray[i] = newVertex;
  }
}

void buildGraph(Vertex **vertexarray, int numvertices) {
  // for (int i = 0; i < numvertices; i++) {
  //   Vertex *newVertex = initializeVertex(i + 1);
  //   // printf("size of newVertex, %lu\n", sizeof(*newVertex));
  //   // UNUSED(newVertex);
  //   // printf("%lu\n", sizeof(*vertexarray[2]));
  //   vertexarray[i] = newVertex;
  // }
  // // for (int i = numvertices; i < MAXVERTEX; i++) {
  // //   vertexarray[i] = NULL;
  // // }

  Vertex *tmpVertex = vertexarray[0];
  // printf("%d\n", vertexarray[0]->value);

  // there will an edge from the vertex with value 1 to every other vertices in
  // the graph
  for (int i = 2; i < numvertices + 1; i++) {
    Vertex *newVertex = initializeVertex(i);
    tmpVertex->next = newVertex;
    tmpVertex = newVertex;
  }

  printf("add edges for vertex 1.\n");

  // adding an edge from vertex i (i != 1)
  for (int i = 1; i < numvertices; i++) {
    tmpVertex = vertexarray[i];
    for (int j = i + 2; j < numvertices + 1; j++) {
      if (j % (i + 1) == 0) {
        Vertex *newVertex = initializeVertex(j);
        printf("%d\n", j);
        tmpVertex->next = newVertex;
        tmpVertex = newVertex;
      }
    }
    // printf("%d\n", i);
  }
  printf("build graph successfully.\n");
}

bool relax(Vertex *u, Vertex *v) {
  if (u->max_weightPath + u->weight > v->max_weightPath) {
    v->max_weightPath = u->max_weightPath + u->weight;
    v->predecossor = u;
    return true;
  }
  return false;
};

void findPaths(Vertex **vertexarray, int numvertices, char bf) {
  printf("start to find path.\n");

  int max_pathLength = 0;
  int num_path = 0;

  bool set_S[numvertices];
  memset(set_S, false, sizeof(set_S));
  set_S[0] = true;

  bool set_Q[numvertices];
  memset(set_Q, true, sizeof(set_Q));
  set_Q[0] = false;

  switch (bf) {
    // Bellman-Ford algorithm
  case 'b': {
  }
    // Dijkstra's algorithm
  default: {
    printf("dijstra's algorithms.\n");
    // printf("%d\n", vertexarray[0]->value);
    Vertex *tmpVertex = vertexarray[0]->next;
    int u_idx = 0;
    int traverseCounter = 1;

    // printf("vertex 1.\n");

    while (tmpVertex != NULL) {
      if (relax(vertexarray[0], tmpVertex)) {
        relax(vertexarray[0], vertexarray[tmpVertex->value - 1]);
        if (tmpVertex->max_weightPath > max_pathLength) {
          // printf("%d, %d\n", tmpVertex->max_weightPath, max_pathLength);
          max_pathLength = tmpVertex->max_weightPath;
          u_idx = tmpVertex->value - 1;
          num_path = 1;
        } else if (tmpVertex->max_weightPath == max_pathLength) {
          num_path++;
        }
      }
      tmpVertex = tmpVertex->next;
    }
    // printf("%d\n", num_path);

    while (traverseCounter <= numvertices) {
      set_S[u_idx] = true;
      set_Q[u_idx] = false;
      Vertex *u = vertexarray[u_idx];
      // printf("u's value %d\n", (set_Q[3] == true));

      tmpVertex = u->next;
      while (tmpVertex != NULL) {
        printf("while loop.\n");
        if (set_Q[tmpVertex->value - 1] == true && relax(u, tmpVertex)) {
          relax(u, vertexarray[tmpVertex->value - 1]);
          printf("%d\n", tmpVertex->max_weightPath);
          if (tmpVertex->max_weightPath > max_pathLength) {
            printf("%d, %d\n", tmpVertex->max_weightPath, max_pathLength);
            max_pathLength = tmpVertex->max_weightPath;
            u_idx = tmpVertex->value - 1;
            num_path = 1;
          } else if (tmpVertex->max_weightPath == max_pathLength) {
            num_path++;
          }
        }
        tmpVertex = tmpVertex->next;
      }
      traverseCounter++;
      // printf("%d, %d\n", num_path, max_pathLength);
    }

    // traverse the vertexarray to find and store the path with max_pathLength
    int max_path[num_path][max_pathLength];
    int n = 0;
    for (int i = 0; i < numvertices; i++) {
      if (n < num_path) {
        tmpVertex = vertexarray[i]->next;
        while (tmpVertex != NULL && n < num_path) {
          if (tmpVertex->max_weightPath == max_pathLength) {
            max_path[n][max_pathLength - 1] = tmpVertex->value;
            Vertex *tmpPre = tmpVertex->predecossor;
            for (int j = max_pathLength - 2; i >= 0; i--) {
              max_path[n][j] = tmpPre->value;
              tmpPre = tmpPre->predecossor;
            }
            n++;
          }
        }
      }
    }

    printf("Maximum path length: %d\n", max_pathLength);
    for (int i = 0; i < num_path; i++) {
      for (int j = 0; j < max_pathLength; j++) {
        if (j == max_pathLength - 1) {
          printf("%d", max_path[i][j]);
        } else {
          printf("%d -> ", max_path[i][j]);
        }
      }
      printf("\n");
    }
  }
  }
};
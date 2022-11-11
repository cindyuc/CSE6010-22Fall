#include "divisorgraph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define UNUSED(x) (void)(x)

#define MAX_VERTICES_NUM 1000
#define INF INT_MAX

Vertex *newVertex(int value) {
  Vertex *newVertex = malloc(sizeof(Vertex));
  if (newVertex == NULL) {
    printf("Allocation failure");
  } else {
    newVertex->value = value;
    newVertex->weight = 1;
    newVertex->next = NULL;
  }
  return newVertex;
}

void initialize(Vertex **vertexarray) {
  for (int i = 0; i < MAX_VERTICES_NUM + 5; i++) {
    Vertex *new = newVertex(i + 1);
    vertexarray[i] = new;
  }
}

void buildGraph(Vertex **vertexarray, int numvertices) {
  Vertex *tmpVertex = vertexarray[0];

  // there will an edge from the vertex with value 1 to every other vertices in
  // the graph
  for (int i = 2; i < numvertices + 1; i++) {
    // printf("n");
    Vertex *new = newVertex(i);
    // UNUSED(newVertex);
    tmpVertex->next = new;
    tmpVertex = new;
  }

  // // adding an edge for vertex i (i != 1)
  for (int i = 1; i < numvertices; i++) {
    tmpVertex = vertexarray[i];
    for (int j = i + 2; j < numvertices + 1; j++) {
      if (j % (i + 1) == 0) {
        Vertex *new = newVertex(j);
        tmpVertex->next = new;
        tmpVertex = new;
      }
    }
  }
}

bool relax(Vertex *u, Vertex *v, int *distance, int *predecessor, int *set_Q) {
  if (distance[u->value - 1] + u->weight > distance[v->value - 1]) {
    distance[v->value - 1] = distance[u->value - 1] + u->weight;
    set_Q[v->value - 1] = distance[v->value - 1];
    predecessor[v->value - 1] = u->value;
    return true;
  }
  return false;
}

void printMaximumPath(int *distance, int *predecessor, int numvertices) {
  int max_distance = -1;
  int num_path = 0;
  int sink[numvertices];

  // get the maximum distance from source vertex
  for (int i = 0; i < numvertices; i++) {
    if (distance[i] > max_distance) {
      max_distance = distance[i];
      num_path = 1;

      memset(sink, 0, sizeof(sink));
      sink[0] = i + 1;
    } else if (distance[i] == max_distance) {
      // printf("%d\n", i+1);
      num_path++;
      sink[num_path - 1] = i + 1;
    }
  }

  // get the maximum paths
  int max_path[num_path][max_distance + 1];
  for (int i = 0; i < num_path; i++) {
    int currVertex = sink[i];
    for (int j = max_distance; j >= 0; j--) {
      max_path[i][j] = currVertex;
      currVertex = predecessor[currVertex - 1];
    }
  }

  printf("The length of maximum-length path in this divisor graph is %d.\n",
         max_distance);
  printf("These paths are:\n");
  for (int i = 0; i < num_path; i++) {
    for (int j = 0; j < max_distance + 1; j++) {
      if (j == max_distance) {
        printf("%d\n", max_path[i][j]);
      } else {
        printf("%d -> ", max_path[i][j]);
      }
    }
  }
}

void findPaths(Vertex **vertexarray, int numvertices, char bf) {
  int distance[numvertices];
  int predecessor[numvertices];
  int set_Q[numvertices];
  int size_Q = numvertices;
  memset(distance, 0, sizeof(distance));
  memset(predecessor, 0, sizeof(predecessor));
  memset(set_Q, 0, sizeof(set_Q));
  predecessor[0] = 1;

  switch (bf) {
  // Bellman-Ford algorithm
  case 'b': {
    bool flag = true;

    while (flag) {
      flag = false;

      for (int i = 0; i < numvertices; i++) {
        Vertex *u = vertexarray[i];
        Vertex *v = u->next;
        while (v != NULL) {
          if (relax(u, v, distance, predecessor, set_Q)) {
            flag = true;
          }
          v = v->next;
        }
      }
    }
    break;
  }
    // Dijkstra's algorithm
  case 'd': {
    while (size_Q > 0) {
      int u_idx = 0;
      int max_distance_q = -1;

      // find the vertex in Q with maximum value of distance.
      // If there are multiple vertices with the same maximum distance, then
      // record the first vertex INF means the vertex doesn't in set_Q
      for (int i = 0; i < numvertices; i++) {
        if (set_Q[i] != INF && set_Q[i] > max_distance_q) {
          max_distance_q = set_Q[i];
          u_idx = i;
        }
      }

      // get vertex u and remove u from set Q
      Vertex *u = vertexarray[u_idx];
      set_Q[u_idx] = INF;
      size_Q--;

      // For each vertex w in Q, where (u, w) exists
      Vertex *v = u->next;
      while (v != NULL) {
        if (set_Q[v->value - 1] != INF) {
          relax(u, v, distance, predecessor, set_Q);
        }
        v = v->next;
      }
    }
  }
  }
  printMaximumPath(distance, predecessor, numvertices);
}

void finalize(Vertex **vertexarray) {
  for (int i = 0; i < MAX_VERTICES_NUM + 5; i++) {
    Vertex *tmpVertex = vertexarray[i]->next;
    while (tmpVertex != NULL) {
      vertexarray[i]->next = tmpVertex->next;
      free(tmpVertex);
      tmpVertex = vertexarray[i]->next;
    }
    free(vertexarray[i]);
  }
}
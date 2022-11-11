#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define INF 999999

void printSolution(int V, int graph[][V]) {
  printf("The shortest distances between every pair of vertices are in "
         "following matrix:\n");
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (graph[i][j] == INF) {
        printf("%s", "INF");
      } else {
        printf("%d ", graph[i][j]);
      }
    }
    printf("\n");
  }
}

void floyWarshall(int V, int graph[][V]) {
  int dist[V][V];

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  printSolution(V, dist);
}

int main() {
  int graph[5][5] = {{6, 23, 88, INF, 29},
                     {68, INF, 10, 9, 0},
                     {8, 0, 3, 77, 3},
                     {9, 35, 15, INF, 0},
                     {23, 0, 5, 0, 22}};
  int V = sizeof(graph[0]) / sizeof(graph[0][0]);

  floyWarshall(V, graph);

  return 0;
}
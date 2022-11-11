#include <limits.h>
#include <stdio.h>

struct Edge {
  int src, destination, weight;
};

struct Graph {
  int V, E;

  struct Edge *Edge;
};

struct Graph *createGraph(int V, int E) {
  struct Graph new_graph;
  struct Graph* graph = &new_graph;
  graph->V = V;
  graph->E = E;
  struct Edge Edge[E];
  graph->Edge = Edge;

  return graph;
};

void printArray(int dist[], int n) {
  printf("Vertex  Distance from Source\n");
  for (int i = 0; i < n; i++) {
    printf("%d \t\t %d\n", i, dist[i]);
  }
}

void BellmanFord(struct Graph *graph, int src) {
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  // initialize distances from src to all other vertices as INFINITE
  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
  }
  dist[src] = 0;

  // relax all edges |V|-1 times
  for (int i = 1; i < V; i++) {
    for (int j = 0; i < E; i++) {
      int u = graph->Edge[j].src;
      int v = graph->Edge[j].destination;
      int weight = graph->Edge[j].weight;

      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  printArray(dist, V);

  return;
}

int main() {

  int V = 5;
  int E = 8;
  struct Graph* graph = createGraph(V, E);

  // add edge 0-1
  graph->Edge[0].src = 0;
  graph->Edge[0].destination = 1;
  graph->Edge[0].weight = -1;

  // add edge 0-2
  graph->Edge[1].src = 0;
  graph->Edge[1].destination = 2;
  graph->Edge[1].weight = 12;

  // add edge 1-4
  graph->Edge[2].src = 1;
  graph->Edge[2].destination = 4;
  graph->Edge[2].weight = -8;

  // add edge 1-3
  graph->Edge[3].src = 1;
  graph->Edge[3].destination = 3;
  graph->Edge[3].weight = 5;

  // add edge 3-4
  graph->Edge[4].src = 3;
  graph->Edge[4].destination = 4;
  graph->Edge[4].weight = 7;

    // Function call
  BellmanFord(graph, 0);

  return 0;
}
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float max(float arr[], int N) {
  float max = arr[0];
  for (int i = 1; i < N; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void cal_heat(float heat[], int N, float scale) {
  // float *heat_new = malloc(N * sizeof(float));
  static int num_steps = 2000;

  for (int i = 0; i < num_steps; i++) {
    float heat_new[N];
#pragma omp parallel for
    for (int j = 0; j < N; j++) {
      if (j == 0) {
        heat_new[j] = heat[j] + scale * (2 * heat[j + 1] - 2 * heat[j]);
      } else if (j == N - 1) {
        heat_new[j] = heat[j] + scale * (2 * heat[j - 1] - 2 * heat[j]);
      } else {
        heat_new[j] =
            heat[j] + scale * (heat[j + 1] + heat[j - 1] - 2 * heat[j]);
      }
    }
    memcpy(heat, heat_new, N * sizeof(float));
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("INPUT ERROR! PLEASE ENTER A REASONABLE ARRAY SIZE!\n");
    return 1;
  }

  // size of the array
  int N = atoi(argv[1]);

  // set random value using a time-dependent seed
  srand(time(NULL));
  int initial = rand() % N;
  int H_init = 50;
  // read initial heat location from command-line or using random value
  if (argc > 2) {
    initial = atoi(argv[2]);
  }

  // declare initialize the heat
  float *heat = malloc(N * sizeof(float));
  memset(heat, 0, N * sizeof(float));
  heat[initial] = H_init;

  cal_heat(heat, N, 0.1);
  float max_heat = max(heat, N);

  // Modified binary search
  // if the maximum heat using H_init = 50 is not more than 1, then
  int L = 0;
  if (max_heat <= 1) {
    while (max_heat <= 1) {
      H_init *= 2;
      memset(heat, 0, N * sizeof(float));
      heat[initial] = H_init;

      cal_heat(heat, N, 0.1);
      max_heat = max(heat, N);
    }
    L = H_init / 2;
  }

  // if the maximum heat using H_init = 50 is more than 1, then
  int H = H_init;
  while (max_heat > 1) {
    H_init = (L + H) / 2;
    memset(heat, 0, N * sizeof(float));
    heat[initial] = H_init;

    cal_heat(heat, N, 0.1);
    max_heat = max(heat, N);

    H = H_init;
  }

  printf("the value of initial heat is %d\nthe maximum heat temperature is "
         "%lf\n",
         H_init, max_heat);

  free(heat);

  return 0;
}
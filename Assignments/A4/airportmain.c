// #include "flights_io.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNUSED(x) (void)(x)

int main(int argc, char *argv[]) {
  // default sort algorithm is insertion sort
  char sort = 'i';

  if (argc == 3) {
    if (*argv[2] == 'i') {
      ;
    } else if (*argv[2] == 'h') {
      sort = 'h';
    } else if (*argv[2] == 'm') {
      sort = 'm';
    } else {
      printf("INVALID INPUT!");
      return 1;
    }
  } else if (argc < 2 || argc > 3) {
    printf("INVALID INPUT!");
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error opening file");

    return 1;
  }

  // read data line by line from .csv file
  int num_ArrivalsAirports;
  fscanf(file, "%d", &num_ArrivalsAirports);

  char buff[64];
  int num_Flights = 0;
  Flight *flights = (Flight *)malloc((num_Flights + 5) * sizeof(Flight));
  while ((fscanf(file, "%s", buff)) != EOF) {
    num_Flights++;
    flights = (Flight *)realloc(flights, (num_Flights + 5) * sizeof(Flight));
    parseFlight(buff, flights + num_Flights - 1);
  }
  fclose(file);

  // calculate average delay time for each airport
  Airport *airports = (Airport *)malloc(num_ArrivalsAirports * sizeof(Airport));
  createAirport(airports, num_ArrivalsAirports, num_Flights, flights);
  updateAirport(airports, num_ArrivalsAirports, num_Flights, flights);

  double time_spent = 0.0;
  clock_t begin = clock();

  if (sort == 'i') {
    insertionSortAirports(airports, num_ArrivalsAirports);
  } else if (sort == 'h') {
    heapSortAirports(airports, num_ArrivalsAirports);
  } else if (sort == 'm') {
    mergeSortAirports(airports, 0, num_ArrivalsAirports - 1);
  }

  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time elpased is %f seconds\n", time_spent);

  // write to file
  FILE *output = fopen("./sortedoutput.txt", "w");
  fprintf(output, "Airport Abbrev\t\tDelay-All\tAvg Delay-Late\t#Arrivals"
                  "\t#Late Arrivals\n");

  for (int i = 0; i < num_ArrivalsAirports; i++) {
    fprintf(output, "%3s\t\t\t\t\t%5.3f\t\t%5.3f\t\t\t\t%d\t\t\t%d\n",
            airports[i].abbrev, airports[i].delayAll, airports[i].avgDelay,
            airports[i].totalFlight, airports[i].totalDelayedFlight);
  }

  free(flights);
  free(airports);
  fclose(output);

  return 0;
}

#include "flights_io.h"

int timeToMinute(int time) {
  int hour = time / 100;
  int minute = time % 100;
  return hour * 60 + minute;
}

int calculateDelay(Flight *flight) {
  int scheduledArrivalTime = timeToMinute(flight->scheduledArrivalTime);
  int actualArrivalTime = timeToMinute(flight->actualArrivalTime);
  int delayTime;

  // calculate delays when the flight arrivals are around midnight
  if (actualArrivalTime < scheduledArrivalTime - 120) {
    actualArrivalTime += 24 * 60;
  } else if (actualArrivalTime > scheduledArrivalTime + 60 * 23) {
    // calculate earlys when the flight arrivals are around midnight
    scheduledArrivalTime += 24 * 60;
  }

  delayTime = actualArrivalTime - scheduledArrivalTime;

  if (delayTime <= 0) {
    return 0;
  }
  return delayTime;
}

void parseFlight(char *buff, Flight *flight) {
  char *token = strtok(buff, ",");
  strcpy(flight->airlineCode, token);

  token = strtok(NULL, ",");
  flight->flightNumber = atoi(token);

  token = strtok(NULL, ",");
  strcpy(flight->departureAirport, token);

  token = strtok(NULL, ",");
  strcpy(flight->arrivalAirport, token);

  token = strtok(NULL, ",");
  flight->scheduledDepartureTime = atoi(token);

  token = strtok(NULL, ",");
  flight->actualDepartureTime = atoi(token);

  token = strtok(NULL, ",");
  flight->scheduledArrivalTime = atoi(token);

  token = strtok(NULL, ",");
  flight->actualArrivalTime = atoi(token);

  flight->delayTime = calculateDelay(flight);
};

void printFlights(Flight *flights, int n) {
  for (int i = 0; i < n; i++) {
    Flight *flight = &flights[i];
    printf("%s %d %s %s %d %d %d %d %d\n", flight->airlineCode,
         flight->flightNumber, flight->departureAirport, flight->arrivalAirport,
         flight->scheduledDepartureTime, flight->actualDepartureTime,
         flight->scheduledArrivalTime, flight->actualArrivalTime,
         flight->delayTime);
  }
}

void createAirport(Airport *airports, int num_airports, int num_flight, Flight *flight) {
  int pointer = 0;
  for (int i = 0; i < num_flight; i++) {
    int found = 0;
    for (int j = 0; j < pointer; j++) {
      if (strcmp(airports[j].abbrev, flight[i].arrivalAirport) == 0) {
        found = 1;
        airports[j].totalFlight++;
        break;
      }
    }
    if (!found) {
      strcpy(airports[pointer].abbrev, flight[i].arrivalAirport);
      airports[pointer].totalDelayTime = 0;
      airports[pointer].totalFlight = 1;
      airports[pointer].totalDelayedFlight = 0;
      airports[pointer].avgDelay = 0;
      pointer++;
    }
  }
}

void updateAirport(Airport *airports, int num_airports, int num_flight, Flight *flight) {
  for (int i = 0; i < num_flight; i++) {
    for (int j = 0; j < num_airports; j++) {
      if (strcmp(airports[j].abbrev, flight[i].arrivalAirport) == 0) {
        airports[j].totalDelayTime += flight[i].delayTime;
        airports[j].delayAll = (float)airports[j].totalDelayTime / (float)airports[j].totalFlight;
        if (flight[i].delayTime > 0) {
          airports[j].totalDelayedFlight++;
        }
        if (airports[j].totalDelayedFlight > 0) {
          airports[j].avgDelay = (float)airports[j].totalDelayTime / (float)airports[j].totalDelayedFlight;
        }
        break;
      }
    }
  }
}

void printAirports(Airport *airports, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s %d %d %d %.3f %.3f\n", airports[i].abbrev, airports[i].totalDelayTime,
           airports[i].totalFlight, airports[i].totalDelayedFlight, airports[i].avgDelay, airports[i].delayAll);
  }
}
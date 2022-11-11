#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Flight {
  char airlineCode[3];
  int flightNumber;
  char departureAirport[4], arrivalAirport[4];
  int scheduledDepartureTime, actualDepartureTime;
  int scheduledArrivalTime, actualArrivalTime;
  int delayTime;
} Flight;

typedef struct Airport {
  char abbrev[4];
  int totalDelayTime;
  int totalFlight, totalDelayedFlight;
  float avgDelay, delayAll;
} Airport;

void parseFlight(char *buff, Flight *flight);

void printFlights(Flight *flights, int n);

int timeToMinute(int time);

int calculateDelay(Flight *flight);

void createAirport(Airport *airports, int num_airports, int num_flight, Flight *flight);

void updateAirport(Airport *airports, int num_airports, int num_flight, Flight *flight);

void printAirports(Airport *airports, int n);
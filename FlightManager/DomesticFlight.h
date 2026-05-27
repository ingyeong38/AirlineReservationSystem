#pragma once
#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H
#include <iostream>
#include "Flight.h"
using namespace std;

class DomesticFlight : public Flight{
public:
	DomesticFlight(string flightCode, string departure, string arrival, int distance, int basePrice);
	int calculateFare();
	string getFlightClass();
};
#endif // !DOMESTICFLIGHT_H

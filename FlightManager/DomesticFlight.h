#pragma once
#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H
#include <iostream>
#include "Flight.h"
using namespace std;

class DomesticFlight : public Flight{
protected:
	void printFare();
	string getFlightClass();
public:
	DomesticFlight(string flightCode, string departure, string arrival, int distance, int basePrice);
	int calculateFare();
};
#endif // !DOMESTICFLIGHT_H

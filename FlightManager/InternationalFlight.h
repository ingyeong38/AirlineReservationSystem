#pragma once
#ifndef INTERNATIONALFLIGHT_H
#define INTERNATIONALFLIGHT_H
#include <iostream>
#include "Flight.h"
using namespace std;

class InternationalFlight : public Flight{
private:
	int fuelSurcharge;	// 유류할증료(원)
	int airportTax;		// 공항세
protected:
	void printFare();
	string getFlightClass();
public:
	InternationalFlight(string flightCode, string departure, string arrival, int distance, int basePrice, int fuelSurcharge, int airportTax);
	int calculateFare();
};
#endif // !INTERNATIONALFLIGHT_H

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
public:
	InternationalFlight(string flightCode, string departure, string arrival, int distance, int basePrice, int fuelSurcharge, int airportTax);
	int calculateFare();
	string getFlightClass();
	void showFareDetail(double multiplier);
};
#endif // !INTERNATIONALFLIGHT_H

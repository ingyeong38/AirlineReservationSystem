#include <iostream>
#include "Flight.h"
#include "InternationalFlight.h"
using namespace std;

InternationalFlight::InternationalFlight(string flightCode, string departure, string arrival, int distance, int basePrice, int fuelSurcharge, int airportTax) 
	: Flight(flightCode, departure, arrival, distance, basePrice),
	  fuelSurcharge(fuelSurcharge),
	  airportTax(airportTax) { }

int InternationalFlight::calculateFare() {
	return getBasePrice() + fuelSurcharge + airportTax;
}

string InternationalFlight::getFlightClass() {
	return "±¹Á¦¼±";
}

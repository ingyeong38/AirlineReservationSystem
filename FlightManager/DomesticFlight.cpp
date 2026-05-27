#include <iostream>
#include "Flight.h"
#include "DomesticFlight.h"
using namespace std;

DomesticFlight::DomesticFlight(string flightCode, string departure, string arrival, int distance, int basePrice) 
	: Flight(flightCode, departure, arrival, distance, basePrice)  { }

int DomesticFlight::calculateFare() {
	return getBasePrice() * (getDistance() / 100);
}

string DomesticFlight::getFlightClass() {
	return "±¹³»¼±";
}
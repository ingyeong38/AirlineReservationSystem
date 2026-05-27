#include <iostream>
#include "Flight.h"
#include "CharterFlight.h"
using namespace std;

CharterFlight::CharterFlight(string flightCode, string departure, string arrival, int distance, int fixedPrice)
	: Flight(flightCode, departure, arrival, distance),
	  fixedPrice(fixedPrice) { }

int CharterFlight::calculateFare() {
	return fixedPrice;
}

string CharterFlight::getFlightClass() {
	return "Àü¼¼±â";
}
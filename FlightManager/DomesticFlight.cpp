#include <iostream>
#include "Flight.h"
#include "DomesticFlight.h"
using namespace std;

DomesticFlight::DomesticFlight(string flightCode, string departure, string arrival, int distance, int basePrice) 
	: Flight(flightCode, departure, arrival, distance, basePrice)  { }

int DomesticFlight::calculateFare() {
	return basePrice * distance / 100;
}

string DomesticFlight::getFlightClass() {
	return "국내선";
}

void DomesticFlight::printFare() {
	cout << " 기본 요금(거리 계산):\t" << calculateFare() << "원" << endl;
}
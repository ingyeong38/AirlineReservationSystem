#include <iostream>
#include "Flight.h"
#include "InternationalFlight.h"
using namespace std;

InternationalFlight::InternationalFlight(string flightCode, string departure, string arrival, int distance, int basePrice, int fuelSurcharge, int airportTax) 
	: Flight(flightCode, departure, arrival, distance, basePrice)
{ 
	this->fuelSurcharge = fuelSurcharge;
	this->airportTax = airportTax;
}

int InternationalFlight::calculateFare() {
	return basePrice + fuelSurcharge + airportTax;
}

void InternationalFlight::printFare() {
	cout << " 기본 요금:\t\t" << basePrice << "원" << endl;
	cout << " + 유류할증료:\t\t" << fuelSurcharge << "원" << endl;
	cout << " + 공항세:\t\t" << airportTax << "원" << endl;
}

string InternationalFlight::getFlightClass() {
	return "국제선";
}
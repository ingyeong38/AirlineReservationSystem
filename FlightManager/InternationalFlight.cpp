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

int InternationalFlight::calculateFare() {			// 요금 계산
	return basePrice + fuelSurcharge + airportTax;	// 기본 + 유류할증료 + 공항세
}

void InternationalFlight::printFare() {		// 요금 상세 출력용
	cout << " 기본 요금:\t\t" << basePrice << "원" << endl;
	cout << " + 유류할증료:\t\t" << fuelSurcharge << "원" << endl;
	cout << " + 공항세:\t\t" << airportTax << "원" << endl;
}

string InternationalFlight::getFlightClass() {
	return "국제선";
}
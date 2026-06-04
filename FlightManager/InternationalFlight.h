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
	int calculateFare();		// 요금 계산
	void printFare();			// 항공편에 따른 요금 출력
	string getFlightClass();	// "국제선" 반환 
public:
	InternationalFlight(string flightCode, string departure, string arrival, int distance, int basePrice, int fuelSurcharge, int airportTax);
};
#endif // !INTERNATIONALFLIGHT_H

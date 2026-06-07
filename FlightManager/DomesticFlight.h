#pragma once
#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H
#include <iostream>
#include "Flight.h"
using namespace std;

class DomesticFlight : public Flight{
private:
	int calculateFare();		// 요금 계산
	void printFare();			// 항공편에 따른 요금 출력
public:
	DomesticFlight(string flightCode, string departure, string arrival, int distance, int basePrice);
	string getFlightClass();	// "국내선" 반환 
};
#endif // !DOMESTICFLIGHT_H

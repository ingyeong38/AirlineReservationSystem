#pragma once
#ifndef CHARTERFLIGHT_H
#define CHARTERFLIGHT_H
#include <iostream>
using namespace std;

class CharterFlight : public Flight {
private:
	int fixedPrice;		// 고정 요금(원)
public:
	CharterFlight(string flightCode, string departure, string arrival, int distance, int fixedPrice);
	int calculateFare();
	string getFlightClass();
};
#endif // !CHARTERFLIGHT_H

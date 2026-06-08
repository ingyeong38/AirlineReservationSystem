#pragma once
#ifndef CHARTERFLIGHT_H
#define CHARTERFLIGHT_H
#include <iostream>
using namespace std;

class CharterFlight : public Flight {
private:
	int fixedPrice;		// 고정 요금(원)
	int calculateFare();	// 요금 계산
	void printFare();		// 요금 계산 과정 출력

public:
	CharterFlight(string flightCode, string departure, string arrival, int distance, int fixedPrice);
	string getFlightClass();
	bool hasSeatClass() { return false; }
};
#endif // !CHARTERFLIGHT_H

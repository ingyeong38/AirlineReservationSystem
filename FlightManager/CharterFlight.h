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
	int calculateFare();	// 요금 계산
	string getFlightClass();	// 항공편(전세기) 반환
	void showFareDetail(double multiplier);	// 
	bool hasSeatClass() { return false; }	// 
};
#endif // !CHARTERFLIGHT_H

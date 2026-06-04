#include <iostream>
#include "Flight.h"
#include "DomesticFlight.h"
using namespace std;

DomesticFlight::DomesticFlight(string flightCode, string departure, string arrival, int distance, int basePrice) 
	: Flight(flightCode, departure, arrival, distance, basePrice)  { }

int DomesticFlight::calculateFare() {	// 요금 계산
	return basePrice * distance / 100;	// 기본 * 거리 / 100
}

void DomesticFlight::printFare() {		// 요금 상세 출력용
	cout << " 기본 요금(거리 계산):\t" << basePrice * distance / 100 << "원" << endl;
}

string DomesticFlight::getFlightClass() {
	return "국내선";
}
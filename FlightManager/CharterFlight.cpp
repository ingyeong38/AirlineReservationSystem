#include <iostream>
#include "Flight.h"
#include "CharterFlight.h"
using namespace std;

CharterFlight::CharterFlight(string flightCode, string departure, string arrival, int distance, int fixedPrice)
	: Flight(flightCode, departure, arrival, distance, fixedPrice),
	  fixedPrice(fixedPrice) { }

int CharterFlight::calculateFare() {
	return fixedPrice;
}

string CharterFlight::getFlightClass() {
	return "전세기";
}

void CharterFlight::printFare() {
	cout << " 전세기 고정 요금:\t" << fixedPrice << "원" << endl;
	cout << " (좌석 등급 배수 미적용)" << endl;
}
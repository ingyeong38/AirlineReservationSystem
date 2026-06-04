#include <iostream>
#include "Flight.h"
#include "CharterFlight.h"
using namespace std;

CharterFlight::CharterFlight(string flightCode, string departure, string arrival, int distance, int fixedPrice)
	: Flight(flightCode, departure, arrival, distance, fixedPrice)
{ 
	this->fixedPrice = fixedPrice;
}

int CharterFlight::calculateFare() {	// 요금 계산
	return fixedPrice;
}

void CharterFlight::printFare() {		// 요금 상세 출력용
	cout << " 전세기 고정 요금:\t" << fixedPrice << "원" << endl;
	cout << " (좌석 등급 배수 미적용)" << endl;
}

string CharterFlight::getFlightClass() {
	return "전세기";
}
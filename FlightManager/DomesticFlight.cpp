#include <iostream>
#include "Flight.h"
#include "DomesticFlight.h"
using namespace std;

DomesticFlight::DomesticFlight(string flightCode, string departure, string arrival, int distance, int basePrice) 
	: Flight(flightCode, departure, arrival, distance, basePrice)  { }

int DomesticFlight::calculateFare() {
	return getBasePrice() * getDistance() / 100;
}

string DomesticFlight::getFlightClass() {
	return "국내선";
}

void DomesticFlight::showFareDetail(double multiplier) {
	int basePrice = calculateFare();
	int finalPrice = (int)(basePrice * multiplier);

	cout << "\n -------------------------------" << endl;
	cout << " [요금 상세]" << endl;
	cout << " 기본 요금(거리 계산):\t" << basePrice << "원" << endl;
	cout << " x 좌석 등급(x" << multiplier << ")" << endl;
	cout << " -------------------------------" << endl;
	cout << " 최종 결제 금액:\t" << finalPrice << "원" << endl;
}
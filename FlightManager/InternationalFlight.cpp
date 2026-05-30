#include <iostream>
#include "Flight.h"
#include "InternationalFlight.h"
using namespace std;

InternationalFlight::InternationalFlight(string flightCode, string departure, string arrival, int distance, int basePrice, int fuelSurcharge, int airportTax) 
	: Flight(flightCode, departure, arrival, distance, basePrice),
	  fuelSurcharge(fuelSurcharge),
	  airportTax(airportTax) { }

int InternationalFlight::calculateFare() {
	return getBasePrice() + fuelSurcharge + airportTax;
}

string InternationalFlight::getFlightClass() {
	return "국제선";
}

void InternationalFlight::showFareDetail(double multiplier) {
	int basePrice = getBasePrice();		// 기본 요금
	int totalPrice = calculateFare();	// 기본 요금 + 유류할증료 + 공항세
	int finalPrice = (int)(totalPrice* multiplier);

	cout << "\n -------------------------------" << endl;
	cout << " [요금 상세]" << endl;
	cout << " 기본 요금:\t\t" << basePrice << "원" << endl;
	cout << " + 유류할증료:\t\t " << fuelSurcharge << "원" << endl;
	cout << " + 공항세:\t\t " << airportTax << "원" << endl;
	cout << " x 좌석 등급(x" << multiplier << ")" << endl;
	cout << " -------------------------------" << endl;
	cout << " 최종 결제 금액:\t" << finalPrice << "원" << endl;
}

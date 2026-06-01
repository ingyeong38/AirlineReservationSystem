#include <iostream>
#include "Flight.h"
using namespace std;

Flight::Flight(string flightCode, string departure, string arrival, int distance, int basePrice) {
	this->flightCode = flightCode;
	this->departure = departure;
	this->arrival = arrival;
	this->distance = distance;
	this->basePrice = basePrice;
}
string Flight::getFlightCode() {
	return flightCode;
}

void Flight::showFareDetail(double multiplier) {
	int finalPrice;
	if (hasSeatClass())
		finalPrice = int(calculateFare() * multiplier);
	else
		finalPrice = calculateFare();

	cout << "\n -------------------------------" << endl;
	cout << " [요금 상세]" << endl;
	printFare();
	if(hasSeatClass())
		cout << " x 좌석 등급(x" << multiplier << ")" << endl;
	cout << " -------------------------------" << endl;
	cout << " 최종 결제 금액:\t" << finalPrice << "원" << endl;
}

void Flight::printSummary() {
	cout << "\t" << flightCode << "\t|  " << departure << "  →  " << arrival << "\t| " << getFlightClass() <<endl; // endl 앞에 국내선/국제선/전세기 출력 변수 추가
}

void Flight::printTicketInfo() {
	cout << " 편명: " << flightCode << " (" << getFlightClass() << ")" << endl;
	cout << " 구간: " << departure << " → " << arrival << endl;
}

void Flight::printDetail() {
	cout << "==============================" << endl;
	cout << " 선택하신 항공편 정보" << endl;
	cout << " 편명: " << flightCode << endl;
	cout << " 구간: " << departure << "  →  " << arrival << endl;
	cout << " 정보: " << getFlightClass() << endl;
	cout << " 기본 요금: " << basePrice << "원" << endl;
	cout << "==============================" << endl;
}
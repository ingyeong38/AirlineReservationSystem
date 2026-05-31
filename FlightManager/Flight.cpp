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
string Flight::getDeparture() {
	return departure;
}
string Flight::getArrival() {
	return arrival;
}
int Flight::getBasePrice() {
	return basePrice;
}
int Flight::getDistance() {
	return distance;
}
void Flight::printSummary() {
	cout << "\t" << flightCode << "\t|  " << departure << "  →  " << arrival << "\t| " << getFlightClass() <<endl; // endl 앞에 국내선/국제선/전세기 출력 변수 추가
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
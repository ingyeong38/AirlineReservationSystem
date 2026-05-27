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
int Flight::getBasePrice() {
	return basePrice;
}
int Flight::getDistance() {
	return distance;
}
void Flight::printInfo() {
	cout << "\t" << flightCode << "\t|  " << departure << "  →  " << arrival << "\t| " << getFlightClass() <<endl; // endl 앞에 국내선/국제선/전세기 출력 변수 추가
}
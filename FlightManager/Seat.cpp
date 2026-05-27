#include <iostream>
#include "Seat.h"
using namespace std;

Seat::Seat(string seatNumber, double priceMultiplier) {
	this->seatNumber = seatNumber;
	this->priceMultiplier = priceMultiplier;
}
string Seat::getSeatNumber() {
	return seatNumber;
}
double Seat::getPriceMultiplier() {
	return priceMultiplier;
}

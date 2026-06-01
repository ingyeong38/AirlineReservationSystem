#include <iostream>
#include <string>
#include "Seat.h"
using namespace std;

Seat::Seat(double priceMultiplier) {
	this->priceMultiplier = priceMultiplier;
}

double Seat::getPriceMultiplier() {
	return priceMultiplier;
}

bool Seat::isValidSeat(string seatId) {
	int col = seatId[0] - 'A';
	int row = stoi(seatId.substr(1));
	return (col >= 0 && col < getMaxCols()) && (row >= 1 && row <= getMaxRows());
}
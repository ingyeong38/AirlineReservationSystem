#pragma once
#ifndef SEAT_H
#define SEAT_H
#include <iostream>
using namespace std;

class Seat {
private:
	string seatNumber;		// 좌석 번호(ex: 2A)
	double priceMultiplier;	// 가격 배수(1.0/2.5/4.0)
public:
	Seat(string seatNumber, double priceMultiplier);
	double getPriceMultiplier();
	virtual string getClassName() = 0;
	virtual int getMaxRows() = 0;
	virtual int getMaxCols() = 0;
	bool isValidSeat(string seatId);
};
#endif // !SEAT_H

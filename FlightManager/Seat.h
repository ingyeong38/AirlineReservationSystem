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
	Seat(double priceMultiplier);
	double getPriceMultiplier();	// 가격 배수 반환
	virtual string getClassName() = 0;	// 각 클래스의 좌석 등급 반환
	virtual int getMaxRows() = 0;	// 각 클래스의 최대 행 크기 반환
	virtual int getMaxCols() = 0;	// 각 클래스의 최대 열 크기 반환
	bool isValidSeat(string seatId);	// 좌석 범위 확인
};
#endif // !SEAT_H

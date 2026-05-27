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
	string getSeatNumber();	// 좌석 번호 반환
	double getPriceMultiplier();	// 가격 배수 반환

	// getService()와 getClassName()을 순수 가상 함수로 선언
	virtual string getClassName()=0;	// 등급명 반환
};
#endif // !SEAT_H

#pragma once
#ifndef SEAT_H
#define SEAT_H
#include <iostream>
using namespace std;

class Seat {
private:
	double priceMultiplier;	// 가격 배수(1.0/2.5/4.0)
	bool isValidSeat(string seatNum);	// 좌석 범위 검증
protected:
	virtual int rowCount() = 0;	// 각 클래스의 최대 행 크기 반환
	virtual int colCount() = 0;	// 각 클래스의 최대 열 크기 반환
public:
	Seat(double priceMultiplier);
	virtual ~Seat() {}
	double getPriceMultiplier();	// 가격 배수 반환
	virtual string getClassName() = 0;	// 각 클래스의 좌석 등급 반환
	void printSeatMap(bool seatStatus[]);	// 좌석 배치도 출력
	bool reserveSeat(string seatNum, bool seatStatus[]);		// 예약 가능한 좌석인지
	void releaseSeat(string seatNum, bool seatStatus[]);	// 결제 취소 시 좌석 해제
};
#endif // !SEAT_H

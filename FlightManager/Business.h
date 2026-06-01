#pragma once
#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;

class Business : public Seat{
public:
	Business(string seatNumber);
	static void getSeatMap(bool seatStatus[]);		// 좌석 배치도 출력
	string getClassName() { return "Business"; }	// 좌석 등급(Business) 반환
	int getMaxRows() { return 5; }		// 행 크기(5) 반환
	int getMaxCols() { return 4; }		// 열 크기(4) 반환
};
#endif // !BUSINESS_H

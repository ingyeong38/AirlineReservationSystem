#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
using namespace std;

class Flight {
private:
	string flightCode;		// 항공편 편명(ex: KE0987)
	string departure;		// 출발지 공항 코드(ex: ICN)
	string arrival;			// 도착지 공항 코드(ex: LAX)
	int distance;			// 운항 거리(km)
	int basePrice;			// 기본요금(원)
public:
	Flight(string flightCode, string departure, string arrival, int distance, int basePrice = 0);
	string getFlightCode();		// 편명 반환
	int getDistance();			// 운항 거리 반환
	int getBasePrice();			// 기본요금 반환	// 기존 UML에서 추가함
	virtual int calculateFare()=0;// 요금 계산
	virtual string getFlightClass() = 0;	// 비행기 정보 출력
	void printSummary();			// 항공편 정보 출력
	void printDetail();
};
#endif // !FLIGHT_H

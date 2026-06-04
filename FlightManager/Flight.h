#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
using namespace std;

class Flight {
protected:
	int distance;			// 운항 거리(km)
	int basePrice;			// 기본요금(원)

	virtual int calculateFare() = 0;		// 요금 계산
	virtual void printFare() = 0;			// 항공편에 따른 요금 출력
	virtual string getFlightClass() = 0;	// 비행기 정보 출력

public:
	Flight(string flightCode, string departure, string arrival, int distance, int basePrice = 0);

	string flightCode;		// 항공편 편명(ex: KE0987)
	string departure;		// 출발지 공항 코드(ex: ICN)
	string arrival;			// 도착지 공항 코드(ex: LAX)

	int showFareDetail(double multiplier); // 최종 계산 요금 출력
	virtual bool hasSeatClass() { return true; }	// 전세기는 좌석 등급 없음
	void printSummary();			// 항공편 목록 출력용
	void printDetail();				// 항공편 세부 정보 출력
	void printTicketInfo();			// E-Ticket에서 정보 출력
};	
#endif // !FLIGHT_H

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
protected:
	int distance;			// 운항 거리(km)
	int basePrice;			// 기본요금(원)
	virtual void printFare() = 0;	// 항공편별 요금 항목만 출력
	virtual string getFlightClass() = 0;	// 비행기 정보 출력
public:
	Flight(string flightCode, string departure, string arrival, int distance, int basePrice = 0);
	string getFlightCode();		// 편명 반환
	virtual int calculateFare()=0;// 요금 계산
	void showFareDetail(double multiplier); // 최종 계산 요금 출력
	virtual bool hasSeatClass() { return true; }
	void printSummary();			// 항공편 정보 출력
	void printDetail();
	void printTicketInfo();
};	
#endif // !FLIGHT_H

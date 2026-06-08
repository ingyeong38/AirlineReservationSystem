#pragma once
#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
using namespace std;

class Passenger {
private:
	int age;			// 승객 나이
	string passportNo;	// 여권번호

	int selectedFlight;		// 선택한 항공편
	int selectedSeatClass;		// 선택한 좌석 등급
	string selectedSeat;	// 선택한 좌석

public:
	Passenger(string name, int age, string passportNo);	// 생성자
	string name;			// 승객 이름

	void printInfo();		//  승객 정보 등록 확인용
	void printTicket();		// E-Ticket에서 승객 정보 출력

	void setSelectedFlight(int selectedFlight);		// 항공편 선택
	void setSelectedSeatClass(int selectedSeatClass);	// 좌석 등급 선택
	void setSelectedSeat(string selectedSeat);	// 좌석 선택

	inline string getPassportNo() { return passportNo; }			// 여권번호 반환
	inline int getSelectedFlight() { return selectedFlight; }		// 선택한 항공편 반환
	inline int getSelectedSeatClass() { return selectedSeatClass; }	// 선택한 좌석 등급 반환
	inline string getSelectedSeat() { return selectedSeat; }		// 선택한 좌석 반환
};
#endif // !PASSENGER_H

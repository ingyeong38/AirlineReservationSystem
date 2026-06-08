#include <iostream>
#include "Passenger.h"
using namespace std;

Passenger::Passenger(string name, int age, string passportNo) 
	: selectedFlight(0), 
	  selectedSeatClass(0),
	  selectedSeat("")
{
	this->name = name;
	this->age = age;
	this->passportNo = passportNo;
}

void Passenger::printInfo() {			//  승객 정보 등록 확인용
	cout << "-------------------------------------------" << endl;
	cout << " " << name << "님의 정보가 정상적으로 등록되었습니다." << endl;
	cout << " 이름: " << name << endl;
	cout << " 나이: " << age << endl;
	cout << " 여권번호: " << passportNo << endl;
	cout << "-------------------------------------------" << endl;
}

void Passenger::printTicket() {			// E-Ticket에서 승객 정보 출력
	cout << " 승객명: " << name << endl;
	cout << " 여권번호: " << passportNo << endl;
}

void Passenger::setSelectedFlight(int selectedFlight) {	// 항공편 선택
	this->selectedFlight = selectedFlight;
}

void Passenger::setSelectedSeatClass(int seatSeatClass) {	// 좌석 등급 선택
	this->selectedSeatClass = seatSeatClass;
}

void Passenger::setSelectedSeat(string selectedSeat) {		// 좌석 선택
	this->selectedSeat = selectedSeat;
}
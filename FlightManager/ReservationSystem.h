#pragma once
#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
#include <iostream>
#include <map>
#include "Passenger.h"
#include "Flight.h"
#include "Seat.h"
#include "Economy.h"
#include "Business.h"
#include "FirstClass.h"
using namespace std;

struct Reservation {
	string reservationId;
	string passengerName;
	string passportNo;
	int flightIndex;
	int seatClass;
	string seatNumber;
	int finalPrice;
};

class ReservationSystem {
private:
	Flight* flights[10];	// 항공편 10개 저장
	Passenger* passenger;	// 승객 정보
	int flightCount;		// 등록된 항공편 수
	int seatCount;			// 등록된 좌석 수
	bool seatMap[10][3][30];// 등급별 좌석 배치도
	int getColCount(int seatClass); // 등급별 열 수 반환
	int selectedFlight;		// 선택한 항공편 인덱스
	int selectedClass;      // 선택한 좌석 등급
	string selectedSeat;    // 선택한 좌석 번호
	string reservationId;	// 현재 예약번호
	static int counter;		// 예약번호 자동 생성용
	map<string, Reservation> reservations;
public:
	ReservationSystem();
	~ReservationSystem();
	void run();
	void menu();			// 메인 메뉴 출력 및 기능 선택
	void showFlights();		// 등록된 항공편 목록 출력
	void showSeatMap(int flightId, int seatClass);	// 선택한 등급의 좌석 배치도 출력
	bool selectSeat(string seatId);	// 좌석 번호 입력받아 배정 후 반환
	void reserve();			// 결제 확인, 예약번호 생성, E-Ticket 발급
	void findReservation();	// 예약번호로 기존 예약 정보 조회 및 출력
};
#endif // !RESERVATIONSYSTEM_H

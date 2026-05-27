#include <iostream>
#include <string>
#include<vector>
#include "ReservationSystem.h"
#include "Flight.h"
#include "DomesticFlight.h"
#include "InternationalFlight.h"
#include "CharterFlight.h"
#include "Seat.h"
#include "Economy.h"
#include "Business.h"
#include "FirstClass.h"
using namespace std;

int ReservationSystem::counter = 0;

ReservationSystem::ReservationSystem()		// 초기 항공편 목록(10개) 저장
	: passenger(nullptr),
	  flightCount(10),
	  seatCount(10),
	  reservationId(""),
	  selectedFlight(-1),
	  selectedClass(-1),
	  selectedSeat("")
{
	flights[0] = new DomesticFlight("KE1201", "Seoul(GMP)", "Jeju(CJU)", 450, 90000);
	flights[1] = new DomesticFlight("OZ8901", "Seoul(GMP)", "Busan(PUS)", 330, 80000);
	flights[2] = new DomesticFlight("7C101", "Busan(PUS)", "Jeju(CJU)", 300, 70000);
	flights[3] = new DomesticFlight("TW901", "Daegu(TAE)", "Jeju(CJU)", 320, 75000);

	flights[4] = new InternationalFlight("KE701", "Seoul(ICN)", "Tokyo(NRT)", 1200, 300000, 35000, 28000);
	flights[5] = new InternationalFlight("OZ361", "Seoul(ICN)", "Shanghai(PVG)", 900, 250000, 30000, 25000);
	flights[6] = new InternationalFlight("UA893", "Seoul(ICN)", "Guam(GUM)", 9000, 1200000, 150000, 45000);
	flights[7] = new InternationalFlight("SQ607", "Seoul(ICN)", "Bangkok(BKK)", 4600, 600000, 70000, 35000);
	flights[8] = new CharterFlight("CH001", "Seoul(ICN)", "Danang(DAD)", 3000, 15000000);
	flights[9] = new CharterFlight("CH002", "Seoul(ICN)", "Guam(GUM)", 3400, 18000000);

	seats[0] = new Economy("1A");
	seats[1] = new Economy("4E");
	seats[2] = new Economy("2C");
	seats[3] = new Economy("5D");

	seats[4] = new Business("3A");
	seats[5] = new Business("1C");
	seats[6] = new Business("2B");

	seats[7] = new FirstClass("4A");
	seats[8] = new FirstClass("1B");
	seats[9] = new FirstClass("3A");

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 30; k++)
				seatMap[i][j][k] = false;
		}
	}
}
ReservationSystem::~ReservationSystem() {
	for (int i = 0; i < flightCount; i++) {
		if (flights[i] != nullptr) {
			delete flights[i];
		}
	}
	for (int i = 0; i < seatCount; i++) {
		if (seats[i] != nullptr) {
			delete seats[i];
		}
	}
	if (passenger != nullptr)
		delete passenger;
}
void ReservationSystem::run() {
	cout << "======================================================" << endl;
	cout << "                  항공권 예약 시스템     " << endl;
	cout << "======================================================" << endl;
	cout << "      항공권 예약 시스템에 오신 것을 환영합니다!" << endl;
	cout << " 본 시스템을 통해 항공편 조회부터 좌석 선택, 예약까지" << endl;
	cout << "       한 번에 편리하게 진행하실 수 있습니다 :)" << endl;
	cout << "======================================================" << endl;
	string name;
	int age;
	string passportNo;
	cout << "사용자님의 이름, 나이, 여권 번호를 입력해 주세요." << endl;
	cout << "이름: ";
	cin >> name;
	cout << "나이: ";
	cin >> age;
	cout << "여권번호: ";
	cin >> passportNo;
	passenger = new Passenger(name, age, passportNo);
	// 승객 정보 저장
	menu();
}
void ReservationSystem::menu() {
	// 메인 메뉴 출력 및 기능 선택 
	int choice = 0;	// 메뉴 번호
	while (true) {	// 프로그램 종료 선택 시까지 무한 반복
		system("cls");
		cout << " [ MAIN MENU ] ------------------------" << std::endl;
		cout << " 1. 항공편 예약" << endl;
		cout << " 2. 예약 조회" << endl;
		cout << " 3. 프로그램 종료" << endl;
		cout << " --------------------------------------" << std::endl;
		cout << " 원하시는 메뉴의 번호를 입력해주세요: ";
		cin >> choice;

		
		switch (choice) {
		case 1:
			showFlights();	// 항공편 목록 출력
			
			int flightChoice;
			cout << "예약하실 항공편 번호(1~10)를 선택하세요(0: 메뉴로 돌아가기): ";
			cin >> flightChoice;
			if (flightChoice == 0)	break;	// 항공편 목록만 보고 메인 메뉴로 복귀
			
			selectedFlight = flightChoice - 1;

			if (flights[flightChoice - 1]->getFlightClass() != "전세기") {

				cout << "====================== 좌석 등급 선택 ======================" << endl;
				cout << "1. Economy     (x1.0) - 기본 기내식 제공" << endl;
				cout << "2. Business    (x2.5) - 전용 라운지, 프리미엄 식사, 우선 탑승" << endl;
				cout << "3. FirstClass  (x4.0) - 전용 라운지, 개인 스위트, 기내 샤워" << endl;
				cout << "-------------------------------------------------------------" << endl;
				cout << "원하시는 등급 번호를 입력하세요: ";
				int classChoice;
				cin >> classChoice;
				
				selectedClass = classChoice;

				showSeatMap(flightChoice - 1, classChoice);
				string seatNum;
				cout << "원하시는 좌석 번호를 입력하세요. (예: 2A): ";
				cin >> seatNum;
				selectSeat(seatNum);
			}
			//string chosenSeat = selectSeat(classChoice);
			reserve();	// 예약 진행(reserve()에서 selectSeat 호출)
			system("pause");
			break;
		case 2: 
			findReservation();	// 예약 확인
			break;
		case 3:
			cout << "\n시스템을 종료합니다. 이용해 주셔서 감사합니다.\n";
			return;		// menu() 함수를 빠져나가며 프로그램 종료
		default:
			cout << " 1~3 중에서 입력해 주세요." << endl;
			system("pause");
		}
	}
}
void ReservationSystem::showFlights() {
	// 등록된 항공편 목록 출력
	cout << "  \t항공편\t      출발지\t   도착지\t   종류" << endl;
	for (int i = 0; i < flightCount; i++) {	
		cout << "[" << i + 1 << "] ";
		flights[i]->printInfo();
		cout << endl;
	}
}
void ReservationSystem::showSeatMap(int flightChoice, int seatClass) {
	// 선택한 등급의 좌석 배치도 출력
	// 각 항공편마다 선택된 좌석은 X로 나오게끔
	// 승객이 선택한 등급
	if ( seatClass == 1) {
		Economy::getSeatMap(seats);
	}
	else if (seatClass == 2) {
		Business::getSeatMap(seats);
	}
	else if (seatClass == 3) {
		FirstClass::getSeatMap(seats);
	}
	else {
		cout << "등급 번호는 1~3 중에서 입력해 주세요." << endl;
	}
}
int ReservationSystem::getColCount(int selectClass) {
	if (selectClass == 1)		
		return 5;				// Economy 좌석 열	
	else if (selectClass == 2)	
		return 4;				// Business 좌석 열
	else 
		return 2;				// FirstClass 좌석 열
}
void ReservationSystem::selectSeat(string seatNum) {
	// 좌석 번호 입력받아 배정 후 반환
	int row = seatNum[0] - '1';
	int col = seatNum[1] - 'A';
	int colCount = getColCount(selectedClass);
	int index = row * colCount + col;

	if (seatMap[selectedFlight][selectedClass - 1][index]) {
		cout << "이미 예약된 좌석입니다. 다른 좌석을 선택해주세요." << endl;
	}
	else {
		seatMap[selectedFlight][selectedClass - 1][index] = true;
		selectedSeat = seatNum;
		cout << seatNum << " 좌석이 선택되었습니다." << endl;
	}
	// 해당 좌석이 이미 예약되었는지 확인
	// seatMap을 통해 확인
    // 예약 가능하면 → true로 변경, 멤버 변수에 저장
    // 이미 예약됨 → 다시 입력 안내
}
void ReservationSystem::reserve() {
	// 결제 확인, 예약번호 생성, E-Ticket 발급
}
void ReservationSystem::findReservation() {
	// 예약번호로 기존 예약 정보 조회 및 출력
}
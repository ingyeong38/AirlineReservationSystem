#include <iostream>
#include <string>
#include <Windows.h>
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
	flights[6] = new InternationalFlight("UA893", "Seoul(ICN)", "Guam(GUM)", 9000, 270000, 150000, 45000);
	flights[7] = new InternationalFlight("SQ607", "Seoul(ICN)", "Bangkok(BKK)", 4600, 230000, 70000, 35000);
	flights[8] = new CharterFlight("CH001", "Seoul(ICN)", "Danang(DAD)", 3000, 15000000);
	flights[9] = new CharterFlight("CH002", "Seoul(ICN)", "Guam(GUM)", 3400, 18000000);

	// 좌석 배열은 지우고 승객이 좌석 저장할 객체 or 배열 만들기
	// unordered_map 사용해서 객체 하나에 승객이 예약한 정보 저장

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 30; k++)
				seatMap[i][j][k] = false;
		}
	}
}
ReservationSystem::~ReservationSystem() {	// 동적 할당 받은 객체를 delete
	for (int i = 0; i < flightCount; i++) {
		if (flights[i] != nullptr) {
			delete flights[i];
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
	passenger = new Passenger(name, age, passportNo);	// 입력받은 승객 정보를 passenger 객체에 동적 할당
	system("cls");
	cout << "-------------------------------------------" << endl;
	cout << " " << passenger->getName() << "님의 정보가 정상적으로 등록되었습니다." << endl;
	cout << " 이름: " << passenger->getAge() << endl;
	cout << " 나이: " << passenger->getAge() << endl;
	cout << " 여권번호: " << passenger->getPassportNo() << endl;
	cout << "-------------------------------------------" << endl;
	Sleep(2500);
	menu();
}
void ReservationSystem::menu() {
	// 메인 메뉴 출력 및 기능 선택 
	int choice = 0;	// 메뉴 번호
	while (true) {	// 프로그램 종료 선택 시까지 무한 반복
		system("cls");	// 화면 초기화
		cout << " [ MAIN MENU ] ------------------------" << std::endl;
		cout << " 1. 항공편 예약" << endl;
		cout << " 2. 예약 조회" << endl;
		cout << " 3. 프로그램 종료" << endl;
		cout << " --------------------------------------" << std::endl;
		cout << " 원하시는 메뉴의 번호를 입력해주세요: ";
		cin >> choice;
		
		switch (choice) {
		case 1:	// 1. 항공편 예약 선택
			showFlights();	// 항공편 목록 출력
			
			int flightChoice;
			cout << "예약하실 항공편 번호(1~10)를 선택하세요(0: 메뉴로 돌아가기): ";
			cin >> flightChoice;
			if (flightChoice == 0)	break;	// 항공편 목록만 보고 메인 메뉴로 복귀
			
			selectedFlight = flightChoice - 1;
			system("cls");
			flights[selectedFlight]->printDetail();
			Sleep(1000);

			if (flights[flightChoice - 1]->getFlightClass() != "전세기") {	// 전세기는 좌석 등급 없음
				cout << "\n---------------------- 좌석 등급 선택 ----------------------" << endl;
				cout << "1. Economy     (x1.0) - 기본 기내식 제공" << endl;
				cout << "2. Business    (x2.5) - 전용 라운지, 프리미엄 식사, 우선 탑승" << endl;
				cout << "3. FirstClass  (x4.0) - 전용 라운지, 개인 스위트, 기내 샤워" << endl;
				cout << "-------------------------------------------------------------" << endl;
				cout << "원하시는 등급 번호를 입력하세요: ";
				int classChoice;
				cin >> classChoice;
				
				selectedClass = classChoice;

				showSeatMap(selectedFlight, classChoice);	// 선택한 등급의 좌석 배치도 출력(Economy/Business/FirstClass)
				string seatNum;
				while (true) {
					cout << "원하시는 좌석 번호를 입력하세요. (예: 2A): ";
					cin >> seatNum;
					int seatInt = seatNum[0] - '0';
					int seatCharUp = seatNum[1] - 'A';		// 열 값을 정수값으로 저장(A -> 0, B -> 1, C -> 2, ...)
					int seatCharLow = seatNum[1] - 'a';
					// 2a로 입력했을 때 2A로 저장되게
					if (classChoice == 1) {
						if ((seatInt >= 1 && seatInt <= 6) && (seatCharUp >= 0 && seatCharUp <= 4) || (seatCharLow >= 0 && seatCharLow <= 4)) {
							selectSeat(seatNum);
							break;
						}
						else {
							cout << "배치도의 범위 내에서 선택해 주세요." << endl;
						}
					}
					else if (classChoice == 2) {
						if ((seatInt >= 1 && seatInt <= 5) && (seatCharUp >= 0 && seatCharUp <= 3) || (seatCharLow >= 0 && seatCharLow <= 3)) {
							selectSeat(seatNum);
							break;
						}
						else {
							cout << "배치도의 범위 내에서 선택해 주세요." << endl;
						}
					}
					else if (classChoice == 3) {
						if ((seatInt >= 1 && seatInt <= 4) && (seatCharUp >= 0 && seatCharUp <= 1) || (seatCharLow >= 0 && seatCharLow <= 1)) {
							selectSeat(seatNum);
							break;
						}
						else {
							cout << "배치도의 범위 내에서 선택해 주세요." << endl;
						}
					}
				}
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
	cout << "\n  \t항공편\t      출발지\t   도착지\t   종류" << endl;
	for (int i = 0; i < flightCount; i++) {	
		cout << "[" << i + 1 << "] ";
		flights[i]->printSummary();
		cout << endl;
	}
}
void ReservationSystem::showSeatMap(int flightChoice, int seatClass) {
	// 선택한 등급의 좌석 배치도 출력
	// 각 항공편마다 선택된 좌석은 X로 나오게끔
	// 승객이 선택한 등급
	if ( seatClass == 1) {
		Economy::getSeatMap();
	}
	else if (seatClass == 2) {
		Business::getSeatMap();
	}
	else if (seatClass == 3) {
		FirstClass::getSeatMap();
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
		Sleep(2000);
	}
	// 해당 좌석이 이미 예약되었는지 확인
	// seatMap을 통해 확인
    // 예약 가능하면 → true로 변경, 멤버 변수에 저장
    // 이미 예약됨 → 다시 입력 안내
}
void ReservationSystem::reserve() {
	// 결제 확인, 예약번호 생성, E-Ticket 발급
	double multiplier;
	if (selectedClass == 1) multiplier = 1.0;
	else if (selectedClass == 2) multiplier = 2.5;
	else multiplier = 4.0;
	flights[selectedFlight]->showFareDetail(multiplier);
	char confirm;
	cout << "결제하시겠습니까? (Y/N): ";
	cin >> confirm;

	if (confirm == 'Y' || confirm == 'y') {
		// map으로 예약 번호 저장
	}
	else {
		cout << "결제가 취소되었습니다." << endl;
	}
}
void ReservationSystem::findReservation() {
	// 예약번호로 기존 예약 정보 조회 및 출력
}
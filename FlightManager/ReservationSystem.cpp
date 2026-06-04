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

int ReservationSystem::counter = 0;			// 예약 번호 카운트

ReservationSystem::ReservationSystem()		// 초기 항공편 목록(10개) 저장
	: passenger(nullptr),
	flightCount(10),
	reservationId("")
{
	flights[0] = new DomesticFlight("KE1201", "Seoul(GMP)", "Jeju(CJU)", 450, 15000);
	flights[1] = new DomesticFlight("OZ8901", "Seoul(GMP)", "Busan(PUS)", 330, 16000);
	flights[2] = new DomesticFlight("7C101", "Busan(PUS)", "Jeju(CJU)", 300, 15000);
	flights[3] = new DomesticFlight("TW901", "Daegu(TAE)", "Jeju(CJU)", 320, 14000);
	flights[4] = new InternationalFlight("KE701", "Seoul(ICN)", "Tokyo(NRT)", 1200, 150000, 28000, 17000);
	flights[5] = new InternationalFlight("OZ361", "Seoul(ICN)", "Shanghai(PVG)", 900, 120000, 25000, 15000);
	flights[6] = new InternationalFlight("UA893", "Seoul(ICN)", "Guam(GUM)", 3400, 200000, 40000, 25000);
	flights[7] = new InternationalFlight("SQ607", "Seoul(ICN)", "Bangkok(BKK)", 4600, 180000, 35000, 20000);
	flights[8] = new CharterFlight("CH001", "Seoul(ICN)", "Danang(DAD)", 3000, 5000000);
	flights[9] = new CharterFlight("CH002", "Seoul(ICN)", "Guam(GUM)", 3400, 6500000);

	seats[0] = new Economy();
	seats[1] = new Business();
	seats[2] = new FirstClass();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 30; k++)
				seatMap[i][j][k] = false;
		}
	}
}

ReservationSystem::~ReservationSystem() {	// 소멸자 - 동적 할당 받은 객체를 delete
	for (int i = 0; i < flightCount; i++) {
		if (flights[i] != nullptr) {
			delete flights[i];
		}
	}

	for (int i = 0; i < 3; i++) {
		delete seats[i];
	}

	if (passenger != nullptr)
		delete passenger;
}

void ReservationSystem::run() {		// 프로그램 실행
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
	system("cls");		// 화면 초기화
	passenger->printInfo();		// 등록된 승객 정보 출력
	Sleep(1500);
	menu();				// 메인 메뉴 호출
}
void ReservationSystem::menu() {	// 메인 메뉴 출력 및 기능 선택 
	int choice = 0;	// 메뉴 번호
	while (true) {	// 3번(프로그램 종료) 선택 시까지 무한 반복
		system("cls");
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

			int flightChoice;	// 항공편 번호
			cout << "예약하실 항공편 번호(1~10)를 선택하세요(0: 메뉴로 돌아가기): ";
			cin >> flightChoice;
			if (flightChoice == 0)	break;	// 항공편 목록만 보고 메인 메뉴로 복귀

			passenger->setSelectedFlight(flightChoice - 1);		// 승객이 선택한 항공편 번호를 저장
			system("cls");
			flights[passenger->getSelectedFlight()]->printDetail();		// 선택한 항공편의 상세 정보 출력
			Sleep(700);

			if (flights[passenger->getSelectedFlight()]->hasSeatClass()) {	// 전세기는 좌석 등급이 없기 때문에 국내선/국제선인 경우에만 실행됨
				cout << "\n---------------------- 좌석 등급 선택 ----------------------" << endl;
				cout << "1. Economy     (x1.0) - 기본 기내식 제공" << endl;
				cout << "2. Business    (x2.5) - 전용 라운지, 프리미엄 식사, 우선 탑승" << endl;
				cout << "3. FirstClass  (x4.0) - 전용 라운지, 개인 스위트, 기내 샤워" << endl;
				cout << "-------------------------------------------------------------" << endl;
				cout << "원하시는 등급 번호를 입력하세요: ";
				int classChoice;		// 좌석 등급
				cin >> classChoice;

				passenger->setSelectedSeatClass(classChoice);	// 승객이 선택한 좌석 등급 번호를 저장

				showSeatMap(passenger->getSelectedFlight(), classChoice);	// 선택한 등급의 좌석 배치도 출력
				string seatNum;		// 좌석 번호
				while (true) {
					cout << "원하시는 좌석 번호를 입력하세요. (예: A2): ";
					cin >> seatNum;
					seatNum[0] = toupper(seatNum[0]);		// 문자를 대문자로 통일
					if (selectSeat(seatNum)) {		// 좌석 선택 함수 호출
						break;
					}
				}
			}
			reserve();	// 예약 진행
			break;
		case 2:
			findReservation();	// 예약 확인
			break;
		case 3:
			cout << " 시스템을 종료합니다. 이용해 주셔서 감사합니다.\n";
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
	if (seatClass == 1) {
		cout << "\n [Economy 좌석]";
		seats[passenger->getSelectedSeatClass() - 1]->printSeatMap(seatMap[flightChoice][0]);
	}
	else if (seatClass == 2) {
		cout << "\n [Business 좌석]";
		seats[passenger->getSelectedSeatClass() - 1]->printSeatMap(seatMap[flightChoice][1]);
	}
	else if (seatClass == 3) {
		cout << "\n [FirstClass 좌석]";
		seats[passenger->getSelectedSeatClass() - 1]->printSeatMap(seatMap[flightChoice][2]);
	}
	else {
		cout << "등급 번호는 1~3 중에서 입력해 주세요." << endl;
	}
}

bool ReservationSystem::selectSeat(string seatNum) {	// 좌석 예약 유무에 따라 T/F 반환
	if (!seats[passenger->getSelectedSeatClass() - 1]->reserveSeat(seatNum, seatMap[passenger->getSelectedFlight()][passenger->getSelectedSeatClass() - 1])) {
		return false;	// 이미 예약된 좌석이라면 false 반환(재입력)
	}
	else {
		passenger->setSelectedSeat(seatNum);	// 예약 가능한 좌석이라면 true 반환
		Sleep(1500);
		return true;
	}
}

void ReservationSystem::reserve() {
	// 결제 확인, 예약번호 생성, E-Ticket 발급
	double multiplier;

	if (flights[passenger->getSelectedFlight()]->hasSeatClass())	// 
		multiplier = seats[passenger->getSelectedSeatClass() - 1]->getPriceMultiplier();

	int finalPrice = flights[passenger->getSelectedFlight()]->showFareDetail(multiplier);

	char confirm;
	cout << " 결제하시겠습니까? (Y/N): ";
	cin >> confirm;

	if (confirm == 'Y' || confirm == 'y') {
		// map으로 예약 번호 저장
		counter++;
		string num = to_string(counter);
		while (num.length() < 4) {
			num = "0" + num;
		}
		reservationId = flights[passenger->getSelectedFlight()]->flightCode + "-A" + num;

		Reservation r;
		r.reservationId = reservationId;
		r.passengerName = passenger->name;
		r.passportNo = passenger->getPassportNo();
		r.flightIndex = passenger->getSelectedFlight();
		r.seatClass = passenger->getSelectedSeatClass();
		r.seatNumber = passenger->getSelectedSeat();
		r.finalPrice = finalPrice;

		reservations[reservationId] = r;

		// E-Ticket 출력
		Sleep(1000);
		cout << " 결제가 정상적으로 처리되었습니다." << endl;
		cout << " E-Ticket을 발급합니다." << endl;

		cout << "\n ========= E-TICKET =========" << endl;
		cout << " 예약 번호: " << reservationId << endl;
		passenger->printTicket();
		flights[passenger->getSelectedFlight()]->printTicketInfo();
		if (flights[passenger->getSelectedFlight()]->hasSeatClass()) {
			string className = seats[passenger->getSelectedSeatClass() - 1]->getClassName();
			cout << " 좌석: " << passenger->getSelectedSeat() << " (" << className << ")" << endl;
		}
		cout << " 결제 금액: " << finalPrice << "원" << endl;
		cout << " =============================\n" << endl;
		system("pause");
	}
	else {
		if (flights[passenger->getSelectedFlight()]->hasSeatClass()) {
			seats[passenger->getSelectedSeatClass() - 1]->releaseSeat(passenger->getSelectedSeat(), seatMap[passenger->getSelectedFlight()][passenger->getSelectedSeatClass() - 1]);
		}
		cout << " 결제가 취소되었습니다." << endl;
		Sleep(1000);
	}
}
void ReservationSystem::findReservation() {
	// 예약번호로 기존 예약 정보 조회 및 출력
	string searchId;
	cout << " 예약 번호를 입력하세요: ";
	cin >> searchId;

	if (reservations.find(searchId) != reservations.end()) {
		Reservation r = reservations[searchId];
		cout << "\n [예약 정보]" << endl;
		cout << " 예약 번호: " << r.reservationId << endl;
		cout << " 승객명: " << r.passengerName << endl;
		flights[r.flightIndex]->printTicketInfo();
		cout << " 좌석: " << r.seatNumber << endl;
		cout << " 결제 금액: " << r.finalPrice << "원\n" << endl;
		system("pause");
	}
	else {
		cout << " 해당 예약번호를 찾을 수 없습니다.";
		Sleep(1000);
	}
}
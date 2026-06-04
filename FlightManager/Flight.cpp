#include <iostream>
#include "Flight.h"
using namespace std;

Flight::Flight(string flightCode, string departure, string arrival, int distance, int basePrice) {
	this->flightCode = flightCode;
	this->departure = departure;
	this->arrival = arrival;
	this->distance = distance;
	this->basePrice = basePrice;
}

int Flight::showFareDetail(double multiplier) {		// 요금 상세 출력
	int finalPrice;		// 최종 결제 금액
	if (hasSeatClass())		// 국내선/국제선인 경우
		finalPrice = int(calculateFare() * multiplier);	// 항공편별 계산 수행 후 * 좌석별 가격 배수
	else
		finalPrice = calculateFare();	// 전세기는 가격 배수 계산 안함

	cout << "\n -------------------------------" << endl;
	cout << " [요금 상세]" << endl;
	printFare();
	if(hasSeatClass())	// 국내선/국제선인 경우만 출력
		cout << " x 좌석 등급(x" << multiplier << ")" << endl;
	cout << " -------------------------------" << endl;
	cout << " 최종 결제 금액:\t" << finalPrice << "원" << endl;
	return finalPrice;
}

void Flight::printSummary() {		// 항공편 목록에서 출력할 내용
	cout << "\t" << flightCode << "\t|  " << departure << "  →  " << arrival << "\t| " << getFlightClass() <<endl; // endl 앞에 국내선/국제선/전세기 출력 변수 추가
}

void Flight::printTicketInfo() {	// E-Ticket에서 출력할 내용
	cout << " 편명: " << flightCode << " (" << getFlightClass() << ")" << endl;
	cout << " 구간: " << departure << " → " << arrival << endl;
}

void Flight::printDetail() {	// 항공편 선택 후 출력할 내용
	cout << "==============================" << endl;
	cout << " 선택하신 항공편 정보" << endl;
	cout << " 편명: " << flightCode << endl;
	cout << " 구간: " << departure << "  →  " << arrival << endl;
	cout << " 정보: " << getFlightClass() << endl;
	cout << " 기본 요금: " << basePrice << "원" << endl;
	cout << "==============================" << endl;
}
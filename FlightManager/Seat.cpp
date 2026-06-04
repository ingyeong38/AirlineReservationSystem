#include <iostream>
#include <string>
#include "Seat.h"
using namespace std;

Seat::Seat(double priceMultiplier) {
	this->priceMultiplier = priceMultiplier;
}

double Seat::getPriceMultiplier() {
	return priceMultiplier;
}

bool Seat::isValidSeat(string seatNum) {		// 좌석 범위 검증
	int col = seatNum[0] - 'A';
	int row = stoi(seatNum.substr(1));
	return (col >= 0 && col < colCount()) && (row >= 1 && row <= rowCount());
}

void Seat::printSeatMap(bool seatStatus[]) {	// 좌석 배치도 출력
	cout << "\n\t";
	for (int i = 0; i < colCount(); i++) {
		cout << char('A' + i) << "\t";
	}
	cout << endl;
	for (int i = 0; i < rowCount(); i++) {
		cout << i + 1 << "      ";
		for (int j = 0; j < colCount(); j++) {
			int index = i * colCount() + j;
			if (seatStatus[index])
				cout << "[x]     ";
			else
				cout << "[O]     ";
		}
		cout << endl;
	}
}
	
bool Seat::reserveSeat(string seatNum, bool seatStatus[]) {	// 예약 가능한 좌석인지
	if (!isValidSeat(seatNum)) {
		cout << "배치도의 범위 내에서 선택해 주세요." << endl;
		return false;
	}
	else {
		int col = seatNum[0] - 'A';
		int row = stoi(seatNum.substr(1)) - 1;
		int index = row * colCount() + col;

		if (seatStatus[index]) {
			cout << "이미 예약된 좌석입니다.\n다른 좌석을 선택해주세요." << endl;
			return false;
		}
		else {
			seatStatus[index] = true;
			cout << seatNum << " 좌석이 선택되었습니다." << endl;
			return true;
		}
	}
}
void Seat::releaseSeat(string seatNum, bool seatStatus[]) {		// 결제 취소 시 좌석 해제
	int col = seatNum[0] - 'A';
	int row = stoi(seatNum.substr(1)) - 1;
	int index = row * colCount() + col;
	seatStatus[index] = false;
}
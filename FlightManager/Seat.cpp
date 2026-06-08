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
	int col = seatNum[0] - 'A';			// 0 -> A, 1 -> B, ... 의미
	int row = stoi(seatNum.substr(1));	// 0번 인덱스(문자) 이후의 숫자 값을 int로 변환해서 저장
	return (col >= 0 && col < colCount()) && (row >= 1 && row <= rowCount());
}	// 열이 0 ~ colCount(), 행이 1 ~ rowCount() 사이인 경우에만 true 반환

void Seat::printSeatMap(bool seatStatus[]) {	// 좌석 배치도 출력
	cout << "\n\t";
	for (int i = 0; i < colCount(); i++) {	// 좌석 등급마다 행/열 크기 다름. colCount()로 좌석 등급의 열 크기 반환
		cout << char('A' + i) << "\t";
	}
	cout << endl;
	for (int i = 0; i < rowCount(); i++) {	// rowCount()로 좌석 등급의 행 크기 반환
		cout << i + 1 << "      ";
		for (int j = 0; j < colCount(); j++) {	// colCount()로 좌석 등급의 열 크기 반환
			int index = i * colCount() + j;		// 0행 0열부터 마지막 행 마지막 열까지 접근
			if (seatStatus[index])		// 좌석(index)이 이미 예약된 경우 [x]로 출력
				cout << "[x]     ";
			else
				cout << "[O]     ";
		}
		cout << endl;
	}
}
	
bool Seat::reserveSeat(string seatNum, bool seatStatus[]) {	// 예약 가능한 좌석인지
	if (!isValidSeat(seatNum)) {	// 좌석 범위에서 벗어난 경우 실행
		cout << "배치도의 범위 내에서 선택해 주세요." << endl;
		return false;
	}
	else {
		int col = seatNum[0] - 'A';
		int row = stoi(seatNum.substr(1)) - 1;		// 배열에 접근해야 하기 때문에 - 1
		int index = row * colCount() + col;

		if (seatStatus[index]) {	// 좌석이 이미 예약된 상태(true)라면 실행
			cout << "이미 예약된 좌석입니다.\n다른 좌석을 선택해주세요." << endl;
			return false;
		}
		else {
			seatStatus[index] = true;	// 좌석이 예약 되어 있지 않다면 true로 바꿈(예약)
			cout << seatNum << " 좌석이 선택되었습니다." << endl;
			return true;
		}
	}
}
void Seat::releaseSeat(string seatNum, bool seatStatus[]) {		// 결제 취소 시 좌석 해제
	int col = seatNum[0] - 'A';
	int row = stoi(seatNum.substr(1)) - 1;
	int index = row * colCount() + col;
	seatStatus[index] = false;		// 결제 취소로 예약된 좌석을 해제해야 함 -> 해당 좌석을 false로 변경
}
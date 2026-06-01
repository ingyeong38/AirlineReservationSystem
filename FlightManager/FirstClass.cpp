#include <iostream>
#include "Seat.h"
#include "FirstClass.h"
using namespace std;

FirstClass::FirstClass()
	: Seat(4.0){ }

void FirstClass::getSeatMap(bool seatStatus[]) {
	cout << "\n\t" << "A\tB\n";
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "      ";
		for (int j = 0; j < 2; j++) {
			int index = i * 2 + j;
			if(seatStatus[index])
				cout << "[x]     ";
			else
				cout << "[O]     ";
		}
		cout << endl;
	}
}
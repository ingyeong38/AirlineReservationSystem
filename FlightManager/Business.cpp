#include <iostream>
#include "Seat.h"
#include "Business.h"
using namespace std;

Business::Business(string seatNumber) 
	: Seat(seatNumber, 2.5){ }

void Business::getSeatMap(bool seatStatus[]) {
	cout << "\n\t" << "A\tB\tC\tD\n";
	for (int i = 0; i < 5; i++) {
		cout << i + 1<< "     ";
		for (int j = 0; j < 4; j++) {
			int index = i * 4 + j;
			if(seatStatus[index])
				cout << " [x]    ";
			else
				cout << " [O]    ";
		}
		cout << endl;
	}
}
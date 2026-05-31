#include <iostream>
#include "Seat.h"
#include "Economy.h"
using namespace std;

Economy::Economy(string seatNumber)
	: Seat(seatNumber, 1.0) { }

void Economy::getSeatMap(bool seatStatus[]) {
	cout << "\n\t" << "A\tB\tC\tD\tE\n";
	for (int i = 0; i < 6; i++) {
		cout << i + 1<< "     ";
		for (int j = 0; j < 5; j++) {
			int index = i * 5 + j;
			if(seatStatus[index])
				cout << " [x]    ";
			else
				cout << " [O]    ";
		}
		cout << endl;
	} 
}
#include <iostream>
#include "Seat.h"
#include "FirstClass.h"
using namespace std;

FirstClass::FirstClass(string seatNumber)
	: Seat(seatNumber, 4.0) { }

string FirstClass::getClassName() {
	return "[FirstClass ÁÂ¼®]\n";
}

void FirstClass::getSeatMap(Seat* seats[]) {
	cout << "\t" << "A\tB\n";
	for (int i = 1; i < 5; i++) {
		cout << i << "      ";
		for (int j = 0; j < 2; j++) {
			cout << "[O]     ";
		}
		cout << endl;
	}
}
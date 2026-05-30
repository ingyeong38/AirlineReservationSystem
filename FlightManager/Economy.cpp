#include <iostream>
#include "Seat.h"
#include "Economy.h"
using namespace std;

Economy::Economy(string seatNumber)
	: Seat(seatNumber, 1.0) { }

string Economy::getClassName() {
	return "[Economy ÁÂ¼®]\n";
}

void Economy::getSeatMap() {
	cout << "\n\t" << "A\tB\tC\tD\tE\n";
	for (int i = 1; i < 7; i++) {
		cout << i << "     ";
		for (int j = 0; j < 5; j++) {
			cout << " [O]    ";
		}
		cout << endl;
	} 
}
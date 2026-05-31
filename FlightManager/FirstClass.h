#pragma once
#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;

class FirstClass : public Seat {
public:
	FirstClass(string seatNumber);
	static void getSeatMap(bool seatStatus[]);
	string getClassName() { return "FirstClass"; }
	int getMaxRows() { return 4; }
	int getMaxCols() { return 2; }
};
#endif // !FIRSTCLASS_H

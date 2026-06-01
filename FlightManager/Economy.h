#pragma once
#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;

class Economy : public Seat{
public:
	Economy();
	static void getSeatMap(bool seatStatus[]);
	string getClassName() { return "Economy"; }
	int getMaxRows() { return 6; }
	int getMaxCols() { return 5; }
};
#endif // !ECONOMY_H

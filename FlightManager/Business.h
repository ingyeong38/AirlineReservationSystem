#pragma once
#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;

class Business : public Seat{
public:
	Business();
	static void getSeatMap(bool seatStatus[]);
	string getClassName() { return "Business"; }
	int getMaxRows() { return 5; }
	int getMaxCols() { return 4; }
};
#endif // !BUSINESS_H

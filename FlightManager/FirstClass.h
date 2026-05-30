#pragma once
#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;

class FirstClass : public Seat {
public:
	FirstClass(string seatNumber);
	string getClassName();
	static void getSeatMap();
};
#endif // !FIRSTCLASS_H

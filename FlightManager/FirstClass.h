#pragma once
#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;

class FirstClass : public Seat {
public:
	FirstClass(string seatNumber);
	static void getSeatMap(bool seatStatus[]);
};
#endif // !FIRSTCLASS_H

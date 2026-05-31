#pragma once
#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;

class Economy : public Seat{
public:
	Economy(string seatNumber);
	static void getSeatMap(bool seatStatus[]);
};
#endif // !ECONOMY_H

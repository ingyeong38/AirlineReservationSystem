#pragma once
#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;

class Economy : public Seat{
public:
	Economy(string seatNumber);
	string getClassName();
	static void getSeatMap(Seat* seats[]);
};
#endif // !ECONOMY_H

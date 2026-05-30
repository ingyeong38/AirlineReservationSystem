#pragma once
#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;

class Business : public Seat{
public:
	Business(string seatNumber);
	string getClassName();
	static void getSeatMap();
};
#endif // !BUSINESS_H

#pragma once
#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;

class Business : public Seat{
public:
	Business(string seatNumber);
	static void getSeatMap(bool seatStatus[]);
};
#endif // !BUSINESS_H

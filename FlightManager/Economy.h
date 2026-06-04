#pragma once
#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;

class Economy : public Seat{
private:
	int rowCount();
	int colCount();
public:
	Economy();
	string getClassName() { return "Economy"; }
};
#endif // !ECONOMY_H

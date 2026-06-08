#pragma once
#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;

class Economy : public Seat{
private:
	int rowCount();	// 행 크기
	int colCount();	// 열 크기

public:
	Economy();
	inline string getClassName() { return "Economy"; }
};
#endif // !ECONOMY_H

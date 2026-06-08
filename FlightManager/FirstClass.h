#pragma once
#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;

class FirstClass : public Seat {
private:
	int rowCount();	// 행 크기
	int colCount();	// 열 크기

public:
	FirstClass();
	inline string getClassName() { return "FirstClass"; }
};
#endif // !FIRSTCLASS_H

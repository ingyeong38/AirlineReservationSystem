#pragma once
#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;

class FirstClass : public Seat {
private:
	inline int rowCount();
	inline int colCount();
public:
	FirstClass();
	string getClassName() { return "FirstClass"; }
};
#endif // !FIRSTCLASS_H

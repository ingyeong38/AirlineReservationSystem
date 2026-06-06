#pragma once
#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;

class Business : public Seat{
private:
	inline int rowCount();
	inline int colCount();
public:
	Business();
	string getClassName() { return "Business"; }
};
#endif // !BUSINESS_H

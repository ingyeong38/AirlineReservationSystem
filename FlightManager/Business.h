#pragma once
#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;

class Business : public Seat{
private:
	int rowCount();	// 행 크기
	int colCount();	// 열 크기

public:
	Business();
	inline string getClassName() { return "Business"; }
};
#endif // !BUSINESS_H

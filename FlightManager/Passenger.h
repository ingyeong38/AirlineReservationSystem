#pragma once
#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
using namespace std;

class Passenger {
private:
	string name;		// 승객 이름
	int age;			// 승객 나이
	string passPortNo;	// 여권번호
public:
	Passenger(string name, int age, string passport);
	string getName();	// 이름 반환
	int getAge();		// 나이 반환
	string getPassportNo();	// 여권번호 반환
};
#endif // !PASSENGER_H

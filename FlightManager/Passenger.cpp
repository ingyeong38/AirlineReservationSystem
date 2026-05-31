#include <iostream>
#include "Passenger.h"
using namespace std;

Passenger::Passenger(string name, int age, string passportno) {
	this->name = name;
	this->age = age;
	this->passPortNo = passportno;
}
void Passenger::printInfo() {
	cout << "-------------------------------------------" << endl;
	cout << " " << name << "님의 정보가 정상적으로 등록되었습니다." << endl;
	cout << " 이름: " << name << endl;
	cout << " 나이: " << age << endl;
	cout << " 여권번호: " << passPortNo << endl;
	cout << "-------------------------------------------" << endl;
}
void Passenger::printTicket() {
	cout << " 승객명: " << name << endl;
	cout << " 여권번호: " << passPortNo << endl;
}
string Passenger::getName() {
	return name;
}
int Passenger::getAge() {
	return age;
}
string Passenger::getPassportNo() {
	return passPortNo;
}
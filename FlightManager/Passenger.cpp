#include <iostream>
#include "Passenger.h"
using namespace std;

Passenger::Passenger(string name, int age, string passportno) {
	this->name = name;
	this->age = age;
	this->passPortNo = passportno;
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
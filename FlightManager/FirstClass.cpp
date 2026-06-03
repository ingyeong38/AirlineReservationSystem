#include <iostream>
#include "Seat.h"
#include "FirstClass.h"
using namespace std;

FirstClass::FirstClass()
	: Seat(4.0){ }

int FirstClass::rowCount() {
	return 4;
}

int FirstClass::colCount() {
	return 2;
}
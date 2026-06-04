#include <iostream>
#include "Seat.h"
#include "Business.h"
using namespace std;

Business::Business() 
	: Seat(2.5) { }

int Business::rowCount() {
	return 5;
}

int Business::colCount() {
	return 4;
}
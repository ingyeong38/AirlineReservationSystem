#include <iostream>
#include "Seat.h"
#include "Economy.h"
using namespace std;

Economy::Economy()
	: Seat(1.0) { }

int Economy::rowCount() {
	return 6;
}

int Economy::colCount() {
	return 5;
}
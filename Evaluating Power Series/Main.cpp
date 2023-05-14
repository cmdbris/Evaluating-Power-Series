#include "Trig.h"
#include <iostream>
#include <windows.h>

using namespace Trig;

int choice;
long double x;
long double y = 0;

int main() {
	do {
		choice = introduction();
		x = defining_x(choice);

		switch (choice) {
		case 1:
			y = function_1(x);		// e^x
			break;
		case 2:
			y = function_2(x);		// sin(x)
			break;
		case 3:
			y = function_3(x);		// cos(x)
			break;
		case 4:
			y = function_4(x);		// ln(1+x)
			break;
		case 5:
			y = function_5(x);		// tan^-1(x)
			break;
		case 6:
			y = function_6(x);		// 1/(1-x)
			break;
		case 7:
			y = function_7(x);		// 1/(1+x)
			break;
		case 8:
			y = function_8(x);		// 1/(1-x)^2
			break;
		default:
			std::cout << "ERROR in choice; invalid entry detected";
			break;
		}
		answer(choice, x, y);

	} while (continue_exit_program());

	return 0;
}
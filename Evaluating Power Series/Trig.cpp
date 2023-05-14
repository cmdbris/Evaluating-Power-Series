#include "Trig.h"
#include <iostream>
#include <windows.h>

using namespace Trig;


void Trig::clear_screen(int x, int y) {
	// Clears the console screen
	std::cout << "\033[2J\033[1;1H";
	// puts the cursor back to the top left when (x, y) = (0, 0)
	std::cout << "\033[" << y << ";" << x << "H";
}

void Trig::fix_cin() {
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

bool Trig::range(long double input, int lower_bound, int upper_bound) {
	if ((input >= lower_bound) && (input <= upper_bound)) {
		return true;
	}
	else if ((input < lower_bound) || (input > upper_bound)) {
		return false;
	}
}

int Trig::introduction() {
	int choice;
	char proceed[20];

	Trig::clear_screen(0, 0);

	do {
		std::cout << "Which power series are you going to evaluate (enter corresponding list number)? \n\n";
		std::cout << " 1) e^x \n 2) sin(x) \n 3) cos(x) \n 4) ln(1+x) \n 5) tan^-1(x) \n 6) 1/(1-x) \n 7) 1/(1+x) \n 8) 1/(1-x)^2 \n\n";
		std::cout << "power series: ";
		console_black_yellow();
		std::cin >> choice;
		console_black_white();

		if (std::cin.fail()) {
			fix_cin();
			console_black_red();
			std::cout << "\n\n" << "Non numerical choice detected; please try again \n";
			console_black_white();
			std::cout << "Enter any key to proceed: ";
			std::cin >> proceed;
		}

		else if (!range(choice, 1, 8)) {
			console_black_red();
			std::cout << "\n\n" << "Invalid choice; please try again \n";
			console_black_white();
			std::cout << "Enter any key to proceed: ";
			std::cin >> proceed;
		}

		Trig::clear_screen(0, 0);
		fix_cin();

	} while (!range(choice, 1, 8));
	return choice;
}

long double Trig::exponent(long double base, int exponent) {

	long double product;

	if (exponent == 0) {
		return 1;
	}
	else if (exponent == 1) {
		return base;
	}
	else {
		product = base;

		for (int i = 2; i <= exponent; i++) {
			product = (product * base);
		}
	}
	return product;
}

long double Trig::factorial(int factor) {

	long double product = factor;
	int x = factor - 1;

	if (factor > 1) {
		product = (factor * factorial(factor - 1));
		return product;
	}
	else {
		return 1;
	}
}

long double Trig::defining_x(int choice) {

	long double x;
	char proceed[20];
	do {
		switch (choice) {
		case 1:
			std::cout << "What value of x would you like to evaluate e^x?";
			break;
		case 2:
			std::cout << "What value of x would you like to evaluate sin(x) (where x is in radians)?";
			break;
		case 3:
			std::cout << "What value of x would you like to evaluate cos(x) (where x is in radians)?";
			break;
		case 4:
			std::cout << "What value of x would you like to evaluate ln(1+x) (where -1 < x <= 1)?";
			break;
		case 5:
			std::cout << "What value of x would you like to evaluate tan^-1(x)? (where -1 <= x <= 1)";
			break;
		case 6:
			std::cout << "What value of x would you like to evaluate 1/(1-x) (where -1 < x < 1)?";
			break;
		case 7:
			std::cout << "What value of x would you like to evaluate 1/(1+x) (where -1 < x < 1)?";
			break;
		case 8:
			std::cout << "What value of x would you like to evaluate 1/(1-x)^2? (where -1 < x < 1)";
			break;
		default:
			console_black_red();
			std::cout << "ERROR defining value of x";
			console_black_white();
			break;
		}

		std::cout << "\n\n\t x = ";
		console_black_yellow();
		std::cin >> x;
		console_black_white();

		if (std::cin.fail()) {
			fix_cin();
			console_black_red();
			std::cout << "\n\n" << "Non numerical choice detected; please try again \n";
			console_black_white();
			std::cout << "Enter any key to proceed: ";
			std::cin >> proceed;
			Trig::clear_screen(0, 0);
		}

		else if (range(choice, 1, 3)) {
			break;
		}
		else if (choice == 4) {
			if ((x > -1) && (x <= 1)) {
				break;
			}
			else if ((x <= -1) || (x > 1)) {
				console_black_red();
				std::cout << "\n\n" << "Invalid x value detected; x must be within the interval of convergence stated \n";
				console_black_white();
				std::cout << "Enter any key to proceed: ";
				std::cin >> proceed;
				Trig::clear_screen(0, 0);
				continue;
			}
		}
		else if (choice == 5) {
			if (range(x, -1, 1)) {
				break;
			}
			else if (!range(x, -1, 1)) {
				console_black_red();
				std::cout << "\n\n" << "Invalid x value detected; x must be within the interval of convergence stated \n";
				console_black_white();
				std::cout << "Enter any key to proceed: ";
				std::cin >> proceed;
				Trig::clear_screen(0, 0);
			}
		}
		else if (range(choice, 6, 8)) {
			if ((x > -1) && (x < 1)) {
				break;
			}
			else if ((x <= -1) || (x >= 1)) {
				console_black_red();
				std::cout << "\n\n" << "Invalid x value detected; x must be within the interval of convergence stated \n";
				console_black_white();
				std::cout << "Enter any key to proceed: ";
				std::cin >> proceed;
				Trig::clear_screen(0, 0);
			}
		}

	} while (true);

	return x;
}

// e^x
// Maclaurin series for e^x = x^n/n!

long double Trig::function_1(long double x) {

	long double nominator, denominator, result, power_series_sum = 0;

	for (int n = 0; n <= 30; n++) {

		nominator = exponent(x, n);
		denominator = factorial(n);
		result = (nominator / denominator);
		power_series_sum = (power_series_sum + result);
	}
	return power_series_sum;
}

// sin(x)
// Maclaurin series for sin(x) = (-1)^n * x^2n+1/(2n+1)! , where x is in radians

long double Trig::function_2(long double x) {

	long double alternating_multiplier, nominator, denominator, result, power_series_sum = 0;
	int a;

	for (int n = 0; n <= 5; n++) {

		a = ((2 * n) + 1);

		alternating_multiplier = exponent(-1, n);
		nominator = exponent(x, a);
		denominator = factorial(a);
		result = (alternating_multiplier * (nominator / denominator));
		power_series_sum = (power_series_sum + result);
	}
	return power_series_sum;
}

// cos(x)
// Maclaurin series for cos(x) = (-1)^n * x^2n/(2n)! , where x is in radians

long double Trig::function_3(long double x) {

	long double alternating_multiplier, nominator, denominator, result, power_series_sum = 0;
	int a;

	for (int n = 0; n <= 5; n++) {

		a = (2 * n);

		alternating_multiplier = exponent(-1, n);
		nominator = exponent(x, a);
		denominator = factorial(a);
		result = (alternating_multiplier * (nominator / denominator));
		power_series_sum = (power_series_sum + result);
	}
	return power_series_sum;
}

// ln(1+x)
// Maclaurin series for ln(1+x) = (-1)^(n+1) * x^n/n , where -1 < x <= 1

long double Trig::function_4(long double x) {

	long double alternating_multiplier, nominator, denominator, result, power_series_sum = 0;
	int a;

	for (int n = 1; n <= 5000; n++) {

		a = (n + 1);

		alternating_multiplier = exponent(-1, a);
		nominator = exponent(x, n);
		denominator = n;
		result = (alternating_multiplier * (nominator / denominator));
		power_series_sum = (power_series_sum + result);
	}
	return power_series_sum;
}

// tan^-1(x)
// Maclaurin series for tan^-1(x) = (-1)^n * x^2n+1/2n+1 , where -1 <= x <= 1

long double Trig::function_5(long double x) {

	long double alternating_multiplier, nominator, denominator, result, power_series_sum = 0;
	int a;

	for (int n = 1; n <= 1000; n++) {

		a = ((2 * n) + 1);

		alternating_multiplier = exponent(-1, n);
		nominator = exponent(x, a);
		denominator = a;
		result = (alternating_multiplier * (nominator / denominator));
		power_series_sum = (power_series_sum + result);
	}
	return power_series_sum;
}

// 1/(1-x)
// Maclaurin series for 1/(1-x) = x^n , where -1 < x < 1

long double Trig::function_6(long double x) {

	long double result, power_series_sum = 0;

	for (int n = 0; n <= 1000; n++) {

		result = exponent(x, n);
		power_series_sum = (power_series_sum + result);
	}
	return power_series_sum;
}

// 1/(1+x)
// Maclaurin series for 1/(1+x) = (-1)^n * x^n , where -1 < x < 1

long double Trig::function_7(long double x) {
	long double alternating_multiplier, nominator, result, power_series_sum = 0;

	for (int n = 0; n <= 1000; n++) {

		alternating_multiplier = exponent(-1, n);
		nominator = exponent(x, n);
		result = (alternating_multiplier * nominator);
		power_series_sum = (power_series_sum + result);
	}
	return power_series_sum;
}

// 1/(1-x)^2
// Maclaurin series for 1/(1-x)^2 = (n+1) * x^n , where -1 < x < 1

long double Trig::function_8(long double x) {
	long double alternating_multiplier, nominator, result, power_series_sum = 0;
	int a;

	for (int n = 0; n <= 1000; n++) {

		a = (n + 1);

		alternating_multiplier = a;
		nominator = exponent(x, n);
		result = (alternating_multiplier * nominator);
		power_series_sum = (power_series_sum + result);
	}
	return power_series_sum;
}

void Trig::answer(int choice, long double x, long double y) {

	console_black_yellow();

	switch (choice) {
	case 1:
		std::cout << "\n\n\t e^(" << x << ") = " << y;
		break;
	case 2:
		std::cout << "\n\n\t sin(" << x << ") = " << y;
		break;
	case 3:
		std::cout << "\n\n\t cos(" << x << ") = " << y;
		break;
	case 4:
		std::cout << "\n\n\t ln(1 + " << x << ") = " << y;
		break;
	case 5:
		std::cout << "\n\n\t tan^-1(" << x << ") = " << y;
		break;
	case 6:
		std::cout << "\n\n\t 1/(1 - " << x << ") = " << y;
		break;
	case 7:
		std::cout << "\n\n\t 1/(1 + " << x << ") = " << y;
		break;
	case 8:
		std::cout << "\n\n\t 1/(1 - " << x << ")^2 = " << y;
		break;
	default:
		console_black_red();
		std::cout << "ERROR printing answer to console screen";
		break;
	}
	console_black_white();
	std::cout << "\n\n\n";
}

bool Trig::continue_exit_program() {

	int choice;
	char proceed[20];
	do {
		std::cout << "To continue calculations, type '1'; to exit calculations, type '0': ";
		console_black_yellow();
		std::cin >> choice;
		console_black_white();
		std::cout << "\n\n\n";

		if (std::cin.fail()) {
			fix_cin();
			console_black_red();
			std::cout << "\n\n" << "Non numerical choice detected; please try again \n";
			console_black_white();
			std::cout << "Enter any key to proceed: ";
			std::cin >> proceed;
		}

		else if (!range(choice, 0, 1)) {
			console_black_red();
			std::cout << "Invalid choice; type '1' or '0' as a response \n\n";
			console_black_white();
		}

	} while (!range(choice, 0, 1));

	//return choice;

	if (choice == 1) {
		return true;
	}
	else if (choice == 0) {
		return false;
	}
}

void Trig::console_black_white() {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 15);
}
void Trig::console_black_green() {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 10);
}
void Trig::console_black_red() {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 12);
}
void Trig::console_black_yellow() {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 14);
}
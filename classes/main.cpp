#include "console_logger.h"

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;
public:
	// constructor
	Fraction(int numerator, int denominator) {
		Logger::log("Fraction constructor called", GREEN);
		set_numerator(numerator);
		set_denominator(denominator);
	}

	// copy constructor
	Fraction(const Fraction& fraction) {
		Logger::log("Fraction copy constructor called", GREEN);
		set_numerator(fraction.get_numerator());
		set_denominator(fraction.get_denominator());
	}

	// assignment operator
	Fraction& operator=(const Fraction& fraction) {
		Logger::log("Fraction assignment operator called", GREEN);
		set_numerator(fraction.get_numerator());
		set_denominator(fraction.get_denominator());
		return *this;
	}

	// addition operator
	Fraction operator + (const Fraction* fraction) {
		Logger::log("Fraction addition operator called", GREEN);
		Fraction result(0, 0);
		result.set_numerator(this->numerator * fraction->denominator + this->denominator * fraction->numerator);
		result.set_denominator(this->denominator * fraction->denominator);
		return result;
	}

	// subtraction operator
	Fraction operator - (const Fraction* fraction) {
		Logger::log("Fraction subtraction operator called", GREEN);
		Fraction result(0, 0);
		result.set_numerator(this->numerator * fraction->denominator - this->denominator * fraction->numerator);
		result.set_denominator(this->denominator * fraction->denominator);
		return result;
	}

	// multiplication operator
	Fraction operator * (const Fraction* fraction) {
		Logger::log("Fraction multiplication operator called", GREEN);
		Fraction result(0, 0);
		result.set_numerator(this->numerator * fraction->numerator);
		result.set_denominator(this->denominator * fraction->denominator);
		return result;
	}

	// division operator
	Fraction operator / (const Fraction* fraction) {
		Logger::log("Fraction division operator called", GREEN);
		Fraction result(0, 0);
		result.set_numerator(this->numerator * fraction->denominator);
		result.set_denominator(this->denominator * fraction->numerator);
		return result;
	}

	// equality operator
	bool operator == (const Fraction& fraction) {
		Logger::log("Fraction equality operator called", GREEN);
		return this->numerator == fraction.numerator && this->denominator == fraction.denominator;
	}

	// methods
	void print_fraction() {
		Logger::log("Fraction print method called", GREEN);
		cout << get_numerator() << "/" << get_denominator() << endl;
	}

	// setters
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) { this->denominator = denominator; }

	// getters
	int get_numerator()const { return numerator; }
	int get_denominator()const { return denominator; }

	// destructor
	~Fraction() {
		Logger::log("Fraction destructor called", RED);
	}
};

bool Logger::is_print_logs = false;

int main() {
	Fraction f1(1, 2);
	Fraction f2(1, 2);

	f1.print_fraction();
	
	cout << "f1 == f2: " << (f1 == f2) << endl;
	cout << "f1 + f2: ";
	Fraction f3 = f1 + &f2;
	f3.print_fraction();
	cout << "f1 - f2: ";
	Fraction f4 = f1 - &f2;
	f4.print_fraction();
	cout << "f1 * f2: ";
	Fraction f5 = f1 * &f2;
	f5.print_fraction();
	cout << "f1 / f2: ";
	Fraction f6 = f1 / &f2;
	f6.print_fraction();


	return 0;
}
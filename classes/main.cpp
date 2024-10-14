#include "console_logger.h"

using namespace std;

class Complex {
private:
	double real;
	double imag;
public:
	// constructors
	Complex(double r, double i) {
		Logger::log("Complex object created", GREEN);
		set_real(r);
		set_imag(i);
	}

	// addition operator
	Complex operator+(const Complex& c) {
		Complex result(0, 0);
		result.set_real(real + c.get_real());
		result.set_imag(imag + c.get_imag());
		return result;
	}

	// subtraction operator
	Complex operator-(const Complex& c) {
		Complex result(0, 0);
		result.set_real(real - c.get_real());
		result.set_imag(imag - c.get_imag());
		return result;
	}

	// multiplication operator
	Complex operator*(const Complex& c) {
		Complex result(0, 0);
		result.set_real(real * c.get_real() - imag * c.get_imag());
		result.set_imag(real * c.get_imag() + imag * c.get_real());
		return result;
	}

	// division operator
	Complex operator/(const Complex& c) {
		Complex result(0, 0);
		double denominator = c.get_real() * c.get_real() + c.get_imag() * c.get_imag();
		result.set_real((real * c.get_real() + imag * c.get_imag()) / denominator);
		result.set_imag((imag * c.get_real() - real * c.get_imag()) / denominator);
		return result;
	}

	// setters
	void set_real(double r) { real = r; }
	void set_imag(double i) { imag = i; }

	// getters
	double get_real()const { return real; }
	double get_imag()const { return imag; }

	// destructor
	~Complex() {
		Logger::log("Complex object destroyed", RED);
	}
};

bool Logger::is_print_logs = true;

int main() {
	Complex* c1 = new Complex(3, 4);
	Complex* c2 = new Complex(1, 2);
	Complex c3 = *c1 + *c2;
	Complex c4 = *c1 - *c2;
	Complex c5 = *c1 * *c2;
	Complex c6 = *c1 / *c2;

	cout << "c1: " << c1->get_real() << " + " << c1->get_imag() << "i" << endl;
	cout << "c2: " << c2->get_real() << " + " << c2->get_imag() << "i" << endl;
	cout << endl;
	cout << "c1 + c2: " << c3.get_real() << " + " << c3.get_imag() << "i" << endl;
	cout << "c1 - c2: " << c4.get_real() << " + " << c4.get_imag() << "i" << endl;
	cout << "c1 * c2: " << c5.get_real() << " + " << c5.get_imag() << "i" << endl;
	cout << "c1 / c2: " << c6.get_real() << " + " << c6.get_imag() << "i" << endl;

	delete c1;
	delete c2;

	return 0;
}
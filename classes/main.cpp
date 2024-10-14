#include "console_logger.h"

using namespace std;

class Overcoat {
private:
	string color;
	int size;
	bool has_hood;
	float price;

	void set_default_values() {
		this->color = "black";
		this->size = 0;
		this->has_hood = false;
		this->price = 0.0;
	}
public:
	// constructors
	Overcoat() {
		Logger::log("Overcoat object created", GREEN);
		set_default_values();
	}
	Overcoat(string c) : Overcoat() {
		Logger::log("Overcoat object created", GREEN);
		set_color(c);
	}
	Overcoat(string c, int s) : Overcoat(c) {
		Logger::log("Overcoat object created", GREEN);
		set_size(s);
	}
	Overcoat(string c, int s, bool h) : Overcoat(c, s) {
		Logger::log("Overcoat object created", GREEN);
		set_has_hood(h);
	}
	Overcoat(string c, int s, bool h, float p) : Overcoat(c, s, h) {
		Logger::log("Overcoat object created", GREEN);
		set_price(p);
	}

	// equality operator
	bool operator==(const Overcoat& o) {
		return this->color == o.color && this->size == o.size && this->has_hood == o.has_hood && this->price == o.price;
	}

	// assignment operator
    Overcoat& operator=(const Overcoat& o) {
		set_color(o.color);
		set_size(o.size);
		set_has_hood(o.has_hood);
		set_price(o.price);
		return *this;
    }

	// price comparison
	bool operator>(const Overcoat& o) {
		return this->price > o.price;
	}
	bool operator<(const Overcoat& o) {
		return this->price < o.price;
	}

	// setters
	void set_color(string c) { this->color = c; }
	void set_size(int s) { this->size = s; }
	void set_has_hood(bool h) { this->has_hood = h; }
	void set_price(float p) { this->price = p; }

	// getters
	string get_color() { return this->color; }
	int get_size() { return this->size; }
	bool get_has_hood() { return this->has_hood; }
	float get_price() { return this->price; }

	// destructor
	~Overcoat() {
		Logger::log("Overcoat object destroyed", RED);
	}
};

bool Logger::is_print_logs = true;

int main() {
	// demonstration of all class methods
	Overcoat o1;
	Overcoat o2("blue");
	Overcoat o3("red", 42);
	Overcoat o4("green", 44, true);
	Overcoat o5("yellow", 46, false, 100.0);

	cout << "o1: " << o1.get_color() << " " << o1.get_size() << " " << o1.get_has_hood() << " " << o1.get_price() << endl;
	cout << "o2: " << o2.get_color() << " " << o2.get_size() << " " << o2.get_has_hood() << " " << o2.get_price() << endl;
	cout << "o3: " << o3.get_color() << " " << o3.get_size() << " " << o3.get_has_hood() << " " << o3.get_price() << endl;
	cout << "o4: " << o4.get_color() << " " << o4.get_size() << " " << o4.get_has_hood() << " " << o4.get_price() << endl;
	cout << "o5: " << o5.get_color() << " " << o5.get_size() << " " << o5.get_has_hood() << " " << o5.get_price() << endl;

	Overcoat o6 = o5;
	cout << "o6: " << o6.get_color() << " " << o6.get_size() << " " << o6.get_has_hood() << " " << o6.get_price() << endl;

	cout << "o5 == o6: " << (o5 == o6) << endl;
	cout << "o5 > o6: " << (o5 > o6) << endl;



	return 0;
}
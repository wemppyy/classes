#include "console_logger.h"

using namespace std;

class Flat {
private:
	int rooms;
	int area;
	float price;
	bool is_furnished;
public:
	// constructor
	Flat(int rooms, int area, float price, bool is_furnished) {
		Logger::log("Flat constructor called", GREEN);
		set_rooms(rooms);
		set_area(area);
		set_price(price);
		set_is_furnished(is_furnished);
	}

	// checking for equal areas
	bool operator==(const Flat& flat) {
		return this->area == flat.area;
	}

	// assignment operator
	Flat& operator=(const Flat& flat) {
		set_rooms(flat.rooms);
		set_area(flat.area);
		set_price(flat.price);
		set_is_furnished(flat.is_furnished);
		return *this;
	}

	// price comparison
	bool operator<(const Flat& flat) {
		return this->price < flat.price;
	}
	bool operator>(const Flat& flat) {
		return this->price > flat.price;
	}

	// setters
	void set_rooms(int rooms) { this->rooms = rooms; }
	void set_area(int area) { this->area = area; }
	void set_price(float price) { this->price = price; }
	void set_is_furnished(bool is_furnished) { this->is_furnished = is_furnished; }

	// getters
	int get_rooms() { return rooms; }
	int get_area() { return area; }
	float get_price() { return price; }
	bool get_is_furnished() { return is_furnished; }

	// destructor
	~Flat() {
		Logger::log("Flat destructor called", RED);
	}
};

bool Logger::is_print_logs = true;

int main() {
	Flat* flat = new Flat(3, 80, 50000, false);
	cout << "Rooms: " << flat->get_rooms() << endl;
	cout << "Area: " << flat->get_area() << endl;
	cout << "Price: " << flat->get_price() << endl;
	cout << "Is furnished: " << flat->get_is_furnished() << endl;

	Flat* flat2 = new Flat(2, 80, 60000, true);
	cout << "Equal areas: " << (*flat == *flat2) << endl;

	delete flat;
	return 0;
}
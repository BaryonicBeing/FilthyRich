#pragma once
#include <iostream>

class Country {
private:
	std::string name;
	int billionares;
	float sumOfMoney;

public:
	Country() {}
	Country(std::string n, int b, float s) : Country() {
		this->name = n;
		this->billionares = b;
		this->sumOfMoney = s;
	}
	friend std::ostream& operator<<(std::ostream &os, Country &c);

	void setName(std::string n) { this->name = n; }
	void addBillionare() { this->billionares++; }
	void setSum(float s) { this->sumOfMoney = s; }

	std::string getName() { return name; }
	int getBillionares() { return billionares; }
	float getSum() { return sumOfMoney; }
};

static std::ostream& operator<<(std::ostream &os, Country &c) {
	os << c.name << "  People: " << c.billionares << "  Total sum: $" << c.sumOfMoney;
	return os;
}
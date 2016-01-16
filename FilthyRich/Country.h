#pragma once
#include <iostream>

class Country {
private:
	std::string name;
	int billionares;
	int sumOfMoney;

public:
	Country() {}
	Country(std::string n, int b, int s) : Country() {
		this->name = n;
		this->billionares = b;
		this->sumOfMoney = s;
	}
	friend std::ostream& operator<<(std::ostream &os, Country &c);

	void setName(std::string n) { this->name = n; }
	void addBillionare() { this->billionares++; }
	void setSum(int s) { this->sumOfMoney = s; }

	std::string getName() { return name; }
	int getBillionares() { return billionares; }
	int getSum() { return sumOfMoney; }
};

static std::ostream& operator<<(std::ostream &os, Country &c) {
	os << c.name << " " << c.billionares << " " << c.sumOfMoney;
	return os;
}
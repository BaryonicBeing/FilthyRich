#pragma once
#include <string>

class Person {
private:
	int rank, age;
	float netWorth;
	std::string name, citizenship, sourceOfWealth;

public:
	Person(int r, std::string n, std::string c, int age, float net, std::string srcow) {
		rank = r;
		name = n;
		citizenship = c;
		this->age = age;
		this->netWorth = net;
		sourceOfWealth = srcow;
	}

	void setRank(int r) { rank = r; };
	void setName(std::string n) { name = n; };
	void setCitizenship(std::string c) { citizenship = c; };
	void setAge(int a) { age = a; };
	void setNetWorth(float n) { netWorth = n; };
	void setSourceOfWealth(std::string srcow) { sourceOfWealth = srcow; };

	int getRank() { return rank; };
	std::string getName() { return name; };
	std::string getCitizenship() { return citizenship; };
	int getAge() { return age; };
	float getNetWorth() { return netWorth; };
	std::string getSourceOfWealth() { return sourceOfWealth; };
};

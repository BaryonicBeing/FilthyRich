#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Person.h"
#include "People.h"
#include "Country.h"

class FileReader {
public:
	std::fstream stream;
	People p;

	FileReader(std::string filename) {
		stream = std::fstream(filename);
	}

	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream sStream(s);
		std::string item;
		while (std::getline(sStream, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}
	std::vector<std::string> split(std::string line, char delim) {
		std::vector<std::string> toReturn;
		split(line, delim, toReturn);
		return toReturn;
	}

	void initPersons() {
		std::string currentLine;
		while (std::getline(stream, currentLine)) {
			if (currentLine[0] >= '0' && currentLine[0] <= '9') {
				std::vector<std::string> tokens;
				tokens = split(currentLine, '\t');
				if (0 == (tokens[3].compare("-"))) tokens[3] = "0";
				//tokens: 0 = rank, 1 = name, 2 = citizenship, 3 = age, 4 = networth, 5 = source of wealth
				p.personList.push_back(Person(stoi(tokens[0]), tokens[1], tokens[2], stoi(tokens[3]), stof(tokens[4]), tokens[5]));
			}
		}
	}

	float sumOfAll() {
		float sum = 0.0;
		for (Person pe : p.personList) {
			sum += pe.getNetWorth();
		}
		return sum;
	}

	int allGuys() {
		int guys = 0;
		for (Person pe : p.personList) {
			guys++;
		}
		return guys;
	}

	float avgAge() {
		float age = 0.0;
		for (Person pe : p.personList) {
			age += pe.getAge();
		}
		return age / allGuys();
	}

	float avgNet() {
		return sumOfAll() / allGuys();
	}

	void sortByCountries() {

		Country c(p.personList[0].getCitizenship(), 0, 0.0f);
		std::vector<Country> byCountries;

		for (Person pe : p.personList) {
			Person tmp = pe;
			if (c.getName().compare(pe.getCitizenship()) == 0) {
				c.addBillionare();
				c.setSum(c.getSum() + pe.getNetWorth());
			}
			else {
				byCountries.push_back(c);
				c = Country(pe.getCitizenship(), 1, pe.getNetWorth());
			}
		}
		sort(byCountries.begin(), byCountries.end(), [](Country a, Country b) ->bool { return a.getSum() > b.getSum(); });
		for (Country c : byCountries) {
			std::cout << c << std::endl;
		}
	}

	void topTen() {
		sort(p.personList.begin(), p.personList.end(), [](Person a, Person b) ->bool { return a.getRank() < b.getRank(); });
		for (int i = 0; i < 10; ++i) {
			std::cout << p.personList[i] << std::endl;
		}
	}

	
};



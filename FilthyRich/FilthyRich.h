#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Person.h"
#include "People.h"


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
			//std::getline(stream, currentLine);
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
		int numOfPerson = 0;
		for (Person pe : p.personList) {
			age += pe.getAge();
			numOfPerson++;
		}
		return age / numOfPerson;
	}

	float avgNet() {
		return sumOfAll() / allGuys();
	}

	void topTen() {
		sort(p.personList.begin(), p.personList.end(), [](Person a, Person b) ->bool{ return a.getRank() < b.getRank(); });
		int count = 1;
		for (Person pe : p.personList) {
				std::cout << pe.getRank() << pe.getName() << std::endl;
			
		}
	}
	//avg age, avg networth, top10, country with sumofcapital and number of people desc.
};



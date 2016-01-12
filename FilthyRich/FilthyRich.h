#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Person.h"
#include "People.h"


class FileReader {

	std::ifstream stream;
	People p;

	FileReader(const char* filename) {
		stream = std::ifstream(filename, std::ifstream::in);
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
				//new Person is being added to vector Persons.
				//tokens: 0 = rank, 1 = name, 2 = citizenship, 3 = age, 4 = networth, 5 = source of wealth
				p.personList.push_back(Person(stoi(tokens[0]), tokens[1], tokens[2], stoi(tokens[3]), stof(tokens[4]), tokens[5]));
			}
			//std::getline(stream, currentLine);
		}
	}
};



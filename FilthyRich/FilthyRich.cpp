#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


class FileReader {

	std::ifstream stream;
	char* currentLine;

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
	std::vector<std::string> split(char* line, char delim) {
		std::vector<std::string> toReturn;
		split(line, delim, toReturn);
		return toReturn;
	}

	void initPersons() {
		stream.getline(currentLine, 256);
		while (stream.good()) {
			std::vector<std::string> tokens;
			tokens = split(currentLine, '\t');
			//new Person is being added to vector Persons.
			Persons.pushback(Person(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]));
			stream.getline(currentLine, 256);
		}
	}
};



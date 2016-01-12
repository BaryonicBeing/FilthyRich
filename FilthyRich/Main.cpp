#include "Person.h"
#include "FilthyRich.h"
#include "People.h"

std::string richPeople("C:/Users/Max/Desktop/WorldWealthList.txt");
FileReader fr(richPeople);


int main() {

	fr.initPersons();
	std::cout << "The total sum is " << fr.sumOfAll() << std::endl;	
	std::cout << "The average age is " << fr.avgAge() << std::endl;
	std::cout << "The average networth is " << fr.avgNet() << std::endl;
}
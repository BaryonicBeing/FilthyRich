#include "Person.h"
#include "FilthyRich.h"
#include "People.h"

std::string richPeople("C:/Users/Max/Desktop/WorldWealthList.txt");
FileReader fr(richPeople);


int main() {

	fr.initPersons();
	std::cout << "The total sum is " << fr.sumOfAll() << "\n" << std::endl;	
	std::cout << "The average age is " << fr.avgAge() << "\n" << std::endl;
	std::cout << "The average networth is " << fr.avgNet() << "\n" << std::endl;
	fr.sortByCountries();
	std::cout << std::endl;
	fr.topTen();
	
}
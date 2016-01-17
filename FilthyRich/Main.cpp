#include "Person.h"
#include "FilthyRich.h"
#include "People.h"

std::string richPeople("C:/Users/Max/Desktop/WorldWealthList.txt");
FileReader fr(richPeople);


int main() {

	fr.initPersons();
	std::cout << "\n***************SUM***************\n" << std::endl;
	std::cout << "The total sum is $" << fr.sumOfAll() << std::endl;	
	std::cout <<"\n***************AVG AGE***************\n" << std::endl;
	std::cout << "The average age is " << fr.avgAge() << " years." << std::endl;
	std::cout << "\n***************AVG NETWORTH***************\n" << std::endl;
	std::cout << "The average networth is $" << fr.avgNet() << std::endl;
	std::cout << "\n***************SORT COUNTRIES BY NETWORTH***************\n" << std::endl;
	fr.sortByCountries();
	std::cout << "\n***************TOP TEN***************\n"<< std::endl;
	fr.topTen();
	
}
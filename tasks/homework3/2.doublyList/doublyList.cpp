#include <iostream>
#include "doubly.hpp"


void chooseType();

int main() {
	chooseType();
	return 0;


	
}

void chooseType() {
	char ch;
	std::cout << "\033[2J\033[1;1H";
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "*****************************Welcome to the Doubly LinkedList interface!*****************************"<< std::endl << std::endl;
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "Please choose the data type you want the linkedList to handle \n";
	std::cout << "Enter ( i ) to use integers.\n";
	std::cout << "Enter ( f ) to use floats.\n";
	std::cout << "Enter ( d ) to use doubles.\n";
	std::cout << "Enter ( c ) to use chars.\n";
	std::cout << "Enter ( s ) to use strings.\n";
	std::cout << "Enter ( e ) to exit the program.\n";
	std::cout << "\n\nEnter choice here : ";
	std::cin >> ch;
	switch (ch) {
			case 'i': {
				interface<int>();
				break;
			}

			case 'f': {
				interface<float>();
				break;
			}
			case 'd': {
				interface<double>();
				break;
			}
			case 'c': {
				interface<char>();
				break;
			}
			case 's': {
				interface<std::string>();
				break;
			}
			case 'e': {
				break;
			}
			default: {
				std::cout << "Enter a valid choice!\n";
				wait(2);
				chooseType();
			}
	}
}

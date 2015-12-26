#include <iostream>
#include "stackArr.hpp"

void chooseType();
int getCapcity();

int main() {

	chooseType();

	return 0;
}

	
void chooseType() {
	char ch;

	std::cout << "\033[2J\033[1;1H";
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "******************************Welcome to the Array-based Stack interface!******************************"<< std::endl << std::endl;
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
				int capacity = getCapcity();
				interface<int>(capacity);

				break;
			}

			case 'f': {
				int capacity = getCapcity();
				interface<float>(capacity);
				break;
			}
			case 'd': {
				int capacity = getCapcity();
				interface<double>(capacity);
				break;
			}
			case 'c': {
				int capacity = getCapcity();
				interface<char>(capacity);
				break;
			}
			case 's': {
				int capacity = getCapcity();
				interface<std::string>(capacity);
				break;
			}
			case 'e': {
				break;
			}
			default: {
				std::cout << "Enter a valid choice!\n";
				chooseType();
			}
	}
}

int getCapcity() {

	int capacity = 0;

	do {
		std::cout << "Please Enter the size of the stack: ";
		std::cin >> capacity;
	} while (capacity <= 0);

	return capacity;
}
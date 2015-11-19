#include <iostream>

using namespace std;

bool linearSearch(int n);

int main() 
{
	int n;
	bool isThere;

	cout << "Enter the number that you want to search for: ";
	cin >> n;
	isThere = linearSearch(n);
	if (isThere) {
		cout << "\nThe number you Entered " << n << " was found!\n";
	}
	else {
		cout << "The number you Entered "  << n << "was not found!\n";
	}


}

bool linearSearch(int n)
{
	int list[] = {3,4,51,2,325,23,9,41312,32,1,34};
	int lenList = 11;

	for (int i = 0; i < lenList; i++) {
		if (n == list[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}
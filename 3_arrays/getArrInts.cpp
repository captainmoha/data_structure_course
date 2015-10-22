/*get array of ints from user and then print the elements and their count*/

#include <iostream>

void printElts(int* arr, int arrLength);
void fillArray(int* arr, int arrLength);

using namespace std;

int main() {
	int arrLength;
	cout << "Enter the length of the array that you want to work with " << endl;
	cin >> arrLength;

 	int x[arrLength];

	fillArray(x, arrLength);
	printElts(x, arrLength);
	return 0;
}

void printElts(int* arr, int arrLength) {
	cout << endl << "Elements of the array are: " << endl << "---------------------------------------" << endl;
	int counter = 0;
	for (int i = 0; i < arrLength; i++) {
		int currentElt = *(arr + i);
		cout << "elment at index " << i << " is " << currentElt << endl;
		counter ++;
	}
	cout << endl << "The array has " << counter <<  " Elements" <<  endl;
}

void fillArray(int* arr, int arrLength) {

	for (int i = 0; i < arrLength; i ++) {
		cout << "Enter element " << i << endl;
		cin >> *(arr + i);
	}

} 

#include <iostream>

using namespace std;

void swapVals (double &x, double &y);
void bubbleSort(double* arr, int lenArray);

int main() {

	cout << "Enter the size of array: " << endl;
	int size = 0;
	cin >> size;

	// dynamically allocate the array with the size that the user entered
	double* arr = new double[size];

	cout << "Enter the elements of the array : " << endl;

	for (int i = 0; i < size; i++) {
		cout << "Enter element number " << i + 1 << endl;
		cin >> arr[i];
	}

	// int elemntsCount = sizeof(arr) / sizeof(double);
	// cout << "There are " << elemntsCount << " in the array" << endl;

	

	cout << "----------------------------------------------------------------------" << endl << "Elements of the array before sorting are : " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	// sort the array
	bubbleSort(arr, size);
	cout << endl;

	cout << "----------------------------------------------------------------------" << endl << "Elements of the array after sorting are : " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;
	return 0;
}

// swap two variables by reference (used in bubbleSort)
void swapVals (double &x, double &y)
{
	double temp;
	temp = y;
	y = x;
	x = temp;
	// cout << endl << "X: " << x << "Y: " << y << endl;
}

// sort an array of integers using bubble sort
void bubbleSort(double* arr, int lenArray)
{	
	
	int temp;

	// go through each element in the array
	for (int i = 0; i < lenArray; i++) {

		// in each iteration go through each element in the array except for the last elment
		for (int j = 0; j < lenArray - i - 1; j++) {

			// if what's on the left is bigger than what's on the right
			if (arr[j] > arr[j + 1]) {
				// swap them
				swapVals(arr[j], arr[j + 1]);	
			}
				
		}
	}
}
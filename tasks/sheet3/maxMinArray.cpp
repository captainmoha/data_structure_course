#include <iostream>

using namespace std;


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
	int elemntsCount = sizeof(arr) / sizeof(double);
	cout << "There are " << elemntsCount << " in the array" << endl;

	double max = arr[0];
	double min = arr[0];

	for (int j = 0; j < size; j++) {
		if (arr[j] >= max) {
			max = arr[j];
		}

		else if (arr[j] <= min) {
			min = arr[j];
		}

	}

	cout << "----------------------------------------------------------------------" << endl << "Elements of the array are : " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "The maximum value in the array is " << max << endl;
	cout << "The minimum value in the array is " << min << endl;

	return 0;
}


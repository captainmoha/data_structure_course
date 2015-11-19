#include <iostream>

using namespace std;

double* addArrs(double* arr1, double* arr2, int size);

int main() {
	int size = 0;
	int arrCounter = 1;
	cout << "Enter array size: " << endl;
	cin >> size;

	double* arr1;
	double* arr2;

	arr1 = new double[size];
	arr2 = new double[size];

	cout << "Enter elements of the first array " << endl;
	for (int i = 0;  i < size; i++) {
		cout << "Enter element numer " << i + 1 << endl;
		cin >> arr1[i];
	}
	cout << endl << "Enter elements of the second array " << endl;
	for (int j = 0;  j < size; j++) {
		cout << "Enter element numer " << j + 1 << endl;
		cin >> arr2[j];
	}

	double* res = addArrs(arr1, arr2, size);

	cout << "Elements of array 1 " << endl;
	for (int i = 0;  i < size; i++) {
		cout <<  arr1[i] << " ";
	}
	cout << endl;
	cout << "Elements of array 2 " << endl;
	for (int j = 0;  j < size; j++) {
		cout << arr2[j] << " ";
	}

	cout << endl << "------------------------------------------------------" << endl;

	cout << "Elements of the resulting array " << endl;
	for (int k = 0;  k < size; k++) {
		cout << res[k] << " ";
	}
	cout << endl;
	return 0;
}

double* addArrs(double* arr1, double* arr2, int size) {

	double* res = new double[size];

	// add each element of the two arrays to the adjacent one
	for (int i = 0; i < size ; i++) {
		res[i] = arr1[i] + arr2[i];
	}

	return res;
}
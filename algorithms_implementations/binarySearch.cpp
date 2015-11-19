#include <iostream>

using namespace std;

bool binarySearch(int n, int lenArray);
int* getArray (int lenArray);
void swapVals (int &x, int &y);
void bubbleSort(int* arr, int lenArray);

int main() 
{
	int n;
	bool isThere;
	int lenArray;

	cout << "Welcome to array search! \n";
	cout << "Enter the length of the array that you want to create: ";
	cin >> lenArray;
	

	cout << "Enter the number that you want to search for: ";
	cin >> n;
	isThere = binarySearch(n, lenArray);

	if (isThere) {
		cout << "\nThe number you Entered " << n << " was found!\n";
	}
	else {
		cout << "The number you Entered "  << n << " was not found!\n";
	}
	
	return 0;
}

// create an array and get its elements from the user
int* getArray(int lenArray) 
{
	// remember to free this
	int* arr = new int[lenArray];
	cout << "Please enter array elements one at a time: \n";
	// getting the array 
	for (int i = 0; i < lenArray; i++) {
		cout << "Enter element number " << i + 1 << ": \n";
		cin >> arr[i];
	}

	// printing its elements
	cout << "\n\n ----------------------------------------------------------------\n";
	cout << "You Entered an array of size " << lenArray << " And its valus are: ";
	cout << "\n ----------------------------------------------------------------\n";

	// sort the array
	bubbleSort(arr, lenArray);

	// print the sorted array
	for (int i = 0; i < lenArray; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n\n";
	return arr;

}

// use binary search to look for the element in question
bool binarySearch(int n, int lenList)
{

	int* list = getArray(lenList);
	int start = 0;
	int end = lenList - 1;
	int counter = 0;

	// handle if the length of the list is 1 and the element is there
	if (lenList == 1 && n == list[0]) {
		return true;
	}

	while (start <= end) {
		// this is better than than mid = (start + mid) / 2
		int mid = start + (end - start)/2;

		if (n > list[mid]) {
			start = mid + 1;
		}
		else if (n < list[mid]) {
			end = mid - 1;
			
		}
		else {
			delete[] list;
			return true;
		}
		// counter += 1;
		// cout << "counter: " << counter << endl;

	}
	delete[] list;
	return false;
	
}

// swap two variables by reference (used in bubbleSort)
void swapVals (int &x, int &y)
{
	int temp;
	temp = y;
	y = x;
	x = temp;
	// cout << endl << "X: " << x << "Y: " << y << endl;
}

// sort an array of integers using bubble sort
void bubbleSort(int* arr, int lenArray)
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
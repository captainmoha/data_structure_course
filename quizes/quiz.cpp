#include <iostream> 
using namespace std;


int max(int* arr);
int main (){
	int arrLen = 3;
	int* arr = new int[arrLen];
	for (int i = 0; i < arrLen; i++) {
		cout << "Enter element number " << i + 1 << " : " << endl;
		cin >> arr[i];
	}
	int maxNum= 0;
	maxNum = max(arr);
	cout << "The biggest number Entered is " << maxNum << endl;
	delete[] arr;
	return 0;

}


int max(int* arr) {
	if (arr[0] > arr[1]) {
		if (arr[0] > arr[2]) {
			return arr[0];
		}
		else {
			return arr[2];
		}
	}
	else if (arr[1] > arr[2]) {
		if (arr[1] > arr[0]) {
			return arr[1];
		}
		else {
			return arr[0];
		}
	}

}

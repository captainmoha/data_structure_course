/*swapping two integers by value*/

#include <iostream>
void swapVals(int* x, int* y);

using namespace std;

int main() {
	int x, y;

	cout << "Welcome to swapper by reference!" << endl;
	cout << "Enter first number" << endl;
	cin >> x;
	cout << "Enter second number" << endl;
	cin >> y;

	// call swap function
	swapVals(&x,&y);
	cout << "----------------------------" << endl << "X is " << x << " Y is " << y << endl;
	return 0;
}

void swapVals(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
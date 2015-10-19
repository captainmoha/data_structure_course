/* Iterative Fibonacci generating algorithm */
#include <iostream>

using namespace std;
void fib(int length);

int main() {
	int length;

	cout << "Enter number of Fibonacci elements you want: " << endl;
	cin >> length;
	if (length > 0) {
		// call fib
		fib(length);
	}

	else {
		cout << "length must be a positive integer. Please try again!" << endl;
	}
	
	return 0;
}

void fib(int length) {
	int current = 1;
	int next = 0;
	int temp = 0;

	// generate elments and print them
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Here are the first " << length << " elements of the Fibonacci sequence: " << endl;
	while (length > 0) {
		temp = next;
		next = current + temp;
		current = temp;
		cout << next << ", ";
		length--;
	}
	cout << endl;
}

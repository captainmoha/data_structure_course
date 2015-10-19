/* Recursive Fibonacci generating algorithm */
#include <iostream>

using namespace std;

int fib(int num);

int main() {
	int length;
    
	cout << "Enter number of Fibonacci elements you want: " << endl;
	cin >> length;
	if (length > 0) {

		// generate elments and print them
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "Here are the first " << length << " elments of the Fibonacci sequence: " << endl;

		for (int i = 0; i < length; i++) {
			// call fib for current element
			cout << fib(i) << ", ";
		}
		cout << endl;
	}

	else {
		cout << "length must be a positive integer. Please try again!" << endl;
	}
	
	return 0;
}

int fib(int num) {
	// base case
	if (num == 0 || num == 1) {
		return 1;
	}

	else {
		return fib(num-1) + fib(num-2);
	}

}

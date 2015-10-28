/* Iterative Fibonacci algorithm to get nth fibonacci element */
#include <iostream>

using namespace std;
int fib(int n);

int main() {
	int n;

	cout << "Enter a number to get its Fibonacci:  " << endl;
	cin >> n;
	if (n >= 0) {
		// call fib
		cout << "Fibonacci of " << n << " is " << fib(n) << endl;
	}

	else {
		cout << "n must be a positive integer or zero. Please try again!" << endl;
	}
	
	return 0;
}

int fib(int n) {
	int current = 1;
	int next = 0;
	int temp = 0;

	// get fib of n
	cout << "-----------------------------------------------------------------------------" << endl;

	while (n > 0) {
		temp = next;
		next = current + temp;
		current = temp;
		n--;
	}

	return next;
}

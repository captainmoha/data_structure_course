#include <iostream> 

using namespace std;

int greatestCDiv(int a, int b);

int main ()
{	
	int a,b, gcd;

	cout << "In order to get the greatest common divisor of two integers you will need to enter them\n";
	cout << "Enter first number: ";
	cin >> a;
	cout << "\nEnter second number: ";
	cin >> b;
	gcd = greatestCDiv(a, b);
	cout << "The greatest common divisor of " << a << " and " << b << " is " << gcd << endl;
	return 0;
} 

int greatestCDiv(int a, int b)
{
	// base case
	if (b == 0) {
		return a;
	}

	else {

		return greatestCDiv(b, a%b);
	}
}
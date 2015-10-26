#include <iostream>
#include <math.h>

// getting the roots of a quadratic equation 
using namespace std;

double* quadEqn(double a, double b, double c) {
	double* values = new double[2];
	double x1, x2;
	if ((b*b - 4 * a * c) >= 0) {
	    x1 = (-b + sqrt(b*b - 4 * a * c)) / 2 * a;
	    x2 = (-b - sqrt(b*b - 4 * a * c)) / 2 * a;
	    values[0] = x1;
	    values[1] = x2;
	    return values;
	}
	else {
		// TODO deal with negative square roots
	    return NULL;
	    
	}
}

int main() {
	double a, b, c;
	cout << "Hello! , welcome to quadratic equations solver!" << endl;
	// get coeffecients from user
	cout << "Enter a: ";
	cin >> a;
	cout << endl << "Enter b: ";
	cin >> b;
	cout << endl << "Enter c: ";
	cin >> c;
	
	double* values;
	// get address of first element
	values = quadEqn(a, b, c);
	
	double x1, x2;
	// roots of equation
	x1 = values[0];
	x2 = values[1];
	cout << endl <<"The roots of the equation are : " << endl << "-----------------------------------------------------" << endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	return 0;
}

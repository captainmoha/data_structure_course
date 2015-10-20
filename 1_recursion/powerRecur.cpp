/* power using recursion */
#include <iostream>
using namespace std;
 
int powerRecur(int num, int exponent);

int main() {
	int num,exponent, res = 0;
	cout<<"Enter Number: \n";
	cin>>num;
	cout<<"Enter Power: \n";
	cin>>exponent;
	res = powerRecur(num, exponent);
	cout<<num<<" to the power of "<<exponent<<" is "<<res<<"\n";
	return 0;
	
}

int powerRecur(int num, int exponent) {
	// base case
	if (exponent == 0){
		return 1;
	}
	else if (exponent == 1) {
		return num;
	}
	else {
		exponent -= 1;
		return num * powerRecur(num, exponent);
	}
}


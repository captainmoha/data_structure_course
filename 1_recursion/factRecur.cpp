#include <iostream>
using namespace std;
 
int factRecur(int num);

int main() {
	int num, res = 0;
	cout<<"Enter Number to calculate its factorial \n";
	cin>>num;
	res = factRecur(num);
	cout<<"factorial of "<<num<<" is "<<res<<"\n";
	
}

int factRecur(int num) {
	// base case
	if (num == 0 || num == 1) {
		return 1;
	}
	else {
		return  num * factRecur(num-1);
	}
}


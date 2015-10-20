/*summation using recursion*/
#include <iostream>
using namespace std;
 
int sumRecur(int num);

int main() {
	int num, res = 0;
	cout<<"Enter Number to calculate its sum \n";
	cin>>num;
	res = sumRecur(num);
	cout<<"sum of "<<num<<" is "<<res<<"\n";
	
}

int sumRecur(int num) {
	// base case
	if (num == 1) {
		return 1;
	}
	else {
		return  num + sumRecur(num-1);
	}
}


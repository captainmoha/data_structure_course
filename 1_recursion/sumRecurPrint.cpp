#include <iostream>
using namespace std;
 
int sumRecurPrint(int num);

int main() {
	int num, res = 0;
	cout<<"Enter Number to calculate its sum \n";
	cin>>num;
	cout<<"*******************************\n\n";
	res = sumRecurPrint(num);
	cout<<"sum of "<<num<<" is "<<res<<"\n";
	
}

int sumRecurPrint(int num) {
	// base case
	if (num == 1) {
		cout<<num<<"\n";
		return 1;
	}
	else {
		cout<<num<<"\n";
		return  num + sumRecurPrint(num-1);
	}
}


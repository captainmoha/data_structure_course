#include <iostream>
using namespace std;

int factIter(int num);

int main()
{
	int num = 0;
	cout<<"Enter Number to get its factorial: \n";
	cin>>num;
	cout<<"Factorial of "<<num<<" is "<<factIter(num)<<"\n";
	return 0;
}
int factIter(int num) {
	int res = 1;
	for (int i = num; i > 0; i--) 
	{
		res *= i; 
	}
	return res;
}
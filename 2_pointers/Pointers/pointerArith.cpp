#include <iostream>

using namespace std;

int main() {
	int x;
	typedef int* pointer;
	pointer p1, p2;
	x = 5;
	p1 = &x;
	*p1 = 6;
	cout<<"x "<<x<<endl<<"p1 "<<p1<<endl;
	p2 = p1;
	*p2 = 7;
	cout<<"x "<<x<<endl<<"p2 "<<p2<<endl;

	return 0;
}
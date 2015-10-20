#include <iostream>

using namespace std;

int main() {
	int x;
	int* ptr;
	x = 5;
	ptr = &x ;
	cout<<"x "<<x<<" size of x is "<<sizeof(x)<<endl<<"ptr "<<ptr<<endl;
	*ptr++;
	cout<<"x "<<x<<" size of x is "<<sizeof(x)<<endl<<"ptr "<<ptr<<endl;
	// ++ has higher precedence than *
	(*ptr)++;
	cout<<"x "<<x<<" size of x is "<<sizeof(x)<<endl<<"ptr "<<ptr<<endl;
	return 0;
}
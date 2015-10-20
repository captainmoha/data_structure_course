#include <iostream>

using namespace std;

int main() {
	char x = 'a';
	typedef char* pointer;
	pointer ptr;
	ptr = &x;
	cout<<"ptr "<<ptr<<endl;
	cout<<"ptr after casting "<<int(*ptr)<<endl;
	ptr++;
	cout<<"ptr "<<ptr<<" ptr after casting and incrementing "<<int(*ptr)<<endl;
	return 0;
}
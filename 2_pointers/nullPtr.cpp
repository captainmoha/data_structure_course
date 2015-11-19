#include <iostream> 

using namespace std;

struct Emp {
	char name[20];
	float salary;
};
int main (){
	int* ptr = NULL;
	int* ptr2 = '\0';
	cout << ptr << " " << ptr2 << endl;
	return 0;
}

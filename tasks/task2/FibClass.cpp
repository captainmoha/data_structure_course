/* Recursive Fibonacci algorithm with a class */
#include <iostream>
using namespace std;

class Fibonacci {
	private:
		int length, num;

		int fib(int num) {
			// base case
			if (num == 0 || num == 1) {
				return 1;
			}

			else {
				return fib(num-1) + fib(num-2);
			}
		}

	public:
	    
	    
		int setLength(int len) {
			length = len;
		}

		int getLength() {
			return length;
		}

		int getFib() { 
			return fib(getNum());
		}
        
        int setNum(int n) {
            num = n;
        }
        
        int getNum() {
            return num;
        }
		void genrateFib() {
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << "Here are the first " << length << " elments of the Fibonacci sequence: " << endl;
			for (int i = 0; i < length; i++) {
			    // set Num
			    setNum(i);
				// call fib for current element
				cout << getFib() << ", ";
			}

		cout << endl;
		}
};


int main() {
	int length;

	// create Fibonacci instance
	Fibonacci myFib;

	cout << "Enter number of Fibonacci elements you want: " << endl;
	cin >> length;
	myFib.setLength(length);
	myFib.genrateFib();

	return 0;
}

/* Number class with methods that calculate the summation from one to the given input and print the intermediate values*/
#include <iostream>

using namespace std;

class Number {
	private:
		int n;

		int sumNum(int n) {
			int num = n;
			
			if (num == 1) {
				return 1;
			} 

			else {
				return num + sumNum(num - 1);
			}
		}
        
	public: 
		int setNum(int num) {
			n = num;
		}

		int getNum() {
			return n;
		}
		
		int getSum() {
		    return sumNum(n);
		}
		
		void printNum(int num) {
		    while (num > 0) {
		        cout << num << endl;
		        num--;
		    }
		}
};
int main() {
	int num, sum;

	// create number instance; 
	Number myNum;

	cout << "Enter number to get the summation of the numbers from 0 to it: " << endl;
	cin >> num;

	// set num;
	myNum.setNum(num);
	sum = myNum.getSum();

	cout << "Summation of " << myNum.getNum() << " is " << sum << endl;
	myNum.printNum(num);
	return 0;
}

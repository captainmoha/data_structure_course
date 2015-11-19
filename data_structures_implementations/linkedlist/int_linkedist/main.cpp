#include <iostream> 
#include "singlyLinkedList.hpp"

using namespace std;

void interface();
void displayMenu();

int main (){
	
	interface();

	return 0;
}


void interface() {
	linkedList List;

	char choice;
	bool isDone = false;


	while (!isDone) {
		cout << "\033[2J\033[1;1H"; // clear the screen
		
		displayMenu();
		cout << "####  List  ###########################################################################################"<< endl << endl;
		List.display();
		cout << endl;
		cout << "#######################################################################################################"<< endl << endl;
		
		cout << "Enter choice here: ";

		cin >> choice;

		switch (choice) {
			case 'a':
				int n;
				cout << "Add what ?  ";
				cin >> n; 
				List.append(n);
				break;

			case 'i':
				cout << "Add what as first ?  ";
				cin >> n;
				List.addAsFirst(n);
				break;

			case '1':
				int afterN;
				cout << "Add what ?  ";
				cin >> n;
				cout << endl << "After which element ?  ";
				cin >> afterN;
				List.addAfter(afterN, n);
				break;

			case '2':
				int beforeN;
				cout << "Add what ?  ";
				cin >> n;
				cout << endl << "Before which element ?  ";
				cin >> beforeN;
				List.addBefore(beforeN, n);
				break;

			case 'p':
				int pos;
				cout << "Add what ?  ";
				cin >> n;
				cout << endl << "After position number ?  ";
				cin >> pos;
				List.addAfterPosition(pos, n);
				break;

			case 'n':
				cout << "Delete node number ?  ";
				cin >> n;
				List.delNode(n);
				break;

			case '>':
				cout << "Delete element after what ?  ";
				cin >> n;
				List.delAfter(n);
				break;
			
			case '<':
				cout << "Delete element before what ?  ";
				cin >> n;
				List.delBefore(n);
				break;

			case 's':
				cout << "What do you wanna search for ?  ";
				cin >> n;
				List.search(n);
				break;

			case 'd':
				cout << "Delete what ?  ";
				cin >> n;
				List.del(n);
				break;

			case 'c':
				List.count();
				break;

			case 'w':
				int n2;
				cout << "Swap what ?  ";
				cin >> n;
				cout << endl << "What is next to that ?  ";
				cin >> n2;
				List.swapTwoAdjacent(n, n2);
				break;

			case 'e':
				cout << "\033[2J\033[1;1H";
				isDone = true;
				break;
		}
	}
	
}


void displayMenu() {
	cout << "*******************************************************************************************************"<< endl << endl;
	cout << "******************************Welcome to the Singly LinkedList interface!******************************"<< endl << endl;
	cout << "*******************************************************************************************************"<< endl << endl;
	cout << "Please choose one of the following choices to begin playing with the LinkedList: " << endl << endl;
	cout << "Enter ( a )  to add an element." << endl;
	cout << "Enter ( i )  to insert an element as the first element." << endl;
	cout << "Enter ( 1 )  to add an element after a certain element." << endl;
	cout << "Enter ( 2 )  to add an element before a certain element." << endl;
	cout << "Enter ( p )  to add an element after a certain position." << endl;
	cout << "Enter ( n )  to delete a certain node." << endl;
	cout << "Enter ( > )  to delete an element after a certain element." << endl;
	cout << "Enter ( < )  to delte an element before a certain element." << endl;
	cout << "Enter ( s )  to search for an element." << endl;
	cout << "Enter ( d ) to delete an element." << endl;
	cout << "Enter ( c ) to count the elements." << endl;
	cout << "Enter ( w ) to swap two adjacent elements." << endl;
	cout << "Enter ( e )  to exit this interface." << endl << endl;
}
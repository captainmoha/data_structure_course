template<class T>
struct node {
	T data;
	node<T> *next;
	node<T> *prev;
};

template<class T>
class doublyList {

	private:
		node<T> *head;

	public:
		doublyList();
		node<T>* createNode(T data);
		void append(T data);
		void delNode(int nodeNum);
		void display();
};

void wait(int seconds) {
	int endwait;
	endwait =  clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

void displayMenu() {
	/* displays the menu to interact with the list */
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "*****************************Welcome to the Doubly LinkedList interface!*****************************"<< std::endl << std::endl;
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "Please choose one of the following choices to begin playing with the LinkedList: " << std::endl << std::endl;
	std::cout << "Enter ( a )  to add an element." << std::endl;
	std::cout << "Enter ( n )  to delete a certain node." << std::endl;
	std::cout << "Enter ( e )  to exit this interface." << std::endl << std::endl;
}

template<class T>
void interface() {
	/* handles the interface and deals with user input */

	doublyList<T> List;

	char choice;
	bool isDone = false;


	while (!isDone) {
		std::cout << "\033[2J\033[1;1H"; // clear the screen

		displayMenu();
		std::cout << "####  List  ###########################################################################################"<< std::endl << std::endl;
		List.display();
		std::cout << std::endl;
		std::cout << "#######################################################################################################"<< std::endl << std::endl;
		
		std::cout << "Enter choice here: ";

		std::cin >> choice;

		switch (choice) {
			case 'a': {
				T n;
				std::cout << "Add what ?  ";
				std::cin >> n; 
				List.append(n);
				break;
			}


			case 'n': {
				int nodeN;
				std::cout << "Delete node number ?  ";
				std::cin >> nodeN;
				List.delNode(nodeN);
				break;
			}

			case 'e': {
				std::cout << "\033[2J\033[1;1H";
				isDone = true;
				break;
			}
		}
	}
	
}

template<class T>
doublyList<T>::doublyList() {
	head = NULL;
}

template<class T>
node<T>* doublyList<T>::createNode(T data) {
	node<T>* new_node;
	new_node = new node<T>;
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}

template<class T>
void doublyList<T>::append(T data) {
	node<T>* nNode = createNode(data);

	if (head == NULL) {
		head = nNode;
	}

	else {
		node<T> *temp;

		temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		nNode->prev = temp;
		temp->next = nNode;
	}
}

template<class T>
void doublyList<T>::display() {

	if (head == NULL) {
		std::cout << "Nothing added yet ¯\\_(ツ)_/¯" << std::endl; 
	}

	else {
		node<T>* temp = head;

		while(temp != NULL) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}

		std::cout << std::endl;
	}
}

template<class T>
void doublyList<T>::delNode(int n) {
	if (head == NULL) {
		std::cout << "List is empty!" << std::endl;
		wait(2);
	}

	else if (n == 1) {
		head = head->next;
		std::cout << std::endl << n << " was deleted" << std::endl;
		
	}

	else {
		node<T> *temp1, *temp2;
		temp1 = head;
		temp2 = temp1->next;

		int counter = 2;

		while (counter != n && temp2 != NULL) {
			temp1 = temp1->next;
			temp2 = temp1->next;
			counter++;
		}

		if (counter == n && temp2 != NULL) {
			temp1->next = temp2->next;
			std::cout << "Node number " << n << " was deleted" << std::endl;
		}
		else {
			std::cout << "No node " << n << std::endl;
			wait(2); 
		}

	}
}
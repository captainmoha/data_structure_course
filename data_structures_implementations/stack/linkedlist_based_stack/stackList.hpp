/*Header file implements a singly-circular linkedList-based stack */


template <class T>
struct node
{
	T data;
	node<T> *next;
};

template <class T>
class stack {
	private:
		node<T> *head;
		node<T> *tail;

	public:
		stack();
		node<T>* createNode(T data);
		node<T>* isEmpty();
		void push(T data);
		T pop();
		void display();
		~stack();
};



void wait(int seconds) 
{ 	/*this function is used as a sleep function uses time.h*/
    int endwait; 
    endwait = clock() + seconds * CLOCKS_PER_SEC ; 
    while (clock() < endwait){} 
} 

void displayMenu() {
	/* displays the menu to interact with the s */
	std::cout << "********************************************************************************************************"<< std::endl << std::endl;
	std::cout << "****************************Welcome to the Linkedlist-based Stack interface!****************************"<< std::endl << std::endl;
	std::cout << "********************************************************************************************************"<< std::endl << std::endl;
	std::cout << "Please choose one of the following choices to begin playing with the Stack: " << std::endl << std::endl;
	std::cout << "Enter ( s )  to push an element to the stack." << std::endl;
	std::cout << "Enter ( p )  to pop an element from the stack." << std::endl;
	// std::cout << "Enter ( 3 )  to add an element if it is not contained in the stack." << std::endl;
	// std::cout << "Enter ( s )  to search for an element." << std::endl;
	// std::cout << "Enter ( c )  to count the elements." << std::endl;
	// std::cout << "Enter ( l )  to clear the stack." << std::endl;
	std::cout << "Enter ( e )  to exit this interface." << std::endl << std::endl;
}

template <class T>
void interface() {
	/* handles the interface and deals with user input */
	stack<T> s;

	char choice;
	bool isDone = false;


	while (!isDone) {
		std::cout << "\033[2J\033[1;1H"; // clear the screen
		
		displayMenu();
		std::cout << "####  stack  ##########################################################################################"<< std::endl << std::endl;
		s.display();
		std::cout << std::endl;
		std::cout << "#######################################################################################################"<< std::endl << std::endl;
		
		std::cout << "Enter choice here: ";

		std::cin >> choice;

		switch (choice) {
			case 's': {
				T n;
				std::cout << "Push what ?  ";
				std::cin >> n; 
				s.push(n);
				break;
			}

			case 'p': {
				if (s.isEmpty()) {
					T n;
					n = s.pop();
					std::cout << "Popped " << n << std::endl;
					wait(2);
				}

				else {
					std::cout << "Nothing to pop. The stack is Empty!" << std::endl;
					wait(2);
				}
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



template <class T>
stack<T>::stack() {
	head = NULL;
	tail = NULL;
}

template <class T>
node<T>* stack<T>::createNode(T data) {
	node<T>* newNode = new node<T>;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

template <class T>
node<T>* stack<T>::isEmpty() {
	return head;
}

template <class T>
void stack<T>::display() {


	if (head == NULL) {
		std::cout << "Nothing added yet ¯\\_(ツ)_/¯";
	}

	else {
		node<T> *trav = NULL;
		node<T> *travAhead = head;

		while (trav != tail) {

			std::cout << travAhead->data << " ";
			trav = travAhead;
			travAhead = travAhead->next; 
		}
	}
	std::cout << std::endl;

}


template <class T>
void stack<T>::push(T data) {
	node<T> *nNode = createNode(data);

	if (head == NULL) {
		head = nNode;
		tail = head;
		tail->next = head;
	}

	else {
		tail->next = nNode;
		tail = nNode;
		tail->next = head;
	}
}



template <class T> 
T stack<T>::pop() {

	node<T> *dNode; // node to be deleted
	T poppedData;

	if (head == tail) {

		dNode = head;
		poppedData = head->data;
		head = tail = NULL;
	}

	else {
		dNode = tail;
		poppedData = tail->data;

		node<T> *trav = head;

		while (trav->next != tail) {
			trav = trav->next;
		}

		tail = trav;
		tail->next = head;
	}

	delete dNode;
	return poppedData;
}

template <class T>
stack<T>::~stack() {
	node<T> *temp1 = head;

	while (temp1 != tail) {
		node<T> *temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}

	delete head;
	delete tail;
}
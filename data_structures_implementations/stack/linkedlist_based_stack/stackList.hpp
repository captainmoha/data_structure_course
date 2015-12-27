/*Header file implements a doubly-circular linkedList-based stack */


template <class T>
struct node
{
	T data;
	node<T> *next;
	node<T> *prev;
};

template <class T>
class stack {
	private:
		int top;
		node<T> *head;
		node<T> *tail;

	public:
		stack();
		node<T>* createNode(T data);
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
void interface(int capacity) {
	/* handles the interface and deals with user input */
	stack<T> s(capacity);

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
				T n;
				n = s.pop();
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
	top = -1;
}

template <class T>
node<T>* stack<T>::createNode(T data) {
	node<T>* newNode = new node<T>;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

template <class T>
void stack<T>::push(T data) {
	node<T> *nNode = createNode(data);

	if (head == NULL) {
		head = nNode;
		tail = head;
		tail->next = head;
		tail->prev = head;
	}

	else {
		node<T> *trav = head;

		while (trav != NULL) {
			trav = trav->next;
		}
		trav->next = nNode;
		nNode->prev = trav;
	}
}


template <class T> 
T stack<T>::pop() {

	if (head == NULL) {
		std::cout << "Nothing to pop. Stack is empty!";
		wait(2);
	}


	node<T>* popped;
	else {
		if (head == tail) {
			popped = head;
			head = tail = NULL;
		}

		else {
			popped = tail;	
		}
	}
}


template <class T>
stack<T>::~stack() {

}
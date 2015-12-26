/*Header file implements an array based stack */


template<class T>
class stack {
	private:
		int top;
		int capacity;
		T *buffer;

	public:
		stack(int capacity);
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
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "******************************Welcome to the Array-based Stack interface!******************************"<< std::endl << std::endl;
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
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



template<class T>
stack<T>::stack(int c) {
	capacity = c;
	top = -1;
	buffer = new T[capacity];
}


template<class T>
void stack<T>::push(T data) {
	if (top == (capacity - 1)) {
		std::cout << "Stack is full!" << std::endl;
		wait(2);
	}

	// else if (top == -1){
	// 	buffer[top + 1] = data;
	// 	top++;
	// }

	else {
		buffer[top + 1] = data;
		top++;
	}
}


template<class T>
T stack<T>::pop() {

	T temp;

	if (top == -1) {
		std::cout << "Nothing to pop. The stack is empty!" << std::endl;
		wait(2);
	}

	else {
		temp = buffer[top];
		top--;
		std::cout << "poped " << temp << std::endl;
		wait(2);
		return temp;
	}
}


template<class T>
void stack<T>::display() {
	if (top == -1) {
		std::cout << "Nothing added yet ¯\\_(ツ)_/¯";
	}

	else {
		for (int i = 0; i <= top; i++) {
			std::cout << buffer[i] << " ";
		}
	}

	std::cout << std::endl;
}

template<class T>
stack<T>::~stack() {
	delete[] buffer;
}


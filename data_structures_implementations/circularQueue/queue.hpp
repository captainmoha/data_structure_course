template <class T>
class CircQueue {

	private:
		int front;
		int rear;
		int max;
		T *arr;

	public:
		CircQueue(int size);
		void enqueue(T data);
		bool isEmpty();
		T dequeue();
		void display();
		~CircQueue();	
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
	std::cout << "******************************Welcome to the Array-based Queue interface!******************************"<< std::endl << std::endl;
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "Please choose one of the following choices to begin playing with the Queue: " << std::endl << std::endl;
	std::cout << "Enter ( s )  to enqueue an element to the queue." << std::endl;
	std::cout << "Enter ( p )  to dequeue an element from the queue." << std::endl;
	// std::cout << "Enter ( 3 )  to add an element if it is not contained in the queue." << std::endl;
	// std::cout << "Enter ( s )  to search for an element." << std::endl;
	// std::cout << "Enter ( c )  to count the elements." << std::endl;
	// std::cout << "Enter ( l )  to clear the queue." << std::endl;
	std::cout << "Enter ( e )  to exit this interface." << std::endl << std::endl;
}

template <class T>
void interface(int capacity) {
	/* handles the interface and deals with user input */
	CircQueue<T> q(capacity);

	char choice;
	bool isDone = false;


	while (!isDone) {
		std::cout << "\033[2J\033[1;1H"; // clear the screen
		
		displayMenu();
		std::cout << "####  queue  ##########################################################################################"<< std::endl << std::endl;
		q.display();
		std::cout << std::endl;
		std::cout << "#######################################################################################################"<< std::endl << std::endl;
		
		std::cout << "Enter choice here: ";

		std::cin >> choice;

		switch (choice) {
			case 's': {
				T n;
				std::cout << "Enqueue what ?  ";
				std::cin >> n; 
				q.enqueue(n);
				break;
			}

			case 'p': {

				if (q.isEmpty()) {
					std::cout << "Nothing to dequeue. Queue is empty" << std::endl;
					wait(2);
				}
				
				else {
					T n;
					n = q.dequeue();
					std::cout << "Dequeued " << n << std::endl;
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
CircQueue<T>::CircQueue(int size) {
	max = size;
	arr = new T[size];
	front = rear = -1;
}

template <class T>
void CircQueue<T>::display() {

	if (front == -1) {
		std::cout << "Nothing added yet ¯\\_(ツ)_/¯";
	}

	else {
		for (int i = front; i <= rear; i++) {
			std::cout << arr[i] << " ";
		}
	}

	std::cout << std::endl;
}


template <class T>
void CircQueue<T>::enqueue(T data) {
	if ((front == 0 && rear == (max - 1)) || ((rear+1) == front)) {
		std::cout << "Queue is full" << std::endl;
		wait(2);

	}

	else {
		if (rear == (max-1)) {
			rear = 0;
		}

		else {
			rear++;
		}

		arr[rear] = data;
	}

	if (front == -1) {
		front = 0;
	}
}

template <class T>
bool CircQueue<T>::isEmpty() {
	if (front == -1) {
		return true;
	}

	else {
		return false;
	}
}

template <class T>
T CircQueue<T>::dequeue() {

	T k;

	k = arr[front];

	if (front == rear) {
		front = rear = -1;
	}

	else {
		if (front == (max-1)) {
			front = 0;
		}

		else {
			front++;
		}
	}

	return k;

}


template <class T>
CircQueue<T>::~CircQueue() {

	delete[] arr;
} 
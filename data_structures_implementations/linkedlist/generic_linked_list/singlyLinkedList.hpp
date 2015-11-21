template <class T>
struct node
{
	T data;
	node<T>* next;
};

template <class T>
class linkedList {
	private:
		node<T>* head;

	public:
		linkedList();
		node<T>* createNode(T data);
		void append(T data);
		void addAsFirst(T data);
		void addAfter(T data_in_node, T data_to_insert);
		void addBefore(T data_in_node, T data_to_insert);
		void addAfterPosition(int position, T data);
		void delNode(int data);
		void delAfter(T data);
		void delBefore(T data);
		bool search(T data);
		void del(T data);
		void display();
		int count();
		void swapTwoAdjacent(T data1, T data2);
		~linkedList();	
};


void wait(int seconds) 
{ 	/*this function is used as a sleep function uses time.h*/
    int endwait; 
    endwait = clock() + seconds * CLOCKS_PER_SEC ; 
    while (clock() < endwait){} 
} 

void displayMenu() {
	/* displays the menu to interact with the list */
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "******************************Welcome to the Singly LinkedList interface!******************************"<< std::endl << std::endl;
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "Please choose one of the following choices to begin playing with the LinkedList: " << std::endl << std::endl;
	std::cout << "Enter ( a )  to add an element." << std::endl;
	std::cout << "Enter ( i )  to insert an element as the first element." << std::endl;
	std::cout << "Enter ( 1 )  to add an element after a certain element." << std::endl;
	std::cout << "Enter ( 2 )  to add an element before a certain element." << std::endl;
	std::cout << "Enter ( p )  to add an element after a certain position." << std::endl;
	std::cout << "Enter ( n )  to delete a certain node." << std::endl;
	std::cout << "Enter ( > )  to delete an element after a certain element." << std::endl;
	std::cout << "Enter ( < )  to delte an element before a certain element." << std::endl;
	std::cout << "Enter ( s )  to search for an element." << std::endl;
	std::cout << "Enter ( d ) to delete an element." << std::endl;
	std::cout << "Enter ( c ) to count the elements." << std::endl;
	std::cout << "Enter ( w ) to swap two adjacent elements." << std::endl;
	std::cout << "Enter ( e )  to exit this interface." << std::endl << std::endl;
}

template <class T>
void interface() {
	/* handles the interface and deals with user input */
	linkedList<T> List;

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

			case 'i': {
				T n;
				std::cout << "Add what as first ?  ";
				std::cin >> n;
				List.addAsFirst(n);
				break;
			}
			case '1': {
				T afterN, n;
				std::cout << "Add what ?  ";
				std::cin >> n;
				std::cout << std::endl << "After which element ?  ";
				std::cin >> afterN;
				List.addAfter(afterN, n);
				break;
			}

			case '2': {
				T beforeN, n;
				std::cout << "Add what ?  ";
				std::cin >> n;
				std::cout << std::endl << "Before which element ?  ";
				std::cin >> beforeN;
				List.addBefore(beforeN, n);
				break;
			}

			case 'p': {
				T n;
				int pos;
				std::cout << "Add what ?  ";
				std::cin >> n;
				std::cout << std::endl << "After position number ?  ";
				std::cin >> pos;
				List.addAfterPosition(pos, n);
				break;
			}

			case 'n': {
				int nodeN;
				std::cout << "Delete node number ?  ";
				std::cin >> nodeN;
				List.delNode(nodeN);
				break;
			}

			case '>': {
				T n;
				std::cout << "Delete element after what ?  ";
				std::cin >> n;
				List.delAfter(n);
				break;
			}
			
			case '<': {
				T n;
				std::cout << "Delete element before what ?  ";
				std::cin >> n;
				List.delBefore(n);
				break;
			}

			case 's': {
				T n;
				std::cout << "What do you wanna search for ?  ";
				std::cin >> n;
				List.search(n);
				break;
			}

			case 'd': {
				T n;
				std::cout << "Delete what ?  ";
				std::cin >> n;
				List.del(n);
				break;
			}

			case 'c': {
				List.count();
				break;
			}

			case 'w': {
				T n, n2;
				std::cout << "Swap what ?  ";
				std::cin >> n;
				std::cout << std::endl << "What is next to that ?  ";
				std::cin >> n2;
				List.swapTwoAdjacent(n, n2);
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



// constructor initializes head to null
template <class T>
linkedList<T>::linkedList()
{
	head = NULL;
}


template <class T>// create node
node<T>* linkedList<T>::createNode(T data) 
{
	node<T>* new_node;
	new_node = new node<T>;
	new_node -> data = data;
	new_node -> next = NULL;

	return new_node;
}

template <class T>
void linkedList<T>::append(T data)
{
	node<T> *temp, *nNode;
	nNode = createNode(data);
	if (head == NULL) {
		head = nNode;
	}

	else {
		temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = nNode;

	}
}

template <class T>
void linkedList<T>::display()
{
	// if the list is empty
	if (head == NULL) {
		std::cout << "No nodes added yet!" << std::endl;
	}

	else {
		// create a temp variable to hold the heads
		node<T>* temp = head;
		// as long as we haven't reached the end of the list
		while (temp != NULL) {
			// print current element
			std::cout << temp->data << " ";
			// go to the next node
			temp = temp->next;
		}
		std::cout << std::endl;
	}
}

template <class T>
int linkedList<T>::count()
{
	int counter = 0;
	if (head == NULL) {
		std::cout << std::endl << "The list has " << counter << " elements." << std::endl;
	}

	else {
		// node* temp = head;
		
		// while (temp != NULL) {
		// 	counter++;
		// 	temp = temp->next;

			for (node<T>* temp = head; temp != NULL; temp = temp->next) {
				counter++;
			}
		}

	std::cout << std::endl << "The list has " << counter << " elements." << std::endl;
	wait(3);
}

template <class T>
void linkedList<T>::del(T n) {
	bool isFound = false;
	if (head == NULL) {
		std::cout << "No elements are in the list " << std::endl;
		wait(2);
	}

	else if (head-> next == NULL) {
		head = NULL;
		std::cout << std::endl << n << " was deleted" << std::endl;
		isFound = true;
		wait(2);	
	}

	else {
		node<T> *temp1, *temp2;
		

		for (temp1 = head, temp2 = temp1->next; temp2 != NULL;  temp1 = temp1->next, temp2 = temp1->next) {
			if (temp1->data == n) {
				
				head = temp2;
				std::cout << std::endl << n << " was deleted" << std::endl;
				isFound = true;
				wait(2);
				break;
			}
			else if (temp2->data == n) {
				temp1->next = temp2->next;
				std::cout << std::endl << n << " was deleted" << std::endl;
				isFound = true;
				wait(2);
				break;
			}

		}
	}

	if (!isFound) {
		std::cout << "No element " << n << " exists in the list!" << std::endl;
		wait(2);
	}
		
}


template <class T>// this function is working!
void linkedList<T>::swapTwoAdjacent(T data1, T data2) {
	node<T> *temp1, *temp2, *temp3;
	

	temp1 = head;
	temp2 = temp1->next;

	if (head == NULL) {
		std::cout << "List is empty" << std::endl;
		wait(2);
		return;
	}
	else if (head->next == NULL) {
		std::cout << "Swap not possible! List has only one node." << std::endl;
		wait(2);
	}

	else if (temp1->data == data1 && temp2->data == data2) {      // if the nodes to swap are the first two nodes
				head->next = temp2->next;  	// make the next of head point to the third node
				temp2->next = head;			// make the next of the second node point to head
				head = temp2;
				return;				// now make the second node the head
			}

	
	else {
		node<T> *tempHolder1, *tempHolder2, *tempHolder3;  // holders for nodes in temps to make swapping easier

		// go through nodes in the list with three pointers
		// temp1->temp2->temp3
		// I'm using three pointers so that I always know the node before the two nodes I'm looking for

		for (temp1 = head, temp2 = temp1->next, temp3 = temp2->next; temp3 != NULL; temp1 = temp1->next, temp2 = temp1->next, temp3 = temp2->next) {
			// std::cout << "IN FOR" << std::endl;
			
			if (temp2->data == data1 && temp3->data == data2) { // if the two nodes are found

				// these are just placeholders to make swapping easier

				tempHolder1 = temp1;	// now temp1 is the node before the two nodes I want to swap
				tempHolder2 = temp2;	// temp2 is the first node
				tempHolder3 = temp3;	// temp3 is the second node

				temp1->next = tempHolder2->next;		// make the first node point to the third node
				temp2->next = tempHolder3->next;		// make the second node point to what's after the third node
				temp3->next = tempHolder2;				// make the third node point to the second node
				
				break;
				
			}

			else {
				continue;
			}
		}

	}
	std::cout << "Swap not possible! " << std::endl;
	wait(2);
	
}


// template <class T>
// void linkedList<T>::swapTwoAdjacent(int data1, int data2)
// {
//     if (head == NULL) {
//         std::cout << "List is empty" << std::endl;
//         return;
//     }
//     node** np = &head; //two star programmer club
//     node* temp;
//     while ((*np)->next != NULL) //As long as next node exists
//     {
//         if ((*np)->data == data1 && (*np)->next->data == data2)
//         {
//             temp = *np; //temp = &node1
//             *np = (*np)->next; //node0->next = &node2
//             temp->next = (*np)->next; //node1->next = node2->next
//             (*np)->next = temp; //node2->next = node1
//             //node0->node2->node1->node3
//             //If you want to only swap the first pair of values you find, uncomment the next line, otherwise it swaps every matching pair
//             //return;
//         }
//         np = &((*np)->next); //Point to pointer to next node
//     }
// }

template <class T>
void linkedList<T>::addAsFirst(T data) {
	node<T> *nNode;
	nNode = createNode(data);
	nNode->next = head;
	head = nNode;
}

template <class T>
void linkedList<T>::addAfter(T data_in_node, T data_to_insert) {
	node<T> *temp, *nNode;
	temp = head;

	if (temp == NULL) {
		std::cout << "List is empty" << std::endl;
		wait(2);
	}
	while (temp != NULL) {
		if (temp->data == data_in_node) {
			nNode = createNode(data_to_insert);
			nNode->next = temp->next;
			temp->next = nNode;
			return;
		} 
		temp = temp->next;
	}

	std::cout << "There is no node that contains " << data_in_node << std::endl;
	wait(2);
}

template <class T>
void linkedList<T>::addBefore(T data_in_node, T data_to_insert) {
	if (head == NULL) {
		std::cout << "List is empty" << std::endl;
	}

	else if (head->data == data_in_node) {
		addAsFirst(data_to_insert);
		return;
	}

	else {
		node<T> *temp1, *temp2, *nNode;
		temp1 = head;
		temp2 = temp1->next;

		while (temp2 != NULL) {
		if (temp2->data == data_in_node) {
			nNode = createNode(data_to_insert);
			nNode->next = temp2;
			temp1->next = nNode;
			return;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
		
		}
	}
	
	std::cout << "There is no node that contains " << data_in_node << std::endl;
	wait(2);
}

template <class T>
void linkedList<T>::addAfterPosition(int position, T data) {
	node<T> *nNode, *temp;
	temp = head;

	if (position == 0) {    // adding after the zero's position is adding it as first
		addAsFirst(data);
		return;
	}

	int counter = 1;		// make it start from 1 not 0

	while (temp != NULL && counter < position) {
		temp = temp->next;
		counter++;
	}

	if (counter < position) {		// this means that the loop quit because temp is NULL and position hasn't been found 
		std::cout << "The list is too short. There is no position " << position << std::endl;
		wait(2);
		return;
	}

	nNode = createNode(data);
	nNode->next = temp->next;
	temp->next = nNode;	
}

template <class T>
void linkedList<T>::delNode(int n) {

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

template <class T>
void linkedList<T>::delAfter(T data) {
	
	node<T> *temp1, *temp2;
		
	for (temp1 = head, temp2 = temp1->next; temp2 != NULL; temp1 = temp1->next, temp2 = temp1->next) {
		if (temp1->data == data) {
			temp1->next = temp2->next;
			return;
		}
	}

	if (temp2 == NULL) {
		std::cout << "There is nothing after " << temp1->data << std::endl;
	}
	else {
		std::cout << "No node that contains " << data << " was found " << std::endl;
	}
	
	wait(2);  
}

template <class T>
void linkedList<T>::delBefore(T data) {
	
	if (head == NULL) {
		std::cout << "List is empty! " << std::endl;
		wait(2);
	}

	else if  (head->next == NULL && head->data == data) {
		std::cout << "No nodes exist before the node that contains " << data << std::endl;
		wait(2); 
	}

	else if  (head->next == NULL && head->data != data) {
		std::cout << "No node that contains " << data << " exists"<< std::endl;
		wait(2);
	}

	else if (head->next->data == data) {
		head = head->next;
		return;
	}
	else {
		node<T> *temp1, *temp2, *temp3;

		for (temp1 = head, temp2 = temp1->next, temp3 = temp2->next; temp3 != NULL; temp1 = temp1->next, temp2 = temp1->next, temp3 = temp2->next) {		
			if (temp3->data == data) {
				temp1->next = temp3;
				return;
			}
		}
	}
	
	std::cout << "Couldn't delete the node before the node that contains " << data << std::endl;
	wait(2);
}

template <class T>
bool linkedList<T>::search(T data) {
	int counter = 0;

	if (head == NULL) {
		std::cout << "List is empty!" << std::endl;
		wait(2);
	}

	else if (head->data == data) {
		counter++;
		std::cout << "Found the the node that contains " << data << " At node " << counter << std::endl;
		wait(3);
		return true;
	}

	else {
		node<T> *temp1 = head;

		while (temp1 != NULL) {
			std::cout << temp1->data << std::endl;
			counter++;
			if (temp1->data == data) {
				std::cout << "Found the node that contains " << data << " At node " << counter << std::endl;
				wait(3);
				return true;
			}

			temp1 = temp1->next;
		}
		std::cout << "No node that contains " << data << " was found!" << std::endl;
		wait(3);
		return false;
	}
}

template <class T>
linkedList<T>::~linkedList() {
	node<T> *temp1 = head;

	while (temp1 != NULL) {
		node<T> *temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}
	head = NULL;
}
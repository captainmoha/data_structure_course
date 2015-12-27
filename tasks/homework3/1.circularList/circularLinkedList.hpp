
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
		node<T>* tail;

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
		void addIfNotThere(T data);
		void clrRecursive();
		// sort
		// reverse
		// swap
		// arraytize
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
	std::cout << "*****************************Welcome to the Circular LinkedList interface!*****************************"<< std::endl << std::endl;
	std::cout << "*******************************************************************************************************"<< std::endl << std::endl;
	std::cout << "Please choose one of the following choices to begin playing with the LinkedList: " << std::endl << std::endl;
	std::cout << "Enter ( a )  to add an element." << std::endl;
	std::cout << "Enter ( i )  to insert an element as the first element." << std::endl;
	std::cout << "Enter ( 1 )  to add an element after a certain element." << std::endl;
	std::cout << "Enter ( 2 )  to add an element before a certain element." << std::endl;
	std::cout << "Enter ( 3 )  to add an element if it is not contained in the list." << std::endl;
	std::cout << "Enter ( p )  to add an element after a certain position." << std::endl;
	std::cout << "Enter ( n )  to delete a certain node." << std::endl;
	std::cout << "Enter ( > )  to delete an element after a certain element." << std::endl;
	std::cout << "Enter ( < )  to delete an element before a certain element." << std::endl;
	std::cout << "Enter ( s )  to search for an element." << std::endl;
	std::cout << "Enter ( d )  to delete an element." << std::endl;
	std::cout << "Enter ( c )  to count the elements." << std::endl;
	std::cout << "Enter ( w )  to swap two adjacent elements." << std::endl;
	std::cout << "Enter ( l )  to clear the list recursively." << std::endl;
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

			case '3': {
				T data;
				std::cout << "Add what ?  ";
				std::cin >> data;
				List.addIfNotThere(data);
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

			case 'l': {
				List.clrRecursive();
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
	tail = NULL;
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
	node<T> *nNode;
	nNode = createNode(data);
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
void linkedList<T>::display()
{
	// if the list is empty
	if (head == NULL) {
		std::cout << "No nodes added yet!" << std::endl;
	}

	else {
		// create a temp variable to hold the head and a variable to be a step back
		node<T>* temp = head;
		node<T>* prev = NULL;
		// as long as we haven't seen the tail
		while (prev != tail) {
			// print current element
			std::cout << temp->data << " ";
			// go to the next node
			prev = temp;
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
		node<T>* temp = head;
		node<T>* prev = NULL;
		
		while (prev != tail) {
			counter++;
			prev = temp;
			temp = temp->next;
		}

	std::cout << std::endl << "The list has " << counter << " elements." << std::endl;
	wait(3);
	}
}

template <class T>
void linkedList<T>::del(T n) {

	bool isFound = false;
	node<T> *dNode;    // node to store the node to be deleted
	// list is empty
	if (head == NULL) { 
		std::cout << "No elements are in the list " << std::endl;
		wait(2);
	}
	
	// list is not empty
	else {
		node<T> *temp, *prev;	// temp will be one step ahead of prev

		// the list has only one node and it's the one to be deleted
		if (head->data == n && head == tail) {
			dNode = head;
			head = tail = NULL;
			isFound = true;
		}

		// the node to be deleted is the first one
		else if (head->data == n && head != tail) {
			dNode = head;
			head = head->next;
			tail->next = head;
			isFound = true;
		}
		// the node to be deleted is the last one
		else if (tail->data == n) {
			dNode = tail;
			temp = head;
			while (temp != tail) {
				prev = temp;
				temp = temp->next;
			}
			tail = prev;
			tail->next = head;
			isFound = true;
		}

		// the node to be deleted is between the first and last nodes
		else {
			prev = NULL;
			temp = head;

			while (temp != tail && temp->data != n) {
				prev = temp;
				temp = temp->next;
			}

			if (temp->data == n) {
				dNode = temp;
				prev->next = temp->next;
				isFound = true;
			}

		}
	}

	
	if (!isFound) {
		std::cout << "No element " << n << " exists in the list!" << std::endl;
		wait(2);
	}
	else {
		std::cout << std::endl << n << " was deleted" << std::endl;
		wait(2);
		delete dNode;
	}
		
}


template <class T>// this function is working!
void linkedList<T>::swapTwoAdjacent(T data1, T data2) {
	node<T> *prev, *temp;
	
	if (head == NULL) {
		std::cout << "List is empty" << std::endl;
		wait(2);
		return;
	}
	else if (head == tail) {
		std::cout << "Swap not possible! List has only one node." << std::endl;
		wait(2);
	}

	// the list has only two nodes
	else if (head->next == tail && (head->data == data1 && tail->data == data2)) {
		
		prev = head;
		temp = tail;

		head = temp;
		tail = prev;

		head->next = tail;
		tail->next = head;
		return;
	}

	else {
		// the nodes to be swapped are the first two nodes
		if (head->data == data1 && head->next->data == data2) {
			prev = head;
			temp = head->next;

			head = head->next;
			prev->next = temp->next;
			head->next = prev;
			tail->next = head;
			return;
		}

		else {
			// TODO if the nodes to be swapped are the last two
			// TODO if the nodes to be swapped are in the middle
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
	tail->next = head;
}

template <class T>
void linkedList<T>::addAfter(T data_in_node, T data_to_insert) {
	node<T> *temp, *nNode;
	temp = head;

	if (temp == NULL) {
		std::cout << "List is empty" << std::endl;
		wait(2);
	}
	else {
		if (tail->data == data_in_node) {
			nNode = createNode(data_to_insert);
			nNode->next = head;
			tail->next = nNode;
			tail = nNode;
			return;
		}

		else {
			while (temp != tail) {
				if (temp->data == data_in_node) {
					nNode = createNode(data_to_insert);
					nNode->next = temp->next;
					temp->next = nNode;
					return;
				} 
				temp = temp->next;
			}
		}
		
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

		while (temp2 != head) {
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

	else {
		int counter = 1;		// make it start from 1 not 0
		while (temp != tail && counter < position) {
			temp = temp->next;
			counter++;
		}
		// the node to be deleted is the last element
		if (temp == tail && counter == position) {
			nNode = createNode(data);
			nNode->next = head;
			tail->next = nNode;
			tail = nNode;
		}

		else if (temp != tail) {		// this means that the loop quit because position hasn't been found 
			nNode = createNode(data);
			nNode->next = temp->next;
			temp->next = nNode;	
		}
		// the node to be deleted is between the first and last element
		else {
			std::cout << "The list is too short. There is no position " << position << std::endl;
			wait(2);
		}
	}	
}

template <class T>
void linkedList<T>::delNode(int n) {

	node<T> *dNode; // node to be deleted
	bool isFound = false;

	if (head == NULL) {
		std::cout << "List is empty!" << std::endl;
		wait(2);
	}
	// the node to be deleted is the first one
	else if (n == 1) {
		dNode = head;
		isFound = true;	

		// the list has more than one node
		if (head != tail) {
			head = head->next;
			tail->next = head;
		}
		else {
			head = tail = NULL;
		}
	}

	else {
		node<T> *prev, *temp;
		prev = head;
		temp = prev->next;

		int counter = 2;

		while (counter != n && temp != head) {
			prev = prev->next;
			temp = prev->next;
			counter++;
		}

		if (counter == n && temp != head) {
			isFound = true; 
			// the node to be deleted is the last one
			if (temp == tail) {
				dNode = tail;
				tail = prev;
				prev->next = head;
			}
			// the node to be deleted is between the first and last one
			else {
				dNode = temp;
				prev->next = temp->next;
			}
		}

	}


	if (isFound) {
		delete dNode;
		std::cout << std::endl << n << " was deleted" << std::endl;
		wait(2);
	}
	else {
		std::cout << "No node " << n << std::endl;
		wait(2); 
	}
}

template <class T>
void linkedList<T>::delAfter(T data) {
	
	node<T> *prev, *temp;
	node<T> *dNode;
	bool isFound = false;

	if (head == NULL) {
		std::cout << "The list is empty" << std::endl;
		wait(2);
	}

	else {
		// the list has only one node
		if (head == tail && head->data == data) {
			// it was a design choice to not allow the deletion of the only node in the list even though it's circular.
			// ie it's next is itself

			std::cout << "There is nothing after " << head->data << std::endl;
			isFound = true;
			wait(2);
		}

		// the node to be deleted is the head (because it's the next of tail)
		else if (tail->data == data){
			dNode = head;
			isFound = true;
			head = head->next;
			tail->next = head;	
		}

		else {
			prev = NULL;
			temp = head;
			while (temp->next != tail && temp->data != data) {
				prev = temp;
				temp = temp->next;
			}

			// the node to be deleted is between the first and last node
			if (temp->next != tail && temp->data == data) {
				dNode = temp->next;
				isFound = true;
				temp->next = temp->next->next;
			}

			// the node to be deleted is the last node
			else if (temp->next == tail && temp->data == data) {
				dNode = tail;
				isFound = true;
				temp->next = head;
				tail = temp;
			}
		}

	}
	
	if (!isFound) {
		std::cout << "No node that contains " << data << " was found " << std::endl;
		wait(2);  
	}

	else {
		delete dNode;
	}	
	
}

template <class T>
void linkedList<T>::delBefore(T data) {

	bool isFound = false;
	node<T> *dNode;

	if (head == NULL) {
		std::cout << "List is empty! " << std::endl;
		wait(2);
	}

	else {
		node<T> *prev, *temp;
		
		if (head->data == data) {
			std::cout << "There is nothing before " << head->data << std::endl;
			wait(2);
			return;
		}

		// the node to be deleted is the first node (head)
		else if (head->next->data == data) {
			dNode = head;
			isFound = true;
			tail->next = head->next;
			head = head->next;
		}

		// the node to be deleted is the one before the tail
		else if (tail->data == data) {
			prev = NULL;
			temp = head;

			while(temp->next != tail) {
				prev = temp;
				temp = temp->next;
			}
			dNode = temp;
			isFound = true;
			prev->next = tail;
		}

		// the node to be deleted is between the head and the tail
		else {
			prev = NULL;
			temp = head;

			while (temp->next != tail && temp->next->data != data) {
				prev = temp;
				temp = temp->next;
			}
			if (temp->next != tail && temp->next->data == data) {
				dNode = temp;
				isFound = true;
				prev->next = temp->next;
			}
		}
	}

	if (!isFound) {
		std::cout << "There is no node that contains " << data << std::endl;
		wait(2);
	}

	else {
		delete dNode;
	}
}

template <class T>
bool linkedList<T>::search(T data) {
	int counter = 0;

	if (head == NULL) {
		std::cout << "List is empty!" << std::endl;
		wait(2);
	}

	// the data is in the first node
	else if (head->data == data) {
		counter++;
		std::cout << "Found the the node that contains " << data << " At node " << counter << std::endl;
		wait(3);
		return true;
	}

	else {
		node<T> *temp = head;

		while (temp != tail) {
			// std::cout << temp->data << std::endl;
			counter++;
			if (temp->data == data) {
				std::cout << "Found the node that contains " << data << " At node " << counter << std::endl;
				wait(3);
				return true;
			}

			temp = temp->next;
		}

		// the data is in the last node
		if (temp == tail && temp->data == data) {
			counter++;
			std::cout << "Found the node that contains " << data << " At node " << counter << std::endl;
			wait(3);
			return true;
		}

		std::cout << "No node that contains " << data << " was found!" << std::endl;
		wait(3);
		return false;
	}
}

template <class T>
void linkedList<T>::addIfNotThere(T data) {
	bool check = search(data);

	if (!check) {
		append(data);
	}	

	else {
		std::cout << "The element already exists" << std::endl;
		wait(2);
	}
}

template <class T>
void linkedList<T>::clrRecursive() {
	node<T> *temp1 = head;


	if (head == NULL) {
		std::cout << "List is empty" << std::endl;
		wait(2);
	}
	else if (head->next == head) {
		delete temp1;
		head = tail = NULL;
		std::cout << "List was cleared" << std::endl;
		wait(2);
	}
	else {
		// std::cout << "In else" << std::endl;
		// wait(1);
		node<T> *temp2;
		temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
		clrRecursive();
	}
}

template <class T>
linkedList<T>::~linkedList() {
	node<T> *temp1 = head;

	while (temp1 != tail) {
		node<T> *temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}
	delete tail;
}

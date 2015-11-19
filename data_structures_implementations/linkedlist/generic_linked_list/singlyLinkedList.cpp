#include "singlyLinkedList.hpp"
#include <iostream>

using namespace std;
// constructor initializes head to null
template <class T>
linkedList<T>::linkedList()
{
	head = NULL;
}


template <class T>// create node
node<T>* linkedList<T>::createNode(T num) 
{
	node<T>* new_node;
	new_node = new node<T>;
	new_node -> data = num;
	new_node -> next = NULL;

	return new_node;
}

template <class T>
void linkedList<T>::append(T num)
{
	node<T> *temp, *nNode;
	nNode = createNode(num);
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
		cout << "No nodes added yet!" << endl;
	}

	else {
		// create a temp variable to hold the heads
		node<T>* temp = head;
		// as long as we haven't reached the end of the list
		while (temp != NULL) {
			// print current element
			cout << temp->data << " ";
			// go to the next node
			temp = temp->next;
		}
		cout << endl;
	}
}

template <class T>
int linkedList<T>::count()
{
	int counter = 0;
	if (head == NULL) {
		cout << endl << "The list has " << counter << " elements." << endl;
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

	cout << endl << "The list has " << counter << " elements." << endl;
}

template <class T>
void linkedList<T>::del(T n) {
	if (head == NULL) {
		cout << "No elements are in the list " << endl;
	}

	else if (head-> next == NULL) {
		head = NULL;
		cout << endl << n << " was deleted" << endl;
		cout << endl << "Current elements in the list :" << endl << "-----------------------------------------" << endl;
		// this->display();	
	}

	else {
		node<T> *temp1, *temp2;
		

		for (temp1 = head, temp2 = temp1->next; temp2 != NULL;  temp1 = temp1->next, temp2 = temp1->next) {
			if (temp1->data == n) {
				
				head = temp2;
				cout << endl << n << " was deleted" << endl;
				cout << endl << "Current elements in the list :" << endl << "-----------------------------------------" << endl;
				// this->display();
				break;
			}
			else if (temp2->data == n) {
				temp1->next = temp2->next;
				cout << endl << n << " was deleted" << endl;
				cout << endl << "Current elements in the list :" << endl << "-----------------------------------------" << endl;
				// this->display();
				break;
			}


			else {
				continue;
			}
		}
	}
		
}


template <class T>// this function is working!
void linkedList<T>::swapTwoAdjacent(T num1, T num2) {
	node<T> *temp1, *temp2, *temp3;
	

	temp1 = head;
	temp2 = temp1->next;

	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	else if (head->next == NULL) {
		cout << "Swap not possible! List has only one node." << endl;
	}

	else if (temp1->data == num1 && temp2->data == num2) {      // if the nodes to swap are the first two nodes
				head->next = temp2->next;  	// make the next of head point to the third node
				temp2->next = head;			// make the next of the second node point to head
				head = temp2;				// now make the second node the head
			}

	
	else {
		node<T> *tempHolder1, *tempHolder2, *tempHolder3;  // holders for nodes in temps to make swapping easier

		// go through nodes in the list with three pointers
		// temp1->temp2->temp3
		// I'm using three pointers so that I always know the node before the two nodes I'm looking for

		for (temp1 = head, temp2 = temp1->next, temp3 = temp2->next; temp3 != NULL; temp1 = temp1->next, temp2 = temp1->next, temp3 = temp2->next) {
			// cout << "IN FOR" << endl;
			
			if (temp2->data == num1 && temp3->data == num2) { // if the two nodes are found

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
	
}


// template <class T>
// void linkedList<T>::swapTwoAdjacent(int num1, int num2)
// {
//     if (head == NULL) {
//         cout << "List is empty" << endl;
//         return;
//     }
//     node** np = &head; //two star programmer club
//     node* temp;
//     while ((*np)->next != NULL) //As long as next node exists
//     {
//         if ((*np)->data == num1 && (*np)->next->data == num2)
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
void linkedList<T>::addAsFirst(T num) {
	node<T> *nNode;
	nNode = createNode(num);
	nNode->next = head;
	head = nNode;
}

template <class T>
void linkedList<T>::addAfter(T data_in_node, T data_to_insert) {
	node<T> *temp, *nNode;
	temp = head;

	if (temp == NULL) {
		cout << "List is empty" << endl;
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

	cout << "There is no node that contains " << data_in_node << endl;
}

template <class T>
void linkedList<T>::addBefore(T data_in_node, T data_to_insert) {
	node<T> *temp1, *temp2, *nNode;
	temp1 = head;
	temp2 = temp1->next;

	if (temp1 == NULL) {
		cout << "List is empty" << endl;
	}

	while (temp2 != NULL) {
		if (temp2->data == data_in_node) {
			nNode = createNode(data_to_insert);
			nNode->next = temp2;
			temp1->next = nNode;
			break;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
		
	}
	cout << "There is no node that contains " << data_in_node << endl;
}

template <class T>
void linkedList<T>::addAfterPosition(int position, T num) {
	node<T> *nNode, *temp;
	temp = head;

	if (position == 0) {    // adding after the zero's position is adding it as first
		addAsFirst(num);
		return;
	}

	int counter = 1;		// make it start from 1 not 0

	while (temp != NULL && counter < position) {
		temp = temp->next;
		counter++;
	}

	if (counter < position) {		// this means that the loop quit because temp is NULL and position hasn't been found 
		cout << "The list is too short. There is no position " << position << endl;
		return;
	}

	nNode = createNode(num);
	nNode->next = temp->next;
	temp->next = nNode;	
}

template <class T>
void linkedList<T>::delNode(int num) {

	if (head == NULL) {
		cout << "List is empty" << endl;
	}

	else if (head->next == NULL) {
		head = NULL;
		cout << "The node that has the element " << num << " was deleted" << endl;
	}
	else {
		node<T> *temp1, *temp2, *node2Del;
		bool isFound = false;

		for (temp1 = head, temp2 = temp1->next; temp2 != NULL; temp1 = temp1->next, temp2 = temp1->next) {
			if (temp2->data == num) {
				node2Del = temp2;
				temp1->next = node2Del->next;
				cout << "The node that has the element " << num << " was deleted" << endl;
				isFound = true; 
				break;
			}

		}

		if(!isFound) {
			cout << "There is no node that contains " << num << endl;
		}
	}
}

template <class T>
void linkedList<T>::delAfter(T num) {
	
	node<T> *temp1, *temp2;
		
	for (temp1 = head, temp2 = temp1->next; temp2 != NULL; temp1 = temp1->next, temp2 = temp1->next) {
		if (temp1->data == num) {
			temp1->next = temp2->next;
			return;
		}
	}

	cout << "No node that contains " << num << " was found " << endl; 
}

template <class T>
void linkedList<T>::delBefore(T num) {
	
	if (head == NULL) {
		cout << "List is empty! " << endl;
	}

	else if  (head->next == NULL && head->data == num) {
		cout << "No nodes exist before the node that contains " << num << endl; 
	}

	else if  (head->next == NULL && head->data != num) {
		cout << "No node that contains " << num << " exists"<< endl;
	}

	else if (head->next->data == num) {
		head = head->next;
		return;
	}
	else {
		node<T> *temp1, *temp2, *temp3;

		for (temp1 = head, temp2 = temp1->next, temp3 = temp2->next; temp3 != NULL; temp1 = temp1->next, temp2 = temp1->next, temp3 = temp2->next) {		
			if (temp3->data == num) {
				temp1->next = temp3;
				return;
			}
		}
	}
	
	cout << "Couldn't delete the node before the node that contains " << num << endl;
}

template <class T>
bool linkedList<T>::search(T num) {
	int counter = 0;

	if (head == NULL) {
		cout << "List is empty!" << endl;
	}

	else if (head->data == num) {
		counter++;
		cout << "Found the the node that contains " << num << " At node " << counter << endl;
		return true;
	}

	else {
		node<T> *temp1 = head;

		while (temp1 != NULL) {
			cout << temp1->data << endl;
			counter++;
			if (temp1->data == num) {
				cout << "Found the node that contains " << num << " At node " << counter << endl;
				return true;
			}

			temp1 = temp1->next;
		}
		cout << "No node that contains " << num << " was found!" << endl;
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
#include "singlyLinkedList.hpp"
#include <iostream>
#include <time.h>

void wait(int seconds) 
{ 
    int endwait; 
    endwait = clock() + seconds * CLOCKS_PER_SEC ; 
    while (clock() < endwait){} 
} 

using namespace std;
// constructor initializes head to null
linkedList::linkedList()
{
	head = NULL;
}

// create node
node* linkedList::createNode(int num) 
{
	node* new_node;
	new_node = new node;
	new_node -> data = num;
	new_node -> next = NULL;

	return new_node;
}

void linkedList::append(int num)
{
	node *temp, *nNode;
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

void linkedList::display()
{
	// if the list is empty
	if (head == NULL) {
		cout << "No nodes added yet!" << endl;
	}

	else {
		// create a temp variable to hold the heads
		node* temp = head;
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

int linkedList::count()
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

			for (node* temp = head; temp != NULL; temp = temp->next) {
				counter++;
			}
		}

	cout << endl << "The list has " << counter << " elements." << endl;
	wait(3);
}

void linkedList::del(int n) {

	node *dNode;

	bool isFound = false;
	if (head == NULL) {
		cout << "No elements are in the list " << endl;
		wait(2);
	}

	else {
		// the node to be deleted is the first one and the list has only one
		if (head->data == n && head->next == NULL) {
			dNode = head;
			head = NULL;
			isFound = true;
		}

		// the node to be deleted is the first one and the list has multiple nodes
		else if (head->data == n) {
			dNode = head;
			head = head->next;
			isFound = true;
		}

		// the node to be deleted is after the first one

		else {
			node *trav = NULL;
			node *travAhead = head;

			while (travAhead != NULL) {
				trav = travAhead;
				travAhead = travAhead->next;


				if (travAhead->data == n) {
					dNode = travAhead;
					trav->next = travAhead->next;
					isFound = true;
					break;
				}
			}
		}

	}


	if (!isFound) {
		cout << "No element " << n << " exists in the list!" << endl;
		wait(2);
	}

	else {
		delete dNode;
	}	
}

// this function is working!
void linkedList::swapTwoAdjacent(int num1, int num2) {
	node *temp1, *temp2, *temp3;
	

	temp1 = head;
	temp2 = temp1->next;

	if (head == NULL) {
		cout << "List is empty" << endl;
		wait(2);
		return;
	}
	else if (head->next == NULL) {
		cout << "Swap not possible! List has only one node." << endl;
		wait(2);
	}

	else if (temp1->data == num1 && temp2->data == num2) {      // if the nodes to swap are the first two nodes
				head->next = temp2->next;  	// make the next of head point to the third node
				temp2->next = head;			// make the next of the second node point to head
				head = temp2;				// now make the second node the head
				return;
			}

	
	else {
		node *tempHolder1, *tempHolder2, *tempHolder3;  // holders for nodes in temps to make swapping easier

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
				
				return;
				
			}

			else {
				continue;
			}
		}

	}
	cout << "Swap not possible! " << endl;
	wait(2);
	
}


// void linkedList::swapTwoAdjacent(int num1, int num2)
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

void linkedList::addAsFirst(int num) {
	node *nNode;
	nNode = createNode(num);
	nNode->next = head;
	head = nNode;
}

void linkedList::addAfter(int data_in_node, int data_to_insert) {
	node *temp, *nNode;
	temp = head;

	if (temp == NULL) {
		cout << "List is empty" << endl;
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

	cout << "There is no node that contains " << data_in_node << endl;
	wait(2);

}

void linkedList::addBefore(int data_in_node, int data_to_insert) {
	

	if (head == NULL) {
		cout << "List is empty" << endl;
		wait(2);
	}

	else if (head->data == data_in_node) {
		addAsFirst(data_to_insert);
		return;
	}

	else {
		node *temp1, *temp2, *nNode;
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
	
	cout << "There is no node that contains " << data_in_node << endl;
	wait(2);
}

void linkedList::addAfterPosition(int position, int num) {
	node *nNode, *temp;
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
		wait(2);
		return;
	}

	nNode = createNode(num);
	nNode->next = temp->next;
	temp->next = nNode;	
}

void linkedList::delNode(int n) {
	node *dNode; // node to be deleted
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
		if (head->next != NULL) {
			head = head->next;
		}
		else {
			head = NULL;
		}
	}

	else {
		node *prev, *temp;
		prev = head;
		temp = prev->next;

		int counter = 2;

		while (counter != n && temp != head) {
			prev = prev->next;
			temp = prev->next;
			counter++;
		}

		if (counter == n && temp != head) {
			
			// the node to be deleted is after the first one
			dNode = temp;
			isFound = true; 
			prev->next = temp->next;

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

void linkedList::delAfter(int data) {
	
	node *prev, *temp;
	node *dNode;
	bool isFound = false;

	if (head == NULL) {
		std::cout << "The list is empty" << std::endl;
		wait(2);
	}

	// there is only one node in the list so there nothing after it to be deleted
	else if (head->data == data && head->next == NULL) {
		std::cout << "There is nothing after " << data << std::endl;
		wait(2);
		return;
	}

	else if(head->data == data && head->next != NULL) {
		dNode = head->next;
		head->next = head->next->next;
		isFound = true;
	}
	else {

		node *trav = head;

		while (trav != NULL) {
			trav = trav->next;
			// if the node is the last node then there is nothing after it to be deleted
			if (trav->next == NULL) {
				std::cout << "There is nothing after " << data << std::endl;
				wait(2);
				return;
			}

			else if (trav->data == data) {
				dNode = trav->next;
				trav->next = trav->next->next;
				isFound = true;
				break;
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

void linkedList::delBefore(int num) {
	
	if (head == NULL) {
		cout << "List is empty! " << endl;
		wait(2);
	}

	else if  (head->next == NULL && head->data == num) {
		cout << "No nodes exist before the node that contains " << num << endl;
		wait(2); 
	}

	else if  (head->next == NULL && head->data != num) {
		cout << "No node that contains " << num << " exists"<< endl;
		wait(2);
	}

	else if (head->next->data == num) {
		head = head->next;
		return;
	}
	else {
		node *temp1, *temp2, *temp3;

		for (temp1 = head, temp2 = temp1->next, temp3 = temp2->next; temp3 != NULL; temp1 = temp1->next, temp2 = temp1->next, temp3 = temp2->next) {		
			if (temp3->data == num) {
				temp1->next = temp3;
				return;
			}
		}
	}
	
	cout << "Couldn't delete the node before the node that contains " << num << " or there is nothing before it" << endl;
	wait(2);
}

bool linkedList::search(int num) {
	int counter = 0;

	if (head == NULL) {
		cout << "List is empty!" << endl;
		wait(2);
	}

	else if (head->data == num) {
		counter++;
		cout << "Found the the node that contains " << num << " At node " << counter << endl;
		wait(3);
		return true;
	}

	else {
		node *temp1 = head;

		while (temp1 != NULL) {
			// cout << temp1->data << endl;
			counter++;
			if (temp1->data == num) {
				cout << "Found the node that contains " << num << " At node " << counter << endl;
				wait(3);
				return true;
			}

			temp1 = temp1->next;
		}
		cout << "No node that contains " << num << " was found!" << endl;
		wait(3);
		return false;
	}
}

linkedList::~linkedList() {
	node *temp1 = head;

	while (temp1 != NULL) {
		node *temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}
	head = NULL;
}
#include <iostream>

using namespace std;

//The Node structure
struct Node {
	Node *next;
	int data;
};

//Function that builds a linked list from the head forward to the tail
Node* BuildListForward() {
	//Variables
	Node *head = NULL;
	Node *tail = NULL;
	int num;

	//Asks user to enter some numbers and end the input with -999
	cout << "Enter some numbers and end with -999: ";
	cin >> num;
	cout << endl;

	//Creates a new node, inserts the data into that node, and redoes what is the tail until -999 is num
	while (num != -999) {
		//Creates a new node
		Node *newNode = new Node;
		newNode->data = num;
		newNode->next = NULL;
		//If there is no node in the linked list, it makes the head and tail be the new node
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		//Looks for the next number
		cin >> num;
	}
	
	return head;
}//End BuildListForward

//A function that deletes a node
Node* DeleteNode(Node* h, int d) {
	//Creates a new node and initializes it to equal the head
	Node* n = h;

	//If the data in the head node equals the data to be deleted, this deletes the node
	if (n->data == d) {
		return n->next;
	}

	//While node n is not the tail node, search for the node with the data to be deleted
	while (n->next != NULL) {
		//If a node has a next node that contains the data to be deleted, make the next node be the one after that node
		if (n->next->data == d) {
			n->next = n->next->next;
		}
		//Iterates to the next node
		n = n->next;
	}
	return h;
}//End DeleteNode

//Main function
int main() {
	//Creates two nodes; one initialized with BuildListForward and the other with DeleteNode with parameters for it
	Node* current = BuildListForward(); 
	Node* cur = DeleteNode(current, 14);
	//Prints the linked list
	while (current != NULL) {
		cout << current->data << "->";
		current = current->next;
	}
	cout << endl;
	
	cin.ignore();
	cin.get();
	return 0;
}

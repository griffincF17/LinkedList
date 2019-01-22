#include <iostream>

using namespace std;

struct Node {
	Node *next;
	int data;
};

Node* buildListForward() {
	Node *head = NULL;
	Node *tail = NULL;
	int num;

	cout << "Enter some numbers and end with -999: ";
	cin >> num;
	cout << endl;

	while (num != -999) {
		Node *newNode = new Node;
		newNode->data = num;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		
		cin >> num;
	}
	
	return head;
}

Node* DeleteNode(Node* h, int d) {
	Node* n = h;

	if (n->data == d) {
		return h->next;
	}

	while (n->next != NULL) {
		if (n->next->data == d) {
			n->next = n->next->next;
			return h;
		}
		n = n->next;
	}
	return h;
}
int main() {
	Node* current = buildListForward(); 
	Node* cur = DeleteNode(current, 14);
	while (current != NULL) {
		cout << current->data << "->";
		current = current->next;
	}
	cout << endl;
	
	cin.ignore();
	cin.get();
	return 0;
}
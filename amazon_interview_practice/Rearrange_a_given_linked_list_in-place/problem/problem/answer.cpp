#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Linkedlist Node structure 
struct Node {
	int data;
	struct Node* next;
};

// Function to create newNode in a linkedlist 
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// Function to print the linked list 
void printlist(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		if (head->next)
			cout << "-> ";
		head = head->next;
	}
	cout << endl;
}

// Function to rearrange a linked list 
void rearrange(Node** head)
{
	Node * node = *head;
	Node * middle = *head;;
	queue<Node *> odd;
	stack<Node *> even;

	for (node = middle = *head; middle != NULL; middle = middle->next->next) {
		odd.push(node);

		if ((middle->next != NULL) && (middle->next->next != NULL)) {
			node = node->next;
		} else {
			break;
		}
	}

	for (node = node->next; node != NULL; node = node->next) {
		even.push(node);
	}

	*head = node = odd.front();
	odd.pop();
	for (int i = 0; (!odd.empty()) || (!even.empty()); ++i) {
		if ((i % 2) == 0) {
			node->next = even.top();
			even.pop();
		} else {
			node->next = odd.front();
			odd.pop();
		}
		node = node->next;
	}
	node->next = NULL;
}

int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
//	head->next->next->next->next = newNode(5);

	printlist(head); // Print original list 
	rearrange(&head); // Modify the list 
	printlist(head); // Print modified list 
	return 0;
}
#include <iostream>

using namespace std;
/*
// Find next node using next pointer
struct Node *temp = node_ptr->next;

// Copy data of next node to this node
node_ptr->data = temp->data;

// Unlink next node
node_ptr->next = temp->next;

// Delete next node
free(temp);
*/

class Node {
	public :
		Node(int val) : m_iValue(val), m_pNext(NULL) {}
		int m_iValue;
		Node * m_pNext;
};

void push(Node ** head, int val)
{
	Node *node = *head;

	if (*head == NULL) {
		*head = new Node(val);
	} else {
		for (node = *head; node->m_pNext != NULL; node = node->m_pNext);
		node->m_pNext = new Node(val);
	}
}

void printList(Node *head)
{
	for (Node * node = head; node != NULL; node = node->m_pNext) {
		cout << node->m_iValue << " ";
	}
	cout << endl;
}

void deleteNode(Node  *head)
{
	Node * node, *prev;

	for (prev = head, node = head->m_pNext; node->m_pNext != NULL;) {
		prev->m_iValue = node->m_iValue;
		prev = node;
		node = node->m_pNext;
	}
	prev->m_iValue = node->m_iValue;
	prev->m_pNext = NULL;
	delete node;
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Use push() to construct below list
	1->12->1->4->1 */
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);

	cout << "Before deleting \n";
	printList(head);

	/* I m deleting the head itself.
	You can check for more cases */
	deleteNode(head);

	cout << "\nAfter deleting \n";
	printList(head);
	return 0;
}
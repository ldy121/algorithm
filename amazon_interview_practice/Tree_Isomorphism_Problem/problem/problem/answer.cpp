#include <iostream>
#include <queue>

using namespace std;

struct node {
	int m_ival;
	node * left;
	node * right;
};

bool isIsomorphic(struct node *n1, struct node *n2)
{
	if ((n1 == NULL) && (n2 == NULL)) {
		return true;
	} else if ((n1 == NULL) || (n2 == NULL) || (n1->m_ival != n2->m_ival)) {
		return false;
	} else {
		return ((isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
			((isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left))));
	}
}

struct node * newNode(int val)
{
	struct node * new_node = new node;
	new_node->m_ival = val;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

/* Driver program to test above functions*/
int main()
{
	// Let us create trees shown in above diagram 
	struct node *n1 = newNode(1);
	n1->left = newNode(2);
	n1->right = newNode(3);
	n1->left->left = newNode(4);
	n1->left->right = newNode(5);
	n1->right->left = newNode(6);
	n1->left->right->left = newNode(7);
	n1->left->right->right = newNode(8);

	struct node *n2 = newNode(1);
	n2->left = newNode(3);
	n2->right = newNode(2);
	n2->right->left = newNode(4);
	n2->right->right = newNode(5);
	n2->left->right = newNode(6);
	n2->right->right->left = newNode(8);
	n2->right->right->right = newNode(7);

	if (isIsomorphic(n1, n2) == true)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
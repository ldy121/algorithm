#include <iostream>
#include <queue>

using namespace std;

class node {
public :
	node(int val) : data(val), left(NULL), right(NULL), nextRight(NULL) {};
	int data;
	node * left;
	node * right;
	node * nextRight;
};

void connect(node * root)
{
	queue<node *> q;

	for (q.push(root); !q.empty();) {
		node * prev = q.front();
		q.pop();
		for (int size = q.size(); size > 0; --size) {
			node * node = q.front();
			q.pop();
			prev->nextRight = node;
			if (prev->left != NULL)		q.push(prev->left);
			if (prev->right != NULL)	q.push(prev->right);
			prev = node;
		}
		if (prev->left != NULL)		q.push(prev->left);
		if (prev->right != NULL)	q.push(prev->right);
	}
	
}

/* Driver code*/
int main()
{

	/* Constructed binary tree is
	10
	/ \
	8 2
	/
	3
	*/
	node *root = new node(10);
	root->left = new node(8);
	root->right = new node(2);
	root->left->left = new node(3);

	// Populates nextRight pointer in all nodes  
	connect(root);

	// Let us check the values 
	// of nextRight pointers  
	cout << "Following are populated nextRight pointers in the tree"
		" (-1 is printed if there is no nextRight)\n";
	cout << "nextRight of " << root->data << " is "
		<< (root->nextRight ? root->nextRight->data : -1) << endl;
	cout << "nextRight of " << root->left->data << " is "
		<< (root->left->nextRight ? root->left->nextRight->data : -1) << endl;
	cout << "nextRight of " << root->right->data << " is "
		<< (root->right->nextRight ? root->right->nextRight->data : -1) << endl;
	cout << "nextRight of " << root->left->left->data << " is "
		<< (root->left->left->nextRight ? root->left->left->nextRight->data : -1) << endl;
	return 0;
}
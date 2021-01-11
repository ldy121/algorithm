#include <iostream>
#include <queue>

using namespace std;

class node {
	public :
		node(int val) : m_val(val), left(NULL), right(NULL) {};
		node * left;
		node * right;
		int m_val;
};

void printKDistant(node * root, int distance)
{
	queue<node *>q[2];
	int push_queue, pop_queue;
	int level;

	q[0].push(root);
	for (level = push_queue = pop_queue = 0; (level < distance) && (q[pop_queue].size() > 0); pop_queue = push_queue, ++level) {
		push_queue = !push_queue;

		while (q[pop_queue].size() > 0) {
			node* nd = q[pop_queue].front();
			q[pop_queue].pop();

			if (nd->left != NULL) q[push_queue].push(nd->left);
			if (nd->right != NULL) q[push_queue].push(nd->right);
		}
	}

	while (q[pop_queue].size() > 0) {
		node* nd = q[pop_queue].front();
		q[pop_queue].pop();

		cout << nd->m_val << " ";
	}
	cout << endl;
}

/* Driver code*/
int main()
{

	/* Constructed binary tree is
	1
	/ \
	2     3
	/ \     /
	4 5 8
	*/
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(8);

	printKDistant(root, 2);
	return 0;
}

// This code is contributed by rathbhupendra 
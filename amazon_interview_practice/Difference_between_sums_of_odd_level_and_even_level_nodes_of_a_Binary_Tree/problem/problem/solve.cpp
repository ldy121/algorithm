#include <iostream>
#include <queue>

using namespace std;

class Node {
	public :
		Node(int val) : m_iVal(val), left(NULL), right(NULL) {};
		int m_iVal;
		Node * left;
		Node * right;
};

int evenOddLevelDifference(Node * root)
{
	queue<Node *> q[2];
	int push_queue, pop_queue;
	int odd_sum = 0, even_sum = 0;
	int level = 1;

	q[0].push(root);
	for (push_queue = pop_queue = 0, level = 1; q[pop_queue].size() > 0; pop_queue = push_queue, ++level) {
		push_queue = !push_queue;
		while (!q[pop_queue].empty()) {
			Node * node = q[pop_queue].front();
			q[pop_queue].pop();

			if ((level % 2) == 0)	even_sum += node->m_iVal;
			else					odd_sum += node->m_iVal;

			if (node->left != NULL)	q[push_queue].push(node->left);
			if (node->right != NULL) q[push_queue].push(node->right);
		}
	}

	return (odd_sum - even_sum);
}

Node * newNode(int val)
{
	return new Node(val);
}

int main(void)
{
	// construct a tree 
	Node* root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->left->right->left = newNode(3);
	root->right->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left = newNode(7);

	int result = evenOddLevelDifference(root);
	cout << "diffence between sums is :: ";
	cout << result << endl;
	return 0;
}
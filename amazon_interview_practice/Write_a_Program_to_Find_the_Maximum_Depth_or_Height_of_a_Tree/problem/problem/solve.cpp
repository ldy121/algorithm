// Driver code     
#include <iostream>
#include <queue>

using namespace std;

class node {
	public :
		node(int val) :m_val(val), left(NULL), right(NULL) {};
		int m_val;
		node *left;
		node *right;
};

int maxDepth(node * root)
{
	queue<node*> q[2];
	int push_queue = 0, pop_queue;
	int answer = 0;

	q[0].push(root);
	for (pop_queue = 0; q[pop_queue].size() > 0; pop_queue = push_queue) {
		++answer;
		push_queue = !push_queue;
		while (q[pop_queue].size() > 0) {
			node * nd = q[pop_queue].front();
			q[pop_queue].pop();

			if (nd->left != NULL) q[push_queue].push(nd->left);
			if (nd->right != NULL) q[push_queue].push(nd->right);
		}
	}

	return answer;
}

node * newNode(int val) {
	return new node(val);
}

int main()
{
	node *root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Height of tree is " << maxDepth(root) << endl;
	return 0;
}
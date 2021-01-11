#include <iostream>
#include <queue>

using namespace std;

class Node {
public :
	Node(int val) : m_iVal(val) {};
	int m_iVal;
	Node* left;
	Node* right;
};

void printBottomView(Node*root)
{
	queue<Node *> prev, current;
	int size;
	
	prev.push(root);
	for (current.push(root); !current.empty();) {
		size = prev.size();
		for (int _ = current.size(); _ > 0; --_) {
			Node * node = current.front();
			current.pop();
			prev.push(node);
			if (node->left != NULL) current.push(node->left);
			if (node->right != NULL) current.push(node->right);
		}
		if (!current.empty()) {
			for (;size > 0; --size) {
				prev.pop();
			}
		}
	}

	for (; size > 0; --size) {
		Node * node = prev.front();
		prev.pop();
		if (node->left != NULL) cout << node->left->m_iVal << " ";
		if ((node->left == NULL) && (node->right == NULL)) cout << node->m_iVal << " ";
		if (node->right != NULL) cout << node->right->m_iVal << " ";
	}
	cout << endl;
}

int main()
{
	Node * root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n";
	printBottomView(root);
	return 0;
}
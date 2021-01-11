#include <iostream>

using namespace std;

class Node {
public :
	Node() : left(NULL), right(NULL) {};
	Node(int val) : key(val), left(NULL), right(NULL) {};
	int key;
	Node * left;
	Node * right;
};

Node * createTree(int parent[], int n)
{
	Node * nodes = new Node[n];
	Node * ret = NULL;
	for (int i = 0; i < n; ++i) {
		nodes[i].key = i;
		if (parent[i] >= 0) {
			if (nodes[parent[i]].left == NULL) nodes[parent[i]].left = &nodes[i];
			else nodes[parent[i]].right = &nodes[i];
		} else {
			ret = &nodes[i];
		}
	}

	return ret;
}

//For adding new line in a program 
inline void newLine() {
	cout << "\n";
}

// Utility function to do inorder traversal 
void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

// Driver method 
int main()
{
	int parent[] = { -1, 0, 0, 1, 1, 3, 5 };
	int n = sizeof parent / sizeof parent[0];
	Node *root = createTree(parent, n);
	cout << "Inorder Traversal of constructed tree\n";
	inorder(root);
	newLine();
}
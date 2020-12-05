#include <iostream>

using namespace std;

class node {
	public :
		node(int val) : m_ival(val), left(NULL), right(NULL) {};
		int m_ival;
		node * left;
		node * right;
};

bool check_bst(node *nd, int &min, int &max)
{
	bool ret = true;
	int left_child_min, left_child_max;
	int right_child_min, right_child_max;

	left_child_min = left_child_max = right_child_max = right_child_min = nd->m_ival;

	if (nd->left != NULL) {
		ret = check_bst(nd->left, left_child_min, left_child_max);
	}

	if ((ret == true) && (left_child_max > nd->m_ival)) {
		ret = false;
	}

	if ((ret == true) && (nd->right != NULL)) {
		ret = check_bst(nd->right, right_child_min, right_child_max);
	}

	if ((ret == true) && (right_child_min < nd->m_ival)) {
		ret = false;
	}

	min = left_child_min;
	max = right_child_max;

	return ret;
}

bool isBST(node * nd)
{
	int min, max;
	return check_bst(nd, min, max);
}

/* Driver code*/
int main()
{
	node *root = new node(4);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(3);

	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}

// This code is contributed by rathbhupendra 
#include <iostream>

using namespace std;

class Node {
	public :
		Node(int val) : m_iVal(val), m_pLeft(NULL), m_pRight(NULL)
		{};
		int m_iVal;
		Node * m_pLeft;
		Node * m_pRight;
};

int modify_node(Node *node, int add)
{
	if (node->m_pRight != NULL) {
		node->m_iVal += modify_node(node->m_pRight, add);
	} else {
		node->m_iVal += add;
	}

	if (node->m_pLeft != NULL) {
		return modify_node(node->m_pLeft, node->m_iVal);
	} else {
		return node->m_iVal;
	}
}

void modifyBST(Node *root)
{
	modify_node(root, 0);
}

void inorder(Node *node)
{
	if (node->m_pLeft != NULL) inorder(node->m_pLeft);
	cout << node->m_iVal << " ";
	if (node->m_pRight != NULL) inorder(node->m_pRight);
}

Node * insert(Node * root, int val)
{
	Node * ret = new Node(val);
	if (root != NULL) {
		Node * node = root;
		while (true) {
			if (node->m_iVal > val) {
				if (node->m_pLeft == NULL) {
					node->m_pLeft = ret;
					break;
				} else {
					node = node->m_pLeft;
				}
			} else {
				if (node->m_pRight == NULL) {
					node->m_pRight = ret;
					break;
				} else {
					node = node->m_pRight;
				}
			}
		}
	}
	return ret;
}

// Driver code 
int main()
{
	/* Let us create following BST
	50
	/ \
	30 70
	/ \ / \
	20 40 60 80 */
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	
	modifyBST(root);

	// print inoder tarversal of the modified BST  
	inorder(root);

	return 0;
}

// This code is contributed by rathbhupendra 
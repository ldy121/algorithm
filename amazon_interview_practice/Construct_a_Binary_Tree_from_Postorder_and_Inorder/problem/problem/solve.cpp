#include <iostream>

using namespace std;

struct Node {
	int m_iValue;
	Node * m_pLeft;
	Node * m_pRight;
};


Node * buildTree(int * in_order, int * post_order, int n)
{
	Node * node = NULL;

	if (n > 0) {
		int pivot;
		int left;
		int right;
		for (pivot = 0; pivot < n; ++pivot) {
			if (in_order[pivot] == post_order[n - 1]) {
				break;
			}
		}
		node = new Node;

		node->m_iValue = post_order[n - 1];
		node->m_pLeft = buildTree(&in_order[0], &post_order[0], pivot);
		node->m_pRight = buildTree(&in_order[pivot + 1], &post_order[pivot], (n - (pivot + 1)));
	}
	return node;
}

void preOrder(Node * node)
{
	cout << node->m_iValue << " ";
	if (node->m_pLeft != NULL)	preOrder(node->m_pLeft);
	if (node->m_pRight != NULL)	preOrder(node->m_pRight);
}


int main()
{
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
	int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
	int n = sizeof(in) / sizeof(in[0]);

	Node* root = buildTree(in, post, n);

	cout << "Preorder of the constructed tree : \n";
	preOrder(root);

	return 0;
}
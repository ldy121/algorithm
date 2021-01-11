/* Driver function to test above functions */
#include <iostream>

using namespace std;

struct node {
	int m_ival;
	struct node * m_pLeft;
	struct node * m_pRight;
};

void printInorder(struct node * node)
{
	if (node->m_pLeft != NULL)	printInorder(node->m_pLeft);
	cout << node->m_ival << " ";
	if (node->m_pRight != NULL)	printInorder(node->m_pRight);
}

struct node * create_node(int pre[], char preLN[], int index, int * next_index, int size)
{
	int next = index + 1;
	struct node * new_node = NULL;
	
	if (index < size) {
		new_node = new node;
	} else {
		return NULL;
	}
	
	new_node->m_ival = pre[index];

	if (preLN[index] == 'N') {
		new_node->m_pLeft = create_node(pre, preLN, index + 1, &next, size);
		new_node->m_pRight = create_node(pre, preLN, next, &next, size);
	} else {
		new_node->m_pLeft = NULL;
		new_node->m_pRight = NULL;
	}
	*next_index = next;
	return new_node;
}

struct node * constructTree(int pre[], char preLN[], int n)
{
	int ret;
	return create_node(pre, preLN, 0, &ret, n);
}

int main()
{
	struct node *root = NULL;

	/* Constructing tree given in the above figure
	10
	/  \
	30   15
	/  \
	20   5 */
	int pre[] = { 10, 30, 20, 5, 15 };
	char preLN[] = { 'N', 'N', 'L', 'L', 'L' };
	int n = sizeof(pre) / sizeof(pre[0]);

	// construct the above tree 
	root = constructTree(pre, preLN, n);

	// Test the constructed tree 
	printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
	printInorder(root);

	return 0;
}
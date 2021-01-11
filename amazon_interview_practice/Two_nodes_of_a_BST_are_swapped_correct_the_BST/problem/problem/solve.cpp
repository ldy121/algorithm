#include <cstdio>
#include <vector>

using namespace std;

// Two nodes in the BST's swapped, correct the BST. 
#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node *left, *right;
};

// A utility function to swap two integers 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

/* A utility function to print Inoder traversal */
void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

void inorder_array(struct node * node, vector<struct node *>&vec)
{
	if (node->left != NULL)	inorder_array(node->left, vec);
	vec.push_back(node);
	if (node->right != NULL) inorder_array(node->right, vec);
}

void correctBST(struct node * root)
{
	vector<struct node*> vec;
	int i, j, k;

	inorder_array(root, vec);
	for (i = 0, j = vec.size() - 1, k = 0; k < vec.size(); ++k) {
		if (vec[i]->data < vec[i + 1]->data) ++i;
		if (vec[j]->data > vec[j - 1]->data) --j;
	}

	swap(&vec[i]->data, &vec[j]->data);
}

/* Driver program to test above functions*/
int main()
{
	/*   6
	/  \
	10    2
	/ \   / \
	1   3 7  12
	10 and 2 are swapped
	*/

	struct node *root = newNode(6);
	root->left = newNode(10);
	root->right = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(12);
	root->right->left = newNode(7);

	printf("Inorder Traversal of the original tree \n");
	printInorder(root);

	correctBST(root);

	printf("\nInorder Traversal of the fixed tree \n");
	printInorder(root);

	return 0;
}

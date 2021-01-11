#include <stdio.h>
#include <map>
#include <iostream>


#pragma warning(disable : 4996)

using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	Node* right;
	Node* left;

	Node(int x) {
		data = x;
		right = NULL;
		left = NULL;
	}
};
/* Returns true if the given tree is a binary search tree
(efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Driver program to test size function*/
int main()
{
	int t;
	struct Node *child;
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &t);
		while (t--)
		{
			map<int, Node*> m;
			int n;
			scanf("%d",&n);
				struct Node *root = NULL;
			while (n--)
			{
				Node *parent;
				char lr;
				int n1, n2;
				scanf("%d %d %c", &n1, &n2, &lr);
				//  cout << n1 << " " << n2 << " " << (char)lr << endl;
				if (m.find(n1) == m.end())
				{
					parent = new Node(n1);
					m[n1] = parent;
					if (root == NULL)
						root = parent;
				}
				else
					parent = m[n1];
				child = new Node(n2);
				if (lr == 'L')
					parent->left = child;
				else
					parent->right = child;
				m[n2] = child;
			}
			cout << isBST(root) << endl;
		}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
and a pointer to right child
struct Node {
int data;
Node* right;
Node* left;

Node(int x){
data = x;
right = NULL;
left = NULL;
}
}; */

const int min_value = -1000000000;
const int max_value = 100000000;

int isBSTUtil(struct Node* node, int min, int max)
{
	if (node != NULL) {
		return (min < (node->data)) && ((node->data) < max) &&
			(isBSTUtil(node->left, min, node->data)) &&
			(isBSTUtil(node->right, node->data, max));
	} else {
		return 1;
	}
}

bool isBST(Node* root) {
	return isBSTUtil(root, min_value, max_value);
}
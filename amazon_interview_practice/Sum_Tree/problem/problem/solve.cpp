#include <iostream>
#include <cstdio>
#include <map>

#pragma warning(disable : 4996)


using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

#define max(a,b) (((a) > (b)) ? (a) : (b))

bool isSumTree(struct Node* node);
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
	if (node == NULL)
		return 0;
	else
		return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
	int t;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &t);
		while (t--)
		{
			map<int, Node*> m;
			int n;
			scanf("%d", &n);
			struct Node *root = NULL;
			struct Node *child;
			while (n--)
			{
				Node *parent;
				char lr;
				int n1, n2;
				scanf("%d %d %c", &n1, &n2, &lr);
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
			cout << isSumTree(root) << endl;
		}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*  Tree node
struct Node
{
int data;
Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false
bool calc(Node * node, int &sum)
{
	int left_sum = 0;
	int right_sum = 0;

	if (node == NULL) {
		sum = 0;
		return true;
	} else if (node->left == NULL && node->right == NULL) {
		sum = node->data;
		return true;
	} else if (calc(node->left, left_sum) && calc(node->right, right_sum)) {
		sum = left_sum + right_sum + node->data;
		return ((node->data) == (left_sum + right_sum));
	} else {
		return false;
	}
}


bool isSumTree(Node* root)
{
	int test;
	return calc(root, test);
}
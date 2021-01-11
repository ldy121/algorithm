#include <cstdio>
#include <iostream>
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
bool hasPathSum(Node *, int);
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
			if (n == 1)
			{
				int a;
				cin >> a;
				cout << a << endl;
			}
			else {
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
				int a;
				cin >> a;
				cout << hasPathSum(root, a) << endl;
			}
		}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
int data;
Node* left, * right;
}; */
/*you are required to
complete this function */
bool hasPathSum(Node *node, int sum)
{
	if (node->left == NULL && node->right == NULL) {
		return ((sum - node->data) == 0);
	}

	return (((node->left != NULL)  && hasPathSum(node->left, sum - node->data)) ||
	 ((node->right != NULL) && hasPathSum(node->right, sum - node->data)));
}
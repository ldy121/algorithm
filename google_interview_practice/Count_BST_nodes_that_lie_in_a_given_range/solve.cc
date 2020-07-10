// solution 1
int getCountOfNode(Node *root, int l, int h)
{
  int left, right;
  if ((l < root->data) && (root->left)){
    left = getCountOfNode(root->left, l, h);
  } else {
    left = 0;
  }
  
  if ((root-> data < h) && (root->right)) {
    right = getCountOfNode(root->right, l, h);
  } else {
    right = 0;
  }
  
  return (l <= root->data && root->data <= h) ? (1 + left + right) : (left + right);
}

// solution 2
#include <queue>
using namespace std;
int getCountOfNode(Node *root, int l, int h) {
	queue<Node *> q;
	int ret = 0;
	for (q.push(root); q.size() > 0;) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			Node *node = q.front();
			q.pop();

			if (l < node->data && node->left) q.push(node->left);
			if (node->data < h && node->right) q.push(node->right);
			if (l <= node->data && node->data <= h) ++ret;
		}
	}
	return ret;
}

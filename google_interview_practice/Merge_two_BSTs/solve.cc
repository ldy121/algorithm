#include <vector>

using namespace std;

// Return a integer of integers having all the nodes in both the BSTs in a sorted order.
void traversal(Node *node, queue<int> &q)
{
  if (node->left) traversal(node->left, q);
  q.push(node->data);
  if (node->right) traversal(node->right, q);
}

vector<int> merge(Node *root1, Node *root2)
{
	queue<int> q1, q2;
  vector<int> vec;

  traversal(root1, q1);
  traversal(root2, q2);

  while (!q1.empty() || !q2.empty()) {
    if (q1.empty()) {
      vec.push_back(q2.front());
      q2.pop();
      continue;
    }
    if (q2.empty()) {
      vec.push_back(q1.front());
      q1.pop();
      continue;
    }
    if (q1.front() < q2.front()) {
      vec.push_back(q1.front());
      q1.pop();
    } else {
      vec.push_back(q2.front());
      q2.pop();
    }
  }
  return vec;
}

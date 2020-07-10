/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/

/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

bool comp(Node *node1, Node *node2) {
  if (node1 == NULL && node2 == NULL) {
    return true;
  } else if (node1 == NULL || node2 == NULL) {
    return false;
  } else {
    return (node1->data == node2->data) &&
			comp(node1->left, node2->left) &&
			comp(node1->right, node2->right);
  }
}

bool dupSub(Node *root)
{
  queue<Node *> q;
  vector<Node *> vec;
  if (root->left) q.push(root->left);
  if (root->right) q.push(root->right);

  while (!q.empty()) {
    Node * node = q.front();
    q.pop();
    if (node->left == NULL && node->right == NULL) {
      continue;
    } else {
      vec.push_back(node);
    }
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }

  for (int i = 0; i < vec.size(); ++i) {
    for (int j = i + 1; j < vec.size(); ++j) {
      if (comp(vec[i], vec[j])) {
        return true;
      }
    }
  }
  return false;
}

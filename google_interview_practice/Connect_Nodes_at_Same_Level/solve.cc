/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *p)
{
  queue<Node *> q;
  for (q.push(p); !q.empty();) {
    for (int size = q.size(); size > 0; --size) {
      Node * node = q.front();
      q.pop();
      if (size > 1) {
        node->nextRight = q.front();
      }
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
  }
}




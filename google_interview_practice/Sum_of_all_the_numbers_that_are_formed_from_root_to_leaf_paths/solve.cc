class Node {
  public :
    Node * m_left;
    Node * m_right;
    int m_data;
}

// solution 1
void traversal(Node *node, int val, int &answer) {
  int data = (val * 10 + node->m_data);
  if (node->m_left == NULL && node->m_right == NULL) {
    answer += data;
    return;
  }

  if (node->m_left) {
    traversal(node->m_left, data, answer);
  }

  if (node->m_right) {
    traversal(node->m_right, data, answer);
  }
}

int getAnswer(Node *root) {
  int answer = 0;

  traversal(root, 0, answer);

  return answer;
}

// solution 2

#include <queue>

using namespace std;

class QueueNode {
  public :
    QueueNode(Node *node, int val) : m_node(node), m_val(val) {};
    Node * m_node;
    int m_val;
};

int getAnswer(Node *root) {
  int answer = 0;
  queue<QueueNode*> q;

  for (q.push(QueueNode(root, 0)); q.size() > 0;) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      QueueNode* qnode = q.front();
      Node * node = qnode->m_node;
      int val = (qnode->m_val) * 10 + node->m_data;
      qnode.pop();
      
      if (node->left == NULL && node->right) {
        answer += val;
        continue;
      }
      if (node->left) q.push(QueueNode(node->left, val));
      if (node->right) q.push(QueueNode(node->right, val));
    }
  }
  return answer;
}

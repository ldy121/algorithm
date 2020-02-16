/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        queue<Node *> q;
        int ret = 0;
        for (q.push(root); q.size() > 0; ++ret) {
            for (int size = q.size(); size > 0; --size) {
                Node * node = q.front();
                q.pop();
                if (node->left != NULL)     q.push(node->left);
                if (node->right != NULL)    q.push(node->right);
            }
        }
        return ret - 1;
    }
  

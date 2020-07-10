void getAnswer(Node *node, int &answer, int &k) {
    if (node->left != NULL) {
        getAnswer(node->left, answer, k);
    }
    if (k > 0) {
        --k;
        if (k == 0) {
            answer = node->data;            
        }
    }
    if (k > 0 && node->right != NULL) {
        getAnswer(node->right, answer, k);
    }
}

// Return the Kth smallest element in the given BST 
int KthSmallestElement(Node *root, int K)
{
    int answer = -1;
    getAnswer(root, answer, K);
    return answer;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private :
    vector<int> m_answer;
public:
    void traversal(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        traversal(node->left);
        traversal(node->right);
        m_answer.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        traversal(root);
        return m_answer;
    }
};

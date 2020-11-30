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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        vector<vector<int> > ret;
        
        if (root == NULL) {
            return ret;
        }
        
        for (q.push(root); q.size() > 0;) {
            vector<int> vec;
            for (int size = q.size(); size > 0; --size) {
                TreeNode * node = q.front();
                q.pop();

                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right)q.push(node->right);
            }
            ret.push_back(vec);
        }

        return ret;
    }
};

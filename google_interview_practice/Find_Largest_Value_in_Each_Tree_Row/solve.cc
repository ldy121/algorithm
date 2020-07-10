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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        for (q.push(root); !q.empty(); ) {
	        int val = (q.front())->val;
	        for (int size = q.size(); size > 0; --size) {
		        TreeNode* node = q.front();
		        q.pop();
		        if (val < node->val) {
			        val = node->val;
		        }
		        if (node->left) q.push(node->left);
		        if (node->right) q.push(node->right);
	        }
	        ret.push_back(val);
        }
        return ret;
    }
};


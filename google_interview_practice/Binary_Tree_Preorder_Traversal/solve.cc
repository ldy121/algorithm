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
    vector<int> preorderTraversal(TreeNode* root) {
	    vector<int> ret;
	    stack<TreeNode*> sp;
    	if (root == NULL) {
            return ret;
    	}
	    for (sp.push(root); !sp.empty();) {
    		TreeNode* node = sp.top();
    		sp.pop();
    		ret.push_back(node->val);
    		if (node->right) {
    			sp.push(node->right);
    		}
    		if (node->left) {
    			sp.push(node->left);
    		}
    	}
    	return ret;
    }
};





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int tree_modify(TreeNode *node, int val) {
		if (node->right != NULL)    val = tree_modify(node->right, val);
		val = node->val = val + node->val;
		if (node->left != NULL)     val = tree_modify(node->left, val);
		return val;
	}
    
	TreeNode* bstToGst(TreeNode* root) {
		tree_modify(root, 0);
		return root;
	}
};

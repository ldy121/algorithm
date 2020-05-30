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
private :
	bool comp_tree(TreeNode* src, TreeNode *dst) {
		if ((src == NULL) && (dst == NULL)) {
			return true;
		} else if (((src == NULL) && (dst != NULL)) ||
			((src != NULL) && (dst == NULL)) ||
			(src->val != dst->val)) {
			return false;
		} else if ((comp_tree(src->left, dst->left) &&
			comp_tree(src->right, dst->right)) || 
			(comp_tree(src->right, dst->left) &&
			 comp_tree(src->left, dst->right))) {
			return true;
		} else {
			return false;
		}
	}

public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		return comp_tree(root1, root2);
	}
};

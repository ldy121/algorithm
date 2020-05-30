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
	TreeNode* insertTree(TreeNode* node, int val) {
		if (node == NULL) {
			return new TreeNode(val);
		}

		if (val > node->val) {
			TreeNode * nd = new TreeNode(val);
			nd->left = node;
			return nd;
		} else {
			node->right = insertTree(node->right, val);            
		}
		return node;
	}

public:
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		return insertTree(root, val);
	}
};

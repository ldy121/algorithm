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
	TreeNode* insert(TreeNode* node, int val) {
		if (node == NULL) {
			TreeNode* newNode = new TreeNode(val);
			return newNode;
		}
        
		if (node->val < val) {
			node->right = insert(node->right, val);
		} else {
			node->left = insert(node->left, val);
		}
		return node;
	}
    
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		return insert(root, val);
	}
};

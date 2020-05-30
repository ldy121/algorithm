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
	TreeNode *find_node(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		TreeNode * ret;

		if (original == target) {
			return cloned;
		} else {
			ret = NULL;
		}

		if (original->left != NULL) {
			ret = find_node(original->left, cloned->left, target);
		}

		if ((ret == NULL) && (original->right != NULL)) {
			ret = find_node(original->right, cloned->right, target);
		}

		return ret;
	}

public:
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		return find_node(original, cloned, target);
	}
};

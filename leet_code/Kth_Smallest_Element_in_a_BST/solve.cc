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
	const int invalid = -1;
	int m_k;

	int traversal(TreeNode* node) {
		if (node->left) {
			int ret = traversal(node->left);
			if (ret != invalid) {
				return ret;
			}
		}

		if (--m_k == 0) {
			return node->val;
		}

		return (node->right) ? traversal(node->right) : invalid;
	}

public:
	int kthSmallest(TreeNode* root, int k) {
		m_k = k;
		return traversal(root);
	}
};

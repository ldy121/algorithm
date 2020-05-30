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
	vector<TreeNode*> m_vec;

	void traversal(TreeNode* node) {
		if (node->left != NULL)     traversal(node->left);
		m_vec.push_back(node);
		if (node->right != NULL)    traversal(node->right);
	}

	TreeNode* generate_tree(int left, int right) {
		TreeNode* ret = NULL;

		if (left <= right) {
			int mid = (left + right) / 2;
			ret = m_vec[mid];
			ret->left  = generate_tree(left, mid - 1);
			ret->right = generate_tree(mid + 1, right);
		}

		return ret;
	}

public:
	TreeNode* balanceBST(TreeNode* root) {
		traversal(root);
		root = generate_tree(0, m_vec.size() - 1);
		return root;
	}
};

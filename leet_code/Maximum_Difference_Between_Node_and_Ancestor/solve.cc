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
	int m_answer;

	void get_answer(TreeNode *node, int &p_max, int &p_min) {
		int child_min, child_max;
		int min = node->val, max = node->val;

		if (node->left != NULL) {
			get_answer(node->left, child_max, child_min);
			if (child_min < min) min = child_min;
			if (child_max > max) max = child_max;
		}

		if (node->right != NULL) {
			get_answer(node->right, child_max, child_min);
			if (child_min < min) min = child_min;
			if (child_max > max) max = child_max;
		}

		if (max - node->val > m_answer) m_answer = max - node->val;
		if (node->val - min > m_answer) m_answer = node->val - min;

		p_max = max;
		p_min = min;
	}

public:
	int maxAncestorDiff(TreeNode* root) {
		int min, max;
		get_answer(root, min, max);
		return m_answer;
	}
};

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
	int m_idx;
	TreeNode *makeTree(vector<int>& preorder, int min, int max) {
		TreeNode * ret = new TreeNode(preorder[m_idx++]);

		if ((m_idx < preorder.size()) &&
		    (preorder[m_idx] < ret->val) &&
		    (preorder[m_idx] > min)) {
			ret->left = makeTree(preorder, min, ret->val);
		}

		if ((m_idx < preorder.size()) &&
		    (preorder[m_idx] > ret->val) &&
		    (preorder[m_idx] < max)) {
			ret->right = makeTree(preorder, ret->val, max);
		}

		return ret;
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		m_idx = 0;
		return makeTree(preorder, -1, 1000);
	}
};

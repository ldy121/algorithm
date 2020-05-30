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
	unordered_map<int, int> m_hash;
	int m_idx;

	TreeNode* generate_tree(vector<int>&pre) {
		TreeNode* node = new TreeNode(pre[m_idx++]);
		int idx = m_hash[node->val];

		if (m_idx < pre.size() && m_hash[pre[m_idx]] < idx) {
			node->left = generate_tree(pre);
		}

		if ((node->left != NULL) && (m_idx < pre.size()) && (m_hash[pre[m_idx]] < idx)) {
			node->right = generate_tree(pre);
		}

		return node;
	}

public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		for (int i = 0; i < post.size(); ++i) {
			m_hash[post[i]] = i;
		}

		m_idx = 0;
		return generate_tree(pre);
	}
};

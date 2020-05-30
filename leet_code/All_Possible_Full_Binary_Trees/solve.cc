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
	TreeNode* m_root;
	vector<TreeNode*> m_answer;

	TreeNode* fork_tree(TreeNode* node) {
		TreeNode * ret = new TreeNode(0);
		if (node->left != NULL)  ret->left = fork_tree(node->left);
		if (node->right != NULL) ret->right = fork_tree(node->right);
		return ret;
	}

	void get_answer(vector<TreeNode*>& parents, int n) {
		int max = 1 << (parents.size());

		if (n == 0) {
			m_answer.push_back(fork_tree(m_root));
			return;
		}

		for (int i = 1; i < max; ++i) {
			int k = 0;
			for (int j = 0; j < parents.size(); ++j) {
				if ((i & (1 << j)) > 0) {
					k += 2;
				}
			}

			if (k <= n) {
				vector<TreeNode*> vec;
				for (int j = 0; j < parents.size(); ++j) {
					if ((i & (1 << j)) > 0) {
						TreeNode * left     = new TreeNode(0);
						TreeNode * right    = new TreeNode(0);
						parents[j]->left    = left;
						parents[j]->right   = right;
						vec.push_back(left);
						vec.push_back(right);
					}
				}

				get_answer(vec, n - k);
				for (int j = 0; j < parents.size(); ++j) {
					if ((i & (1 << j)) > 0) {
						delete parents[j]->left;
						delete parents[j]->right;
						parents[j]->left    = NULL;
						parents[j]->right   = NULL;
					}
				}
			}
		}
	}

public:
	vector<TreeNode*> allPossibleFBT(int N) {
		vector<TreeNode*> vec;
		TreeNode root(0);

		vec.push_back(&root);

		if (N > 0) {
			m_root = &root;
			get_answer(vec, N - 1);
		} else {
			m_answer.push_back(fork_tree(&root));
		}
		return m_answer;
	}
};

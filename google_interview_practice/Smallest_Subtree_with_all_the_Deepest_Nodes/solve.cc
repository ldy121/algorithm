class Solution {
private :
	TreeNode *m_answer;
	int m_maxDepth;

	int getAnswer(TreeNode *node, int depth) {
		int leftDepth = -1, rightDepth = -1;
		int ret;
		if (m_maxDepth < depth) {
			m_answer = node;
            m_maxDepth = depth;
		}

		if (node->left) {
			leftDepth = getAnswer(node->left, depth + 1);
		}

		if (node->right) {
			rightDepth = getAnswer(node->right, depth + 1);
		}

		if (leftDepth == rightDepth) {
			if (leftDepth >= m_maxDepth) {
				m_answer = node;
				m_maxDepth = leftDepth;
			}
		}

		ret = (leftDepth > rightDepth) ? leftDepth : rightDepth;
		return (ret > depth) ? ret : depth;
	}

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
			m_maxDepth = 0;
			getAnswer(root, 1);
			return m_answer;
    }
};



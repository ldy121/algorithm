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
	unordered_map<TreeNode*, int> m_visit;
	TreeNode * m_answer;
	int m_leave;

	bool find_child_node(TreeNode *node, TreeNode *leave) {
		bool ret = false;
		if (node == leave) {
			ret = true;
		} else {
			if (node->left != NULL) {
				ret = find_child_node(node->left, leave);
			}
			if ((ret == false) && (node->right != NULL)) {
				ret = find_child_node(node->right, leave);
			}
		}

		if (ret) {
			if (m_visit.find(node) == m_visit.end()) {
				m_visit[node] = 0;
			}

			if ((++m_visit[node] == m_leave)  && (m_answer == NULL)) {
				m_answer = node;
			}
		}

		return ret;
	}

public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		queue<TreeNode*> q;
		vector<TreeNode *> leave;

		m_answer = NULL;

		for (q.push(root); q.size() > 0;) {
			leave.clear();
			for (int size = q.size(); size > 0; --size) {
				TreeNode *node = q.front();

				q.pop();

				leave.push_back(node);

				if (node->left != NULL)     q.push(node->left);
				if (node->right != NULL)    q.push(node->right);
			}
		}

		m_leave = leave.size();

		for (int i = 0; i < leave.size(); ++i) {
			TreeNode* node = leave[i];
			find_child_node(root, node);
		}
		return m_answer;
	}
};

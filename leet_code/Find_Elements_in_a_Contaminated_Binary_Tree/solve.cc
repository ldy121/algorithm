/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private :

	vector<int> m_node;

	void init_node(TreeNode * node, int val) {
		m_node.push_back(val);

		if (node->left != NULL)  init_node(node->left,   val * 2 + 1);
		if (node->right != NULL) init_node(node->right,  val * 2 + 2);
	}

public:
	FindElements(TreeNode* root) {
		init_node(root, 0);
		sort(m_node.begin(), m_node.end());
	}

	bool find(int target) {
		for (int low = 0, high = m_node.size(), mid = m_node.size() / 2;
			low <= high; mid = (low + high) / 2) {
			if (m_node[mid] == target) {
				return true;
			} else if (m_node[mid] < target) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return false;
	}
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

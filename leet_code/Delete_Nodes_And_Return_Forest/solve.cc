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
	list<TreeNode*> m_list;

	bool remove(TreeNode *node, int val) {
		bool ret = false;

		if (node->val == val) {
			if (node->left != NULL)     m_list.push_back(node->left);
			if (node->right != NULL)    m_list.push_back(node->right);
			ret = true;
		}

		if (ret == false && node->left != NULL) {
			ret = remove(node->left, val);
			if (node->left->val == val) {
				node->left = NULL;                
			}
		}

		if (ret == false && node->right != NULL) {
			ret = remove(node->right, val);
			if (node->right->val == val) {
				node->right = NULL;
			}
		}

		return ret;
	}

public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		vector<TreeNode*> ret;

		m_list.push_back(root);

		for (int i = 0; i < to_delete.size(); ++i) {
			for (list<TreeNode*>::iterator iter = m_list.begin(); iter != m_list.end(); ++iter) {
				if ((*iter)->val == to_delete[i]) {
					if ((*iter)->left != NULL) m_list.push_back((*iter)->left);
					if ((*iter)->right != NULL) m_list.push_back((*iter)->right);
					m_list.erase(iter);
					break;
				} else if (remove(*iter, to_delete[i])) {
					break;
				}
			}
		}

		for (list<TreeNode*>::iterator iter = m_list.begin(); iter != m_list.end(); ++iter) {
			ret.push_back(*iter);
		}
		return ret;
	}
};

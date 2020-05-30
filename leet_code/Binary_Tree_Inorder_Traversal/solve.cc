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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> sp;
		vector<int> ret;

		for (TreeNode * node = root; (node != NULL) || (!sp.empty());) {
			if (node == NULL) {
				node = sp.top();
				sp.pop();
			} else if (node->left != NULL) {
				sp.push(node);
				node = node->left;
				continue;
			}

			ret.push_back(node->val);
			if (node->right != NULL) {
				node = node->right;
			} else {
				node = NULL;
			}
		}
		return ret;
	}
};

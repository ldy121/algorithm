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
		int deepestLeavesSum(TreeNode* root) {
			queue<TreeNode*> q;
			int ret;
			
			for (q.push(root); q.size() > 0;) {
				ret = 0;

				for (int i = q.size(); i > 0; --i) {
					TreeNode* node = q.front();

					q.pop();

					ret += node->val;

					if (node->left != NULL)     q.push(node->left);
					if (node->right != NULL)    q.push(node->right);
				}
			}
			return ret;
		}
};

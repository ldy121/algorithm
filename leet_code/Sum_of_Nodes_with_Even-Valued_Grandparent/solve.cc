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
		int get_answer(int pp, int p, TreeNode* node) {
			int val = 0;
			if ((pp % 2) == 0) {
				val += node->val;
			}
					            
			if (node->left != NULL) val += get_answer(p, node->val, node->left);
			if (node->right != NULL)val += get_answer(p, node->val, node->right);

			return val;
		}

		int sumEvenGrandparent(TreeNode* root) {
			return get_answer(1, 1, root);
		}
};

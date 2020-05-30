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

	int maxLevelSum(TreeNode* root) {
		queue<TreeNode*> q;
		int answer = 0;
		int max = 0;

		q.push(root);

		for (int level = 1; !q.empty(); ++level) {
			int sum = 0;
			for (int size = q.size(); size > 0; --size) {
				TreeNode * node = q.front();

				q.pop();

				sum += node->val;
				if (node->left != NULL)     q.push(node->left);
				if (node->right != NULL)    q.push(node->right);
			}

			if (max < sum) {
				max = sum;
				answer = level;
			}
		}

		return answer;
	}
};

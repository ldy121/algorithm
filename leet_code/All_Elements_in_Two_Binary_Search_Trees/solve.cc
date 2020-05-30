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
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		priority_queue<int, vector<int>, greater<int> > min_heap;
		queue<TreeNode *> q;
		vector<int> ret;

		if (root1 != NULL) q.push(root1);
		if (root2 != NULL) q.push(root2);

		while (!q.empty()) {
			for (int size = q.size(); size > 0; --size) {
				TreeNode* node = q.front();
				q.pop();

				min_heap.push(node->val);
				if (node->left != NULL)     q.push(node->left);
				if (node->right != NULL)    q.push(node->right);
			}
		}

		while (!min_heap.empty()) {
			ret.push_back(min_heap.top());
			min_heap.pop();
		}

		return ret;
	}
};

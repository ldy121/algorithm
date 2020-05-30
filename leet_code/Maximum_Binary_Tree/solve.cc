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
	TreeNode* construct_tree_node(vector<int>& nums, int left, int right) {
		TreeNode* ret = NULL;
		if (left <= right) {
			int max_idx = left, max_val = nums[left];
			for (int i = left + 1; i <= right; ++i) {
				if (max_val < nums[i]) {
					max_idx = i;
					max_val = nums[i];
				}
			}
			ret = new TreeNode(max_val);
			ret->left   = construct_tree_node(nums, left, max_idx - 1);
			ret->right  = construct_tree_node(nums, max_idx + 1, right);
		}
		return ret;
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return construct_tree_node(nums, 0, nums.size() - 1);
	}
};

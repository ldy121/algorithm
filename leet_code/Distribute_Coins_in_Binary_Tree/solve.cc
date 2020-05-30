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
	int m_answer;

	int move_coin(TreeNode *node) {
		int move_left_coin = 0;
		int move_right_coin = 0;

		if (node->left != NULL)     move_left_coin = move_coin(node->left);
		if (node->right != NULL)    move_right_coin = move_coin(node->right);

		if (move_left_coin < 0) {
			m_answer -= move_left_coin;
		} else {
			m_answer += move_left_coin;
		}

		if (move_right_coin < 0) {
			m_answer -= move_right_coin;
		} else {
			m_answer += move_right_coin;
		}

		return (node->val + move_left_coin + move_right_coin - 1);
	}

public:
	int distributeCoins(TreeNode* root) {
		m_answer = 0;
		move_coin(root);
		return m_answer;

	}
};

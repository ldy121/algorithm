/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private :
	int m_answer;
	void getAnswer(TreeNode* node, vector<int> &key, unordered_map<int, int> &histogram) {
		if (histogram.find(node->val) == histogram.end()) {
			key.push_back(node->val);
			histogram[node->val] = 0;
        }
        ++histogram[node->val];

		if (node->left == NULL && node->right == NULL) {
			bool one = false;
			int i = 0;
			for (i = 0; i < key.size(); ++i) {
				if (histogram[key[i]] % 2 == 0)	{
					continue;
				}
				if (one == false) {
					one = true;
					continue;
				}
				break;
			}
			if (i == key.size()) {
				++m_answer;
			}
		}
		if (node->left) {
			getAnswer(node->left, key, histogram);
		}
		if (node->right) {
			getAnswer(node->right, key, histogram);
        }
        --histogram[node->val];
	}
public:
    int pseudoPalindromicPaths (TreeNode* root) {
	    vector<int> key;
	    unordered_map<int, int> histogram;
    	m_answer = 0;
		getAnswer(root, key, histogram);
		return m_answer;
    }
};

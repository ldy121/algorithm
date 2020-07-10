class Solution {
private :
	unordered_map<int, int> m_histogram;
	vector<int> m_key;

	int traversal(TreeNode *node) {
		int leftSum = 0, rightSum = 0, sum = 0;
		if(node->left) leftSum = traversal(node->left);
		if(node->right) rightSum = traversal(node->right);

		sum = leftSum + rightSum + node->val;

		if (m_histogram.find(sum) == m_histogram.end()) {
			m_histogram[sum] = 0;
			m_key.push_back(sum);
		}
		++m_histogram[sum];

		return sum;
	}

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
	    vector<int> ret;
	    int maxFrequency = 0;
        
        if (root == NULL) {
            return ret;
        } else {
            traversal(root);
        }

        for (int i = 0; i < m_key.size(); ++i) {
	        if (m_histogram[m_key[i]] > maxFrequency) {
		        maxFrequency = m_histogram[m_key[i]];
	        }
        }

        for (int i = 0; i < m_key.size(); ++i) {
	        if (m_histogram[m_key[i]] == maxFrequency) {
		        ret.push_back(m_key[i]);
	        }
        }
        return ret;
    }
};


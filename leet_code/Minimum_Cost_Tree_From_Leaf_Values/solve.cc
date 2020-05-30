class Solution {
private :
	const int max_tree_value = 99999999;
	vector<vector<int> > m_maxNode;
	vector<vector<int> > m_minSum;

	void get_answer(int left, int right) {
		if ((left < right) && (m_minSum[left][right] == max_tree_value)) {
			int maxNode = 0;
			int minSum = max_tree_value;

			for (int i = left + 1; i <= right; ++i) {
				get_answer(left, i - 1);
				get_answer(i, right);

				int val = (m_maxNode[left][i - 1] * m_maxNode[i][right])
					+ m_minSum[left][i - 1] + m_minSum[i][right];

				if (maxNode < m_maxNode[left][i - 1]) maxNode = m_maxNode[left][i - 1];
				if (maxNode < m_maxNode[i][right])    maxNode = m_maxNode[i][right];
				if (val < minSum)                     minSum = val;
			}

			m_minSum[left][right] = minSum;
			m_maxNode[left][right] = maxNode;
		}
	}

public:

	int mctFromLeafValues(vector<int>& arr) {
		for (int i = 0; i < arr.size(); ++i) {
			vector<int> maxNode(arr.size(), 0);
			vector<int> minSum(arr.size(), max_tree_value);

			maxNode[i] = arr[i];
			minSum[i] = 0;

			m_maxNode.push_back(maxNode);
			m_minSum.push_back(minSum);
		}

		get_answer(0, arr.size() - 1);

		return m_minSum[0][arr.size() - 1];
	}
};

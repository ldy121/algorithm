class Solution {
private :
	vector<vector<int> > m_answer;
	const int c_init = 100000000;
public:
	int getAnswer(string &s1, string &s2, int idx1, int idx2) {
		if (idx1 >= s1.length()) {
			int sum = 0;
			for (int i = idx2; i < s2.length(); ++i) {
				sum += s2[i];
			}
			return sum;
		}

		if (idx2 >= s2.length()) {
			int sum = 0;
			for (int i = idx1; i < s1.length(); ++i) {
				sum += s1[i];
			}
			return sum;
		}

		if (m_answer[idx1][idx2] != c_init) {
			return m_answer[idx1][idx2];
		}

		int ret = getAnswer(s1, s2, idx1 + 1, idx2) + s1[idx1];
		if (m_answer[idx1][idx2] > ret) {
			m_answer[idx1][idx2] = ret;
		}

		ret = getAnswer(s1, s2, idx1, idx2 + 1) + s2[idx2];
		if (m_answer[idx1][idx2] > ret) {
			m_answer[idx1][idx2] = ret;
		}

		ret = getAnswer(s1, s2, idx1 + 1, idx2 + 1);
		if (s1[idx1] != s2[idx2]) {
			ret += (s1[idx1] + s2[idx2]);
		}

		if (m_answer[idx1][idx2] > ret) {
			m_answer[idx1][idx2] = ret;
		}

		return m_answer[idx1][idx2];
	}

	int minimumDeleteSum(string s1, string s2) {
		for (int i = 0; i < s1.length(); ++i) {
			vector<int> vec(s2.length(), c_init);
			m_answer.push_back(vec);
		}

		return getAnswer(s1, s2, 0, 0);
	}
};

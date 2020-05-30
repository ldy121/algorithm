class Solution {
private :
	vector<vector<int > > m_answer;
	const int c_init = -1;
	int getSubsequenceLength(string& text1, string& text2, int idx1, int idx2) {
		if (idx1 >= text1.length() || idx2 >= text2.length()) {
			return 0;

		}

		if (m_answer[idx1][idx2] == c_init) {
			int ret = getSubsequenceLength(text1, text2, idx1 + 1, idx2 + 1);
			int maxLength = (text1[idx1] == text2[idx2]) ? (1 + ret) : ret;

			ret = getSubsequenceLength(text1, text2, idx1, idx2 + 1);

			if (maxLength < ret) {
				maxLength = ret;
			}

			ret = getSubsequenceLength(text1, text2, idx1 + 1, idx2);

			if (maxLength < ret) {
				maxLength = ret;
			}

			m_answer[idx1][idx2] = maxLength;
		}

		return m_answer[idx1][idx2];
	}
public:

	int longestCommonSubsequence(string text1, string text2) {
		for (int i = 0; i < text1.length(); ++i) {
			vector vec(text2.length(), c_init);
			m_answer.push_back(vec);
		}

		return getSubsequenceLength(text1, text2, 0, 0);
	}
};

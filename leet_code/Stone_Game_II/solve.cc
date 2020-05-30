class Solution {
private :
	const int c_max = 999999999;
	const int c_init = -1;

	vector<vector<int> > m_answer;

	inline int getLimitLength(vector<int>& piles, int idx, int m) {
		return (idx + m * 2 < piles.size()) ? (idx + m * 2) : (piles.size());
	}

	int getAnswer(vector<int>& piles, int idx, int M) {
		int sumAlex = 0;
		int maxAlex = 0;
		int alexLen = getLimitLength(piles, idx, M);

		if (idx >= piles.size()) {
			return 0;
		}

		if (m_answer[idx][alexLen] != c_init) {
			return m_answer[idx][alexLen];
		}

		for (int i = idx; i < alexLen; ++i) {
			int m = ((i - idx) + 1 > M) ? (i - idx) + 1 : M;
			int lenLee = getLimitLength(piles, i + 1, m);
			int idxLee = i + 1;
			int minAlex = c_max;

			for (int j = idxLee; j < lenLee; ++j) {
				int mm = ((j - idxLee) + 1 > m) ? (j - idxLee) + 1 : m;
				int nextAlex = getAnswer(piles, j + 1, mm);
				if (nextAlex < minAlex) {
					minAlex = nextAlex;
				}
			}

			sumAlex += piles[i];
			if (maxAlex < (sumAlex + minAlex)) {
				maxAlex = sumAlex + ((minAlex == c_max) ? (0) : (minAlex));
			}
		}

		m_answer[idx][alexLen] = maxAlex;
		return m_answer[idx][alexLen];
	}
public:
	int stoneGameII(vector<int>& piles) {
		for (int i = 0; i < piles.size(); ++i) {
			vector<int> vec(piles.size() + 1, c_init);
			m_answer.push_back(vec);
		}
		return getAnswer(piles, 0, 1);
	}
};

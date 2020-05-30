class Solution {
private :
	const int c_init = -1;    
	int m_answer;
	vector<int> m_hash;
	void getAnswer(int idx, int N) {
		if (idx > N) {
			++m_answer;
			return;
		}

		for (int i = 1; i <= N; ++i) {
			if (m_hash[i] != c_init) {
				continue;
			}

			if (((i % idx) == 0) || ((idx % i) == 0)) {
				m_hash[i] = idx;
				getAnswer(idx + 1, N);
				m_hash[i] = c_init;
			}
		}
	}

public:
	int countArrangement(int N) {
		m_answer = 0;        
		for (int i = 0; i <= N; ++i) {
			m_hash.push_back(c_init);
		}
		getAnswer(1, N);
		return m_answer;
	}
};

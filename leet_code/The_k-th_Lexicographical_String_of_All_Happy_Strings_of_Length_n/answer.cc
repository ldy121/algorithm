class Solution {
private :
	string m_answer;
	int m_k;
	int m_n;
	int m_target;

	void getAnswer(char prev, string str) {
		if (str.length() == m_n) {
			if (++m_k == m_target) {
				m_answer = str;
			}
			return;
		}

		for (int i = 0; i < 3; ++i) {
			if (prev != ('a' + i)) {
				char ch = 'a' + i;
				getAnswer(ch, str + ch);
			}
			if (m_answer.length() > 0) {
				break;
			}
		}
	}

public:
	string getHappyString(int n, int k) {
		m_n = n;
		m_target = k;
		m_k = 0;

		getAnswer(' ', string());

		return m_answer;        
	}
};

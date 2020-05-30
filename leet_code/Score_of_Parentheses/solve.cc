class Solution {
private :
	int m_idx;
	int getAnswer(string& s) {
		int ret = 0;
		if (s[m_idx] == ')') {
			++m_idx;
			ret = 1;
		} else {
			while (s[m_idx++] == '(') {
				ret += getAnswer(s) * 2;
			}
		}
		return ret;
	}

public:
	int scoreOfParentheses(string S) {
		int answer = 0;
		for (m_idx = 0; m_idx < S.length();) {
			++m_idx;
			answer += getAnswer(S);
		}
		return answer;
	}
};

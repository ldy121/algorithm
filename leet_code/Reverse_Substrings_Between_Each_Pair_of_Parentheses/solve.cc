class Solution {
private :
	string getAnswer(string& s, int &idx) {
		string ret;

		while (idx < s.length()) {
			if (s[idx] == '(') {
				string str = getAnswer(s, ++idx);
				ret += str;
			} else if (s[idx] == ')') {
				++idx;
				break;
			} else {
				ret += s[idx++];
			}
		}

		for (int i = 0, j = ret.length() - 1; i < j; ++i, --j) {
			char k = ret[i];
			ret[i] = ret[j];
			ret[j] = k;
		}

		return ret;
	}

public:
	string reverseParentheses(string s) {
		string answer;

		for (int i = 0; i < s.length();) {
			if (s[i] == '(') {
				answer += getAnswer(s, ++i);
			} else {
				answer += s[i++];
			}
		}
		return answer;
	}
};

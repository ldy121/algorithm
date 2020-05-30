class Solution {
public:
	int minAddToMakeValid(string S) {
		stack<char> sp;

		for (int i = 0; i < S.length(); ++i) {
			if (S[i] == ')' && !sp.empty() && sp.top() == '(') {
				sp.pop();
			} else {
				sp.push(S[i]);
			}
		}

		return sp.size();
	}
};

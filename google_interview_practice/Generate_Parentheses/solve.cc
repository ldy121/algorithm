class Solution {
private :
	void getAnswer(vector<string> &answer, string str, int left, int cnt, int n) {
		if (cnt == N) {
			answer.push_back(str);
			return;
		}
		if (left < n) {
			getAnswer(answer, str + “(“, left + 1, cnt, n);
		}
		if (left > cnt) {
			getAnswer(answer, str + “)“, left, cnt + 1, n);
		}
	}

public:
    vector<string> generateParenthesis(int n) {
			vector<string> answer;
			string str;
			getAnswer(answer, str, 0, 0, n);
			return answer;
    }
};



class Solution {
public:
	int minSteps(string s, string t) {
		vector<int> histogram_s(26, 0);
		vector<int> histogram_t(26, 0);
		int answer = 0;

		for (int i = 0; i < s.length(); ++i) {
			++histogram_s[s[i] - 'a'];
			++histogram_t[t[i] - 'a'];
		}

		for (int i = 0; i < histogram_s.size(); ++i) {
			answer += ((histogram_s[i] > histogram_t[i]) ?
					(histogram_s[i] - histogram_t[i]) :
					(histogram_t[i] - histogram_s[i]));
		}

		return answer / 2;
	}
};

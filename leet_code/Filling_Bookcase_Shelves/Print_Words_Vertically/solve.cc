class Solution {
public:
	vector<string> printVertically(string s) {
		vector<string> answer;
		vector<int> words;
		vector<int> wordLength;
		int maxLength = 0;

		for (int i = 0; i < s.length(); ++i) {
			int length = 0;
			while (i < s.length() && s[i] != ' ') {
				++length;
				++i;
			}

			wordLength.push_back(length);
			words.push_back(i - length);

			if (maxLength < length) {
				maxLength = length;
			}
		}

		for (int i = 0; i < maxLength; ++i) {
			answer.push_back(string());
		}

		for (int i = 0; i < answer.size(); ++i) {
			for (int j = 0; j < words.size(); ++j) {
				if (i < wordLength[j]) {
					answer[i].push_back(s[words[j] + i]);
				} else {
					answer[i].push_back(' ');
				}
			}
		}

		for (int i = 0; i < answer.size(); ++i) {
			for (string::reverse_iterator iter = answer[i].rbegin(); iter != answer[i].rend(); ++iter) {
				if (*iter == ' ') {
					answer[i].pop_back();
				} else {
					break;
				}
			}
		}

		return answer;
	}
};

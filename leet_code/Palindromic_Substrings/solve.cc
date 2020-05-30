class Solution {
public:
	int countSubstrings(string s) {
		int ret = 0;
		for (int i = 0; i < s.length(); ++i) {
			for (int j = i - 1, k = i; j >= 0 && k < s.length(); --j, ++k) {
				if (s[j] == s[k]) {
					++ret;
				} else {
					break;
				}
			}

			for (int j = 0; i - j >= 0 && i + j < s.length(); ++j) {
				if (s[i - j] == s[i + j]) {
					++ret;
				} else {
					break;
				}
			}
		}
		return ret;
	}
};

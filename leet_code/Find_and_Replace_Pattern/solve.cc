class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> ret;
		for (int i = 0; i < words.size(); ++i) {
			unordered_map<char, char> word_hash;
			unordered_map<char, char> pattern_hash;
			int j;

			for (j = 0; (j < pattern.length()) && (j < words[i].length()); ++j) {
				if (word_hash.find(words[i][j]) == word_hash.end()) {
					word_hash[words[i][j]] = pattern[j];
				} else if (word_hash[words[i][j]] != pattern[j]) {
					break;
				}

				if (pattern_hash.find(pattern[j]) == pattern_hash.end()) {
					pattern_hash[pattern[j]] = words[i][j];
				} else if (pattern_hash[pattern[j]] != words[i][j]) {
					break;
				}
			}

			if ((j == words[i].length()) && (j == pattern.length())) {
				ret.push_back(words[i]);
			}
		}
		return ret;
	}
};

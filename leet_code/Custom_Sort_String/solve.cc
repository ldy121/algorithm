class Solution {
public:
	string customSortString(string S, string T) {
		unordered_map<char, string> hash;
		string ret;

		for (int i = 0; i < S.length(); ++i) {
			hash[S[i]] = string();
		}

		for (int i = 0; i < T.length(); ++i) {
			if (hash.find(T[i]) == hash.end()) {
				ret += T[i];
			} else {
				hash[T[i]] += T[i];
			}
		}

		for (int i = 0; i < S.length(); ++i) {
			ret = ret + hash[S[i]];
		}

		return ret;
	}
};

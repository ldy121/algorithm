class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> src(26, 0);
		vector<int> dst(26, 0);
		vector<int> ret;

		for (int i = 0; i < S.length(); ++i) {
			++src[S[i] - 'a'];
		}

		for (int i = 0, j = 0, k = 0; i < S.length(); ++i) {
			++dst[S[i] - 'a'];
			for (k = 0; (k < 26) && ((dst[k] == 0) || (src[k] == dst[k])); ++k);
			if (k == 26) {
				ret.push_back(i - j + 1);
				j = i + 1;
			}
		}
		return ret;
	}
};

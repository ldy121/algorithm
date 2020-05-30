class Solution {
public:
	bool queryString(string S, int N) {
		for (int i = 1; i <= N; ++i) {
			string binary;

			for (int j = i; j > 0; j >>= 1) {
				if (j & 1) {
					binary = "1" + binary;
				} else {
					binary = "0" + binary;
				}
			}
			if (S.find(binary) == string::npos) {
				return false;
			}
		}
		return true;
	}
};

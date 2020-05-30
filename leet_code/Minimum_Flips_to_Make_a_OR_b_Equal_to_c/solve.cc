class Solution {
public:
	int minFlips(int a, int b, int c) {
		int answer = 0;
		for (int i = 0; i < sizeof(int) * 8; ++i) {
			if (!(c & 1)) {
				if (a & 1) {
					++answer;
				}

				if (b & 1) {
					++answer;
				}
			} else {
				if ((!(a & 1)) && (!(b & 1))) {
					++answer;
				}
			}

			a >>= 1;
			b >>= 1;
			c >>= 1;
		}
		return answer;
	}
};

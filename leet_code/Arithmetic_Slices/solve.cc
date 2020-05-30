class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int answer = 0;

		for (int i = 0; i + 2 < A.size();) {
			int gap = A[i + 1] - A[i];
			int len = 0;
			int j;

			for (j = i + 2; j < A.size(); ++j) {
				if (A[j] == gap * (j - i) + A[i]) {
					++len;
				} else {
					break;
				}
			}

			if (len > 0) {
				answer += (len * (len + 1) / 2);
				i = j;
			} else {
				++i;
			}
		}

		return answer;
	}
};

class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		int ret = 0;

		for (int i = 0; i < A.size(); ++i) {
			if (A[i][0] == 0) {
				for (int j = 0; j < A[i].size(); ++j) {
					A[i][j] = !A[i][j];
				}
			}
		}

		for (int j = 1; j < A[0].size(); ++j) {
			int zero_cnt = 0;
			int one_cnt  = 0;

			for (int i = 0; i < A.size(); ++i) {
				if (A[i][j] == 1) ++one_cnt;
				else              ++zero_cnt;
			}

			if (zero_cnt > one_cnt) {
				for (int i = 0; i < A.size(); ++i) {
					A[i][j] = !A[i][j];
				}
			}
		}

		for (int i = 0; i < A.size(); ++i) {
			int k = 0;
			for (int j = 0; j < A[i].size(); ++j) {
				k = ((k << 1) | A[i][j]);
			}
			ret += k;
		}

		return ret;
	}
};

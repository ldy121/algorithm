class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		vector<vector<int> > acc(matrix.size());
		int ret = 0;

		for (int i = 0; i < matrix[0].size(); ++i) {
			acc[matrix.size() - 1].push_back(matrix[matrix.size() - 1][i]);
		}

		for (int i = matrix.size() - 2; i >= 0; --i) {
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (matrix[i][j] == 1) {
					acc[i].push_back(acc[i + 1][j] + 1);
				} else {
					acc[i].push_back(0);
				}
			}
		}

		for (int i = 0; i < acc.size(); ++i) {
			for (int j = 0; j < acc[i].size(); ++j) {
				if (matrix[i][j] == 1) {
					int k;
					int max_dist = acc[i][j];
					for (k = j; k < acc[i].size(); ++k ) {
						int dist = (k - j) + 1;

						if (max_dist < dist) {
							break;
						}

						if (acc[i][k] < dist) {
							break;
						}

						if (acc[i][k] < max_dist) {
							max_dist = acc[i][k];
						}
					}

					ret += (k - j);
				}
			}
		}

		return ret;
	}
};

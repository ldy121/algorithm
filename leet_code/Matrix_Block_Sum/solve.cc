class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
		vector<vector<int>> sum_matrix;
		vector<vector<int>> answer_matrix;

		for (int i = 0; i < mat.size(); ++i) {
			sum_matrix.push_back(vector<int>());
			sum_matrix[i].push_back(mat[i][0]);
			for (int j = 1; j < mat[i].size(); ++j) {
				sum_matrix[i].push_back(sum_matrix[i][j - 1] + mat[i][j]);
			}
		}

		for (int j = 0; j < sum_matrix[0].size(); ++j) {
			for (int i = 1; i < sum_matrix.size(); ++i) {
				sum_matrix[i][j] += sum_matrix[i - 1][j];
			}
		}

		for (int i = 0; i < mat.size(); ++i) {
			answer_matrix.push_back(vector<int>());
			for (int j = 0; j < mat[i].size(); ++j) {
				int top      = (i - K);
				int bottom   = (i + K);
				int left     = (j - K);
				int right    = (j + K);

				if (top < 0)                top = 0;
				if (bottom >= mat.size())   bottom = mat.size() - 1;
				if (left < 0)               left = 0;
				if (right >= mat[0].size()) right = mat[0].size() - 1;

				int val = sum_matrix[bottom][right];
				if (top - 1 >= 0)                       val -= sum_matrix[top - 1][right];
				if (left - 1 >= 0)                      val -= sum_matrix[bottom][left - 1];
				if ((top - 1 >= 0) && (left - 1 >= 0))  val += sum_matrix[top - 1][left - 1];

				answer_matrix[i].push_back(val);
			}
		}
		return answer_matrix;
	}
};

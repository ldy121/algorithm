class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int max_idx = (mat[0].size() > mat.size()) ? (mat[0].size()) : (mat.size());
		for (int idx = 0; idx < max_idx; ++idx) {
			int i, j;
			vector<int> col_vec, row_vec;

			for (i = idx, j = 0; i < max_idx || j < max_idx; ++i, ++j) {
				if ((i < mat.size()) && (j < mat[0].size())) row_vec.push_back(mat[i][j]);
				if ((j < mat.size()) && (i < mat[0].size())) col_vec.push_back(mat[j][i]);
			}

			sort(row_vec.begin(), row_vec.end());
			sort(col_vec.begin(), col_vec.end());

			i = idx, j = 0; 
			for (int k = 0; i < max_idx || j < max_idx; ++i, ++j, ++k) {
				if ((i < mat.size()) && (j < mat[0].size())) mat[i][j] = row_vec[k];
				if ((j < mat.size()) && (i < mat[0].size())) mat[j][i] = col_vec[k];
			}
		}
		return mat;
	}
};

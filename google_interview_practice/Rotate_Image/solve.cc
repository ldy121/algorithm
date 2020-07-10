class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int len = matrix.size();
        for (int i = 0; i < matrix.size() / 2; ++i) {
	        for (int j = 0; j < len - 1; ++j) {
		        int tmp = matrix[i][i + j];
                matrix[i][i + j] = matrix[i + len - 1 - j][i];
                matrix[i + len - 1 - j][i] = matrix[i + len - 1][i + len - 1 - j];
                matrix[i + len - 1][i + len - 1 - j] = matrix[i + j][i + len - 1];
                matrix[i + j][i + len - 1] = tmp;
	        }
	        len -= 2;
        }
    }
};



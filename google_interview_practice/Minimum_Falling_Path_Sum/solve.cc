class Solution {
private :
	const int invalid = 100000000;
	int getAnswer(vector<vector<int>>& A, vector<vector<int> > &dp, int row, int col) {
		if (row == A.size()) {
			return 0;
		}
		if (col < 0 || col >= A[row].size()) {
			return invalid;
		}

        if (dp[row][col] == invalid) {
	        dp[row][col] = getAnswer(A, dp, row + 1, col);
	        
            int ret = getAnswer(A, dp, row + 1, col - 1);
	        if (ret != invalid && ret < dp[row][col]) {
		        dp[row][col] = ret;
	        }
	        ret = getAnswer(A, dp, row + 1, col + 1);
	        if (ret != invalid && ret < dp[row][col]) {
		        dp[row][col] = ret;
	        }
	        dp[row][col] += A[row][col];
        }

        return dp[row][col];
	}

public:
    int minFallingPathSum(vector<vector<int>>& A) {
    	vector<vector<int> > dp;
    	int answer = invalid;

        for (int i = 0; i < A.size(); ++i) {
	        vector<int> vec(A[i].size(), invalid);
	        dp.push_back(vec);
        }
        for (int i = 0; i < A[0].size(); ++i) {
	        int ret = getAnswer(A, dp, 0, i);
	        if (ret < answer) {
		        answer = ret;
	        }
        }
	    return answer;
    }
};


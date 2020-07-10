class Solution {
private :
	const int sea = 0;
	const int land = 1;
	void getAnswer(vector<vector<int> > &A, int row, int col) {
  	  if (row < 0 || col < 0 || row >= A.size() || col >= A[row].size() || A[row][col] == sea) {
			return;
	  }
	  A[row][col] = sea;
	  getAnswer(A, row - 1, col);
	  getAnswer(A, row + 1, col);
	  getAnswer(A, row, col - 1);
	  getAnswer(A, row, col + 1);
	}
public:
    int numEnclaves(vector<vector<int>>& A) {
        int ret = 0;
        for (int i = 0; i < A.size(); ++i) {
	        if (A[i][0] == land) {
	            getAnswer(A, i, 0);
	        }
	        if (A[i][A[i].size() - 1] == land) {
	            getAnswer(A, i, A[i].size() - 1);
	        }
        }
        for (int i = 0; i < A[0].size(); ++i) {
	        if (A[0][i] == land) {
	            getAnswer(A, 0, i);
	        }
	        if (A[A.size() - 1][i] == land) {
	            getAnswer(A, A.size() - 1, i);
	        }
        }
        for (int i = 0; i < A.size(); ++i) {
	        for (int j = 0; j < A[i].size(); ++j) {
		        ret += A[i][j];
	        }
        }
        return ret;
    }
};



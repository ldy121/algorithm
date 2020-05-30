
// 2배 면적으로 각각 overlap 하면서 최대 1이 겹치는 부분을 찾는 방식
// B의 좌프영역을 -col, -row 부터 col * 2, row* 2까지 좌표를 확장 시킴
// 계속 traversal 하면서 A 면적의 (0,0) 부터 (row,col)이 겹치는 부분 찾음

class Solution {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int answer = 0;

		for (int startRowA = 0; startRowA < (A.size() * 2); ++startRowA) {
			for (int startColA = 0; startColA < (A[0].size() * 2); ++startColA) {
				int startRowB = startRowA + 1 - A.size();
				int startColB = startColA + 1 - A[0].size();
				int sum = 0;

				for (int i = 0, row = startRowB; i < A.size(); ++i, ++row) {
					for (int j = 0, col = startColB; j < A[i].size(); ++j, ++col) {
						if (row < 0) continue;
						if (col < 0) continue;
						if (row >= B.size()) continue;
						if (col >= B[0].size()) continue;
						if (A[row][col] && B[i][j]) {
							++sum;
						}
					}
				}
				if (sum > answer) {
					answer = sum;
				}
			}
		}
		return answer;
	}
};

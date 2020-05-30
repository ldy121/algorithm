class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int> > ret;

		for (int i = 0, j = 0; (i < A.size()) && (j < B.size());) {
			if (A[i][1] < B[j][0]) {
				++i;
			} else if (A[i][0] > B[j][1]) {
				++j;
			} else if (A[i][0] <= B[j][0]) {
				vector<int> vec;
				vec.push_back(B[j][0]);

				if (A[i][1] <= B[j][1]) {
					vec.push_back(A[i++][1]);
				} else {
					vec.push_back(B[j++][1]);
				}
				ret.push_back(vec);
			} else {
				vector<int> vec;
				vec.push_back(A[i][0]);

				if (A[i][1] <= B[j][1]) {
					vec.push_back(A[i++][1]);
				} else {
					vec.push_back(B[j++][1]);
				}
				ret.push_back(vec);
			}
		}

		return ret;
	}
};

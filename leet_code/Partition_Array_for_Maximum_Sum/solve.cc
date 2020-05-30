class Solution {
private :
	const int init = -1;
	int get_answer(vector<vector<int> > &answer, int left, int right, int K) {
		if (answer[left][right] == init) {
			int ans = init;
			int max = answer[left][left];

			for (int i = 0; (i < K) && (left + i <= right); ++i) {
				if (max < answer[left + i][left + i]) {
					max = answer[left + i][left + i];
				}

				int val = max * (i + 1);

				if (left + i + 1 <= right) {
					val += get_answer(answer, left + i + 1, right, K);
				}

				if (ans < val) {
					ans = val;
				}
			}
			answer[left][right] = ans;
		}

		return answer[left][right];
	}

public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
	    vector<vector<int> > answer;

	    for (int i = 0; i < A.size(); ++i) {
		    vector<int> vec(A.size(), init);
		    answer.push_back(vec);
		    answer[i][i] = A[i];
	    }

	    return get_answer(answer, 0, A.size() - 1, K);
    }
};

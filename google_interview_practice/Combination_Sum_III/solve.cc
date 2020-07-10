class Solution {
private :
	const int maxNum = 9;
    void getAnswer(vector<vector<int> > &answer, vector<int> &vec, int idx, int num, int sum, int n) {
	    if (idx >= vec.size()) {
		        if (sum == n) {
			        answer.push_back(vec);
		        }
		        return;
	    }

	    for (int i = num; i <= maxNum; ++i) {
		    vec[idx] = i;
		    sum += i;
		    getAnswer(answer, vec, idx + 1, i + 1, sum, n);
		    sum -= i;
	    }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
	    vector<vector<int> > answer;
	    vector<int> vec(k);
	    getAnswer(answer, vec, 0, 1, 0, n);
	    return answer;
    }
};


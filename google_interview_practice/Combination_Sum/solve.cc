class Solution {
private :
	void getAnswer(vector<vector<int> > &answer, vector<int>& candidates,
        vector<int> &vec, int idx, int sum, int target) {
        int i = 0;
        
        if (sum == target) {
            answer.push_back(vec);
            return;
        } else if (sum > target) {
	        return;
        } else if (idx >= candidates.size()) {
	        return;
        }

        getAnswer(answer, candidates, vec, idx + 1, sum, target);
        for (i = 0; sum < target; ++i) {
            sum += candidates[idx];
            vec.push_back(candidates[idx]);
            getAnswer(answer, candidates, vec, idx + 1, sum, target);
        }
        while (i > 0) {
            vec.pop_back();
            sum -= candidates[idx];
            --i;
        }
	}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > answer;
        vector<int> vec;

        sort(candidates.begin(), candidates.end());
        getAnswer(answer, candidates, vec, 0, 0, target);
        return answer;
    }
};



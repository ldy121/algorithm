class Solution {
private :
   const int invalid = -1000000000;
    void getAnswer(vector<vector<int> > &answer, vector<int> &nums, vector<int> &ans) {
	    if (ans.size() < nums.size()) {
		    for (int i = 0; i < nums.size(); ++i) {
			    if (nums[i] != invalid) {
    				int val = nums[i];
	    			ans.push_back(val);
		    		nums[i] = invalid;
			    	getAnswer(answer, nums, ans);
				    ans.pop_back();
				    nums[i] = val;
			    }
            }
        } else {
            answer.push_back(ans);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > answer;
        vector<int> ans;
        getAnswer(answer, nums, ans);
        return answer;        
    }
};


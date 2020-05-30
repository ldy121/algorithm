class Solution {
private :
	vector<vector<int> > m_answer;
	void getAnswer(vector<int>& nums, vector<int> answer, int idx) {
		if (idx < nums.size()) {
			getAnswer(nums, answer, idx + 1);
			answer.push_back(nums[idx]);
			getAnswer(nums, answer, idx + 1);
		} else {
			m_answer.push_back(answer);
		}
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) {
		getAnswer(nums, vector<int>(), 0);
		return m_answer;
	}
};

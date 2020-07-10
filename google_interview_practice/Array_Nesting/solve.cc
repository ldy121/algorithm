class Solution {
private :
	const int invalid = -1;
	int getAnswer(vector<int> &answer, vector<int> &nums, vector<bool> &visit, int idx) {
		if (idx < 0 || idx >= nums.size() || visit[idx] == true) {
			return 0;
		}

		if (answer[idx] != invalid) {
			return answer[idx];
		}

		visit[idx] = true;
		int ret = 1 + getAnswer(answer, nums, visit, nums[idx]);
		visit[idx] = false;

		answer[idx] = ret;
		return ret;
	}
public:
    int arrayNesting(vector<int>& nums) {
		vector<bool> visit(nums.size(), false);
		vector<int> answer(nums.size(), invalid);
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int ret = getAnswer(answer, nums, visit, i);
			if (ans < ret) {
				ans = ret;
			}
		}
		return ans;
    }
};



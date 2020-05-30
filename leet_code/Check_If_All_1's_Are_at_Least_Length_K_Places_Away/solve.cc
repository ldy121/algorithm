class Solution {
public:
	bool kLengthApart(vector<int>& nums, int k) {
		int prev = -(k + 1);

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 1) {
				if ((i - (prev + 1)) < k) {
					return false;
				} else {
					prev = i;
				}
			}
		}

		return true;
	}
};

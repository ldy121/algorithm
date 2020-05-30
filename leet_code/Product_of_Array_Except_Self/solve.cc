class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ret(nums.size(), 1);
		int low = 1, high = 1;

		for (int i = 0; i < nums.size(); ++i) {
			int j = nums.size() - 1 - i;
			ret[i] *= low;
			ret[j] *= high;
			low *= nums[i];
			high *= nums[j];
		}

		return ret;
	}
};

class Solution {
private :
	const int none = 0;
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ret;

		for (int i = 0; i < nums.size();) {
			int idx = nums[i] - 1;
			if ((i == idx) || (nums[i] == none)) {
				++i;
				continue;
			}

			if (nums[idx] == nums[i]) {
				ret.push_back(nums[i]);
				nums[idx] = none;
				nums[i] = none;
				++i;
			} else {
				int j = nums[i];
				nums[i] = nums[idx];
				nums[idx] = j;
			}
		}

		return ret;
	}
};

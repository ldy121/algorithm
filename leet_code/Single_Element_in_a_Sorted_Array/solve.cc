class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int low, high;
		for (low = 0, high = nums.size() - 1; low < high;) {
			int mid = (high + low) / 2;
			if (nums[mid] == nums[mid - 1]) {
				if ((high - mid) % 2) {
					low = mid + 1;
				} else {
					high = mid - 2;
				}
			} else if (nums[mid] == nums[mid + 1]) {
				if ((mid - low) % 2) {
					high = mid - 1;
				} else {
					low = mid + 2;
				}
			} else {
				return nums[mid];
			}
		}
		return nums[low];
	}
};

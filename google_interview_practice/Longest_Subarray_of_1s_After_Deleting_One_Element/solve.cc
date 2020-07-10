class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> vec;
        int ret = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                vec.push_back(i);
            }
        }
        if (vec.size() == 0) {
            return (nums.size() > 0) ? (nums.size() - 1) : 0;
        }
        if (vec.size() == nums.size()) {
            return 0;
        }
        for (int i = 0; i < vec.size(); ++i) {
            int before = (i > 0) ? (vec[i] - vec[i - 1] - 1) : vec[i];
            int after = (i + 1 < vec.size()) ? (vec[i + 1] - vec[i] - 1) : (nums.size() - vec[i] - 1);
            
            if (ret < before + after) {
                ret = before + after;
            }
        }
        return ret;
    }
};

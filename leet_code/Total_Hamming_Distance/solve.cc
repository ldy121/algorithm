class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int answer = 0;
        for (int j = 0 ; j < sizeof(int) * 8; ++j) {
            int one = 0, zero = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if ((nums[i] & (1 << j)) > 0) {
                    ++one;
                } else {
                    ++zero;
                }
            }
            answer += (one * zero);
        }
        return answer;
    }
};

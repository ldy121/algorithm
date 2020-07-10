class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        int xorSum = 0, a = 0, b = 0;
        int lsb;
        for (int i = 0; i < nums.size(); ++i) {
            xorSum ^= nums[i];
        }
        
        for (lsb = 1; (xorSum & lsb) == 0; lsb <<= 1);

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & lsb) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};

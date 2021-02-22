class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ONE = 0;
        int TWO = 0;
        
        for (int x : nums){
            ONE = (ONE^x) & ~TWO;
            TWO = (TWO^x) & ~ONE;
        }
        
        return ONE;
    }
};

class Solution {
private :
    vector<int> m_nums;
public:
    Solution(vector<int>& nums) {
        m_nums.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(m_nums.size(), -1);
        for (int i = 0; i < m_nums.size(); ++i) {
            int j = rand() % m_nums.size();
            while (ret[j] != -1) {
                j = rand() % m_nums.size();
            }
            ret[j] = m_nums[i];

        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

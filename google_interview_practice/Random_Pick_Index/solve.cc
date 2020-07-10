class Solution {
private :
	unordered_map<int, vector<int>> m_hash;
	unordered_map<int, int> m_random;
public:
  Solution(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) {
			if (m_hash.find(nums[i]) == m_hash.end()) {
				m_hash[nums[i]] = vector<int>();
				m_random[nums[i]] = 0;
			}
			m_hash[nums[i]].push_back(i);
		}
	}
    
	int pick(int target) {
		int ret = m_hash[target][m_random[target]];
		m_random[target] = (m_random[target] + 1) % m_hash[target].size();
		return ret;
	}
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */



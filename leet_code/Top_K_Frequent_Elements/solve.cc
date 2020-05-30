class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, list<int>::iterator > hash;
		unordered_map<int, int> frequent;
		vector<list<int> > elements;
		vector<int> ret;

		elements.push_back(list<int>());
		for (int i = 0; i < nums.size(); ++i) {
			if (hash.find(nums[i]) == hash.end()) {
				frequent[nums[i]] = 0;                
				elements[0].push_front(nums[i]);
				hash[nums[i]] = elements[0].begin();
			}

			elements[frequent[nums[i]]].erase(hash[nums[i]]);
			if (elements.size() <= ++frequent[nums[i]]) {
				elements.push_back(list<int>());
			}

			elements[frequent[nums[i]]].push_front(nums[i]);
			hash[nums[i]] = elements[frequent[nums[i]]].begin();
		}

		for (int i = elements.size() - 1; i >= 0; --i) {
			for (list<int>::iterator iter = elements[i].begin(); iter != elements[i].end(); ++iter) {
				ret.push_back(*iter);
				--k;
			}

			if (k <= 0) {
				break;
			}
		}
		return ret;
	}
};

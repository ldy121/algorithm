class Solution {
public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> answer;
		vector<int> ret;
		unordered_map<int, int> hash;

		int size = (1 << n);
		int num = 0;

		for (hash[num] = 0, answer.push_back(num); answer.size() < size;) {
			int i = answer[answer.size() - 1];
			for (int j = 0;; ++j) {
				int k =  (((i >> j) & 1) > 0) ? (i & ~(1 << j)) : (i |  (1 << j));

				if (hash.find(k) == hash.end()) {
					hash[k] = answer.size();
					answer.push_back(k);
					break;
				}
			}
		}

		for (int i = hash[start]; ret.size() < size; i = (i + 1) % answer.size()) {
			ret.push_back(answer[i]);
		}

		return ret;
	}
};

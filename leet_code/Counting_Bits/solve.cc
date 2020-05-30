class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ret;
		ret.push_back(0);
		for (int i = 1; ret.size() <= num;) {
			int k = 0;
			for (int j = ret.size(); (j > 0) && (ret.size() <= num); --j) {
				ret.push_back(ret[k++] + 1);
			}
		}
		return ret;
	}
};

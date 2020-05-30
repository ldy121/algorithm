class Solution {
public:
	int numTeams(vector<int>& rating) {
		int ret = 0;

		for (int i = 0; i < rating.size(); ++i) {
			int after_high = 0, after_low = 0, before_high = 0, before_low = 0;

			for (int j = i + 1; j < rating.size(); ++j) {
				if (rating[i] < rating[j]) ++after_high;
				if (rating[i] > rating[j]) ++after_low;
			}

			for (int j = i - 1; j >= 0; --j) {
				if (rating[i] < rating[j]) ++before_high;
				if (rating[i] > rating[j]) ++before_low;
			}

			ret += (before_low * after_high);
			ret += (before_high * after_low);
		}
		return ret;
	}
};

class Solution {
private :
	static bool comp (vector<int>& a, vector<int>& b) {
		return ((a[0] < b[0]) || ((a[0] == b[0]) && (a[1] >= b[1])));
	}

public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int ret = 0;

		sort(intervals.begin(), intervals.end(), Solution::comp);

		for (int j = 0, i = 1; i < intervals.size(); ++i) {
			if ((intervals[j][0] <= intervals[i][0]) && (intervals[j][1] >= intervals[i][1])) {
				++ret;
			} else {
				j = i;
			}
		}

		return intervals.size() - ret;
	}
};

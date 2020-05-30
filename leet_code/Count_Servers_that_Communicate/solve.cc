class Solution {
private :
	const int c_visit = 2;
public:
	int countServers(vector<vector<int>>& grid) {
		int ret = 0;

		for (int i = 0; i < grid.size(); ++i) {
			int cnt = 0;
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] > 0) {
					++cnt;
				}
			}
			if (cnt > 1) {
				for (int j = 0; j < grid[i].size(); ++j) {
					if (grid[i][j] == 1) {
						grid[i][j] = c_visit;
						++ret;
					}
				}
			}
		}

		for (int j = 0; j < grid[0].size(); ++j) {
			int cnt = 0;
			for (int i = 0; i < grid.size(); ++i) {
				if (grid[i][j] > 0) {
					++cnt;
				}
			}

			if (cnt > 1) {
				for (int i = 0; i < grid.size(); ++i) {
					if (grid[i][j] == 1) {
						grid[i][j] = c_visit;
						++ret;
					}
				}
			}
		}
		return ret;
	}
};

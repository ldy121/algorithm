class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		vector<int> horizontal_max;
		vector<int> vertical_max(grid[0].size(), 0);
		int ret = 0;

		for (int i = 0; i < grid.size(); ++i) {
			int k = 0;
			for (int j = 0; j < grid[i].size(); ++j) {
				if (vertical_max[j] < grid[i][j]) {
					vertical_max[j] = grid[i][j];
				}

				if (k < grid[i][j]) {
					k = grid[i][j];
				}
			}
			horizontal_max.push_back(k);
		}

		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				int k = (horizontal_max[i] < vertical_max[j]) ? (horizontal_max[i]) : (vertical_max[j]);
				ret += (k - grid[i][j]);
			}
		}

		return ret;
	}
};

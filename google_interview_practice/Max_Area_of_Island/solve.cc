class Solution {
private :
	const int invalid = -1;
	const int valid = 1;
	void getMaxArea(vector<vector<int>>& grid, int row, int col, int &count) {
		if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[row].size() ||
            grid[row][col] != valid) {
			return;
		}
		grid[row][col] = invalid;
        ++count;

		getMaxArea(grid, row - 1, col, count);
		getMaxArea(grid, row + 1, col, count);
		getMaxArea(grid, row, col - 1, count);
		getMaxArea(grid, row, col + 1, count);
	}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0;
	    for (int i = 0; i < grid.size(); ++i) {
		    for (int j = 0; j < grid[i].size(); ++j) {
                int count = 0;
    			getMaxArea(grid, i, j, count);
                if (answer < count) {
                    answer = count;
                }
	    	}
	    }
	    return answer;
    }
};


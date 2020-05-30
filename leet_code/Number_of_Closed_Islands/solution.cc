class Solution {
private :
	const int c_land = 0;
	const int c_water = 1;
	const int c_visit = 2;    
	const int c_invalid = -1;

	void visit(vector<vector<int> >& grid, int row, int col, int color) {
		if (row < 0) {
			return;
		}
		if (grid.size() <= row) {
			return;
		}

		if (col < 0) {
			return;
		}

		if (grid[row].size() <= col) {
			return;
		}

		if (grid[row][col] != c_land) {
			return;
		}

		grid[row][col] = color;

		visit(grid, row - 1, col, color);
		visit(grid, row + 1, col, color);
		visit(grid, row, col - 1, color);
		visit(grid, row, col + 1, color);
	}

public:
	int closedIsland(vector<vector<int>>& grid) {
		int answer = 0;

		for (int i = 0; i < grid[0].size(); ++i) {
			visit(grid, 0, i, c_invalid);
			visit(grid, grid.size() - 1, i, c_invalid);
		}

		for (int i = 0; i < grid.size(); ++i) {
			visit(grid, i, 0, c_invalid);
			visit(grid, i, grid[i].size() - 1, c_invalid);
		}

		for (int i = 1; i < grid.size(); ++i) {
			for (int j = 1; j < grid[i].size(); ++j) {
				if (grid[i][j] == c_land) {
					visit(grid, i, j, c_visit);
					++answer;
				}
			}
		}

		return answer;
	}
};

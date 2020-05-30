class Solution {
private :
	int m_answer;

public:
	void get_answer(vector<vector<int> >& grid, int row, int col, int sum) {
		int val = grid[row][col];

		sum += val;

		if (sum > m_answer) {
			m_answer = sum;
		}

		grid[row][col] = 0;

		if ((row + 1 < grid.size())    && (grid[row + 1][col] > 0)) get_answer(grid, row + 1, col, sum);
		if ((row - 1 >= 0)             && (grid[row - 1][col] > 0)) get_answer(grid, row - 1, col, sum);
		if ((col + 1 < grid[0].size()) && (grid[row][col + 1] > 0)) get_answer(grid, row, col + 1, sum);
		if ((col - 1 >= 0)             && (grid[row][col - 1] > 0)) get_answer(grid, row, col - 1, sum);        

		grid[row][col] = val;
	}

	int getMaximumGold(vector<vector<int>>& grid) {
		m_answer = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] > 0) {
					get_answer(grid, i, j, 0);
				}
			}
		}

		return m_answer;
	}
};

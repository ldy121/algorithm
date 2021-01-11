#include <iostream>

using namespace std;

const int N = 9;
const int NN = 3;
const int all_fill = ((1 << 9) - 1) << 1;

bool SolvedSudoku(int grid[][N])
{
	for (int i = 0; i < N; ++i) {
		int check_row = 0;
		int check_col = 0;
		for (int j = 0; j < N; ++j) {
			check_row |= (1 << grid[i][j]);
			check_col |= (1 << grid[j][i]);
		}
		if ((check_row != all_fill) || (check_col != all_fill)) {
			return false;
		}
	}

	for (int i = 0; i < N; i += NN) {
		for (int j = 0; j < N; j += NN) {
			int check = 0;
			for (int ii = 0; ii < NN; ++ii) {
				for (int jj = 0; jj < NN; ++jj) {
					check |= (1 << grid[i + ii][j + jj]);
				}
			}
			if (check != all_fill) {
				return false;
			}
		}
	}
	return true;
}

bool SolveSudoku(int grid[][N])
{
	int available = all_fill;
	int row = N, col = N;
	int start_row, start_col;
	bool ret = false;

	for (int i = 0; (row == N) && (i < N); ++i) {
		for (int j = 0; (col == N) && (j < N); ++j) {
			if (grid[i][j] == 0) {
				row = i;
				col = j;
			}
		}
	}

	if ((row < N) && (col < N)) {
		for (int i = 0; i < N; ++i) {
			if (grid[row][i] > 0) available &= ~(1 << grid[row][i]);
			if (grid[i][col] > 0) available &= ~(1 << grid[i][col]);
		}
		start_row = (row / NN) * NN;
		start_col = (col / NN) * NN;
		for (int i = 0; i < NN; ++i) {
			for (int j = 0; j < NN; ++j) {
				if (grid[start_row + i][start_col + j] > 0) {
					available &= ~(1 << grid[start_row + i][start_col + j]);
				}
			}
		}

		for (int i = 1; i <= N; ++i) {
			int j = (1 << i);
			if ((j & available) > 0) {
				grid[row][col] = i;
				ret = SolveSudoku(grid);
				if (ret) {
					break;
				} else {
					grid[row][col] = 0;
				}
			}
		}

	} else {
		ret = SolvedSudoku(grid);
	}
	return ret;
}

void printGrid(int grid[][N])
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

// Driver Code 
int main()
{
	// 0 means unassigned cells  
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
	{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
	{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
	{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
	{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
	{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
	{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	if (SolveSudoku(grid) == true)
		printGrid(grid);
	else
		cout << "No solution exists";

	return 0;
}

// This is code is contributed by rathbhupendra 
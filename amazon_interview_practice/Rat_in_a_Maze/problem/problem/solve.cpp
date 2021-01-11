#include <iostream>

using namespace std;

const int N = 4;

bool solve(int answer[][N], int maze[][N], int row, int col)
{
	answer[row][col] = 1;

	if ((row == N - 1) && (col == N - 1)) {
		return true;
	} else {
		if ((col < (N - 1)) && (maze[row][col + 1] == 1) &&
			(solve(answer, maze, row, col + 1))) {
			return true;
		}
		else if (row < (N - 1) && (maze[row + 1][col] == 1) &&
			(solve(answer, maze, row + 1, col))) {
			return true;
		}
	}

	answer[row][col] = 0;
	return false;
}

void solveMaze(int maze[][N])
{
	int visit[N][N];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			visit[i][j] = 0;
		}
	}

	if (solve(visit, maze, 0, 0)) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << visit[i][j] << " ";
			}
			cout << endl;
		}
	}
}


// driver program to test above function 
int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
	{ 1, 1, 0, 1 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 1, 1 } };

	solveMaze(maze);
	return 0;
}
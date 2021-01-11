// driver program to test above function 
#include <iostream>

using namespace std;

const int N = 4;

void mask(int ** map, int row, int col, int val)
{
	for (int i = 1; i < N; ++i) {
		if ((row - i) >= 0) {
			map[row - i][col] += val;
			if ((col - i) >= 0) map[row - i][col - i] += val;
			if ((col + i) < N) 	map[row - i][col + i] += val;
		}

		if ((row + i) < N) {
			map[row + i][col] += val;
			if ((col - i) >= 0) map[row + i][col - i] += val;
			if ((col + i) < N) 	map[row + i][col + i] += val;
		}

		if ((col - i) >= 0) map[row][col - i] += val;
		if ((col + i) < N) 	map[row][col + i] += val;
	}
}

void print(int **map)
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 0) cout << "1 ";
			else			    cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
}

void solve(int ** map, int index)
{
	if (index < N) {
		for (int i = 0; i < N; ++i) {
			if (map[index][i] == 0) {
				mask(map, index, i, 1);
				solve(map, index + 1);
				mask(map, index, i, -1);
			}
		}
	} else {
		print(map);
	}
}

void solveNQ()
{
	int ** map;

	map = new int *[N];
	for (int i = 0; i < N; ++i) {
		map[i] = new int[N];
		for (int j = 0; j < N; ++j) {
			map[i][j] = 0;
		}
	}

	solve(map, 0);

	for (int i = 0; i < N; ++i) {
		delete[] map[i];
	}
	delete map;
}

int main()
{
	solveNQ();
	return 0;
}
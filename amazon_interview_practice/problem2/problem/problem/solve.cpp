#include <stdio.h>
#include <iostream>

#pragma warning(disable : 4996)
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <queue>

using namespace std;

class POINT {
public :
	POINT(int row, int col) : m_row(row), m_col(col) {};
	int m_row;
	int m_col;
};

int removeObstacle(int numRows, int numColumns, int **lot)
{
	queue<POINT> q;
	int ans;

	q.push(POINT(0, 0));
	
	for (ans = 1; !q.empty(); ++ans) {
		for (int size = q.size(); size > 0; --size) {
			int row = q.front().m_row;
			int col = q.front().m_col;

			q.pop();

			if (lot[row][col] == 9) {
				return ans;
			}
			else {
				if (((row - 1) >= 0)         && (lot[row - 1][col] != 0)) q.push(POINT(row - 1, col));
				if (((col - 1) >= 0)         && (lot[row][col - 1] != 0)) q.push(POINT(row, col - 1));
				if (((row + 1) < numRows)    && (lot[row + 1][col] != 0)) q.push(POINT(row + 1, col));
				if (((col + 1) < numColumns) && (lot[row][col + 1] != 0)) q.push(POINT(row, col + 1));
			}
			lot[row][col] = 0;
		}
	}
	return -1;
}
// FUNCTION SIGNATURE ENDS


int main(void)
{
	int **arr;

	arr = new int *[3];

	for (int i = 0; i < 3; ++i) {
		arr[i] = new int[3];
	}

	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[0][2] = 0;

	arr[1][0] = 1;
	arr[1][1] = 0;
	arr[1][2] = 0;

	arr[1][0] = 1;
	arr[1][1] = 9;
	arr[1][2] = 1;

	cout << removeObstacle(3, 3, arr) << endl;

	for (int i = 0; i < 3; ++i) {
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}
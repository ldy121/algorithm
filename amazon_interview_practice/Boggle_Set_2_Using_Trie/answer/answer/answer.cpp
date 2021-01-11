#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

#pragma warning(disable : 4996)

class POINT {
public :
	POINT(int row, int col) : m_iRow(row), m_iCol(col) {};
	int m_iRow;
	int m_iCol;
};

char dictionary[][6] = { "GEEKS", "FOR", "QUIZ", "GO" };
char boggle[][3] = { { 'G','I','Z' },
					{ 'U','E','K' },
					{ 'Q','S','E' } };

const int num_char = 26;

bool path[num_char][num_char];

inline void mark_path(bool graph[][num_char], char dlc[][3], int src, int row, int col, int row_size, int col_size)
{
	if ((0 <= row) && (row < row_size) && (0 <= col) && (col < col_size)) {
		int dst = dlc[row][col] - 'A';
		graph[src][dst] = true;
		graph[dst][src] = true;
	}
}

void get_answer(char b[][3], char dic[][6], int row, int col, int dic_size)
{
	for (int i = 0; i < num_char; ++i) {
		for (int j = 0; j < num_char; ++j) {
			path[i][j] = false;
		}
		path[i][i] = true;
	}

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			mark_path(path, b, b[i][j] - 'A', i - 1, j, row, col);
			mark_path(path, b, b[i][j] - 'A', i - 1, j - 1, row, col);
			mark_path(path, b, b[i][j] - 'A', i - 1, j + 1, row, col);

			mark_path(path, b, b[i][j] - 'A', i, j - 1, row, col);
			mark_path(path, b, b[i][j] - 'A', i, j + 1, row, col);

			mark_path(path, b, b[i][j] - 'A', i + 1, j, row, col);
			mark_path(path, b, b[i][j] - 'A', i + 1, j - 1, row, col);
			mark_path(path, b, b[i][j] - 'A', i + 1, j + 1, row, col);
		}
	}

	for (int i = 0; i < dic_size; ++i) {
		int src = dic[i][0] - 'A';
		int j;

		for (j = 0; dic[i][j] != '\0'; ++j) {
			int dst = dic[i][j] - 'A';
			if (path[src][dst] == false) {
				break;
			}
			src = dst;
		}

		if (dic[i][j] == '\0') {
			cout << dic[i] << endl;
		}
	}
}

int main(void)
{
	get_answer(boggle, dictionary, 3, 3, sizeof(dictionary) / sizeof(dictionary[0]));
}
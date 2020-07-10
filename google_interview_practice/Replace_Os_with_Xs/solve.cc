#include <iostream>
#include <vector>

using namespace std;

const char intermediate = '^';

bool toIntermediate(vector<vector<char> > &matrix, int row, int col) {
	if (row < 0 || col < 0 || row == matrix.size() || col == matrix[0].size()) {
		return false;
	}
	if (matrix[row][col] == 'X' || matrix[row][col] ==intermediate) {
		return true;
	}

	matrix[row][col] = intermediate;

	if (toIntermediate(matrix, row - 1, col) == false ||
	  toIntermediate(matrix, row + 1, col) == false ||
    toIntermediate(matrix, row, col - 1) == false ||
    toIntermediate(matrix, row, col + 1) == false) {
		matrix[row][col] = 'O';
		return false;
	} else {
		return true;
	}
}

void toOriginal(vector<vector<char> > &matrix, int row, int col) {
	if (row < 0 || col < 0 || row == matrix.size() || col == matrix[0].size()) { 
		return;
	}
	char ch = matrix[row][col];

	if (ch  != intermediate) {
		return;
	}
	
	matrix[row][col] = 'O';

	if (ch == intermediate) {
		toOriginal(matrix, row - 1, col);
		toOriginal(matrix, row + 1, col);
		toOriginal(matrix, row, col - 1);
		toOriginal(matrix, row, col + 1);
	}
}

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		vector<vector<char> > matrix;
		int n, m;
		cin >> n >> m; 
		for (int i = 0; i < n; ++i) {
			vector<char> vec;
			for (int j = 0; j < m; ++j) {
				char ch;
				cin >> ch;
				vec.push_back(ch);
			}
			matrix.push_back(vec);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				toIntermediate(matrix, i, j);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] == 'O') {
					matrix[i][j] = intermediate;
					toOriginal(matrix, i, j);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] == intermediate) {
					matrix[i][j] = 'X';
				}
			}
		}
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
				cout << matrix[i][j] << ' ';
      }
    }
		cout << endl;
	}
	return 0;
}



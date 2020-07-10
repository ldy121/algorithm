#include <iostream>
#include <vector>

using namespace std;

void mask(vector<vector<int> > &shape, int row, int col) {
	if (row < 0 || row >= shape.size()) {
		return;
	}

	if (col < 0 || col >= shape[row].size()) {
		return;
	}

	if (shape[row][col] == ‘X’) {
		shape[row][col] = ‘O’;
		mask(shape, row - 1, col);
		mask(shape, row + 1, col);
		mask(shape, row, col - 1);
		mask(shape, row, col + 1);
	}
}


int main() {
	int T;
	for (cin >> T; T > 0; --T ) {
		int N, M, answer = 0;
		vector<vector <int> > shape;

		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			vector<int> vec;
			for (int j = 0; j < M; ++j) {
				char ch;
				cin >> ch;
				vec.push_back(ch);			
			}
			shape.push_back(vec);
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (shape[i][j] == ‘X’) {
					++answer;
					mask(shape, i, j);
				}
			}
		}

		cout << answer << endl;
	}
	return 0;
}



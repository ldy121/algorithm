#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

class point {
	public :
		int m_row;
		int m_col;
		point (int row, int col) : m_row(row), m_col(col) {}
};

bool getAnswer(vector<int> &rows, vector<int> &cols, vector<vector<int> > &map,
		vector<vector<int> > &answer, vector<point> &empty, int idx) {
	if (idx == empty.size()) {
		return true;
	}

	int row = empty[idx].m_row;
	int col = empty[idx].m_col;
	
	for (int i = 1; i <= N; ++i) {
		int j = (1 << i);
    if ((rows[row] & j) > 0) {
			continue;
		}
    if ((cols[col] & j) > 0) {
			continue;
		}
		if ((map[row / 3][col / 3] & j) > 0) {
			continue;
		}
		rows[row] |= j;
		cols[col] |= j;
		map[row / 3][col / 3] |= j;
		answer[row][col] = i;
		if (getAnswer(rows, cols, map, answer, empty, idx + 1)) {
			return true;
		}
		rows[row] &= ~j;
		cols[col] &= ~j;
		map[row / 3][col / 3] &= ~j;
	}


	return false;
}

int main(void) {
	int T;
	for (cin >> T; T > 0; --T) {
		vector<int> rows(N, 0);
		vector<int> cols(N, 0);
		vector<vector<int> > map;
		vector<vector<int> > answer;
		vector<point> empty;

		for (int i = 0; i < 3; ++i) {
			vector<int> vec(3, 0);
			map.push_back(vec);
		}
		for (int i = 0; i < N; ++i) {
			vector<int> vec;
			for (int j = 0; j < N; ++j) {
				int val;
				cin >> val;
				vec.push_back(val);
				if (val > 0) {
					int k = 1 << val;
					rows[i] |= k;
					cols[j] |= k;
					map[i / 3][j / 3] |= k;
				} else {
					empty.push_back(point(i, j));
				}
			}
			answer.push_back(vec);
		}
	  getAnswer(rows, cols, map, answer, empty, 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << answer[i][j] << " ";
			}
		}
	}
	return 0;
}

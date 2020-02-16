#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class point {
	public :
		point(int row, int col) : m_row(row), m_col(col) {}; 
		int m_row;
		int m_col;
};

inline bool check(vector<vector<char> > &boggle, int row, int col, char val) {
	return ((row >= 0) && (col >= 0) && (row < boggle.size()) && 
			(col < boggle[row].size()) && (val == boggle[row][col]));
}

int main(void)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> T; T > 0; --T) {
		int n, m, x;
		vector<string> dictionary;
		vector<vector <char> > boggle;
		vector<string> answer;

		cin >> x;
		for (int i = 0; i < x; ++i) {
			string input;
			cin >> input;
			dictionary.push_back(input);
		}

		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			vector<char> v;
			for (int j = 0; j < m; ++j) {
				char in;
				cin >> in;
				v.push_back(in);
			}
			boggle.push_back(v);
		}

		for (int k = 0; k < x; ++k) {
			string str = dictionary[k];
			queue<point> q;
			int idx = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (boggle[i][j] == str[idx]) {
						q.push(point(i, j));
					}
				}
			}
			while ((++idx < str.length()) && (!q.empty())) {
				for (int size = q.size(); size > 0; --size) {
					int row = q.front().m_row;
					int col = q.front().m_col;
					q.pop();
				
					if (check(boggle, row - 1, col, str[idx])) 	q.push(point(row - 1, col));
					if (check(boggle, row - 1, col - 1, str[idx])) 	q.push(point(row - 1, col - 1));
					if (check(boggle, row - 1, col + 1, str[idx])) 	q.push(point(row - 1, col + 1));
					if (check(boggle, row, col - 1, str[idx])) 	q.push(point(row, col - 1));
					if (check(boggle, row, col + 1, str[idx])) 	q.push(point(row, col + 1));
					if (check(boggle, row + 1, col, str[idx])) 	q.push(point(row + 1, col));
					if (check(boggle, row + 1, col - 1, str[idx])) 	q.push(point(row + 1, col - 1));
					if (check(boggle, row + 1, col + 1, str[idx])) 	q.push(point(row + 1, col + 1));
				}
			}
			if ((idx == str.length()) && (!q.empty())) {
				answer.push_back(str);
			}
		}

		if (!answer.empty()) {
			for (int i = 0; i < answer.size(); ++i) {
				cout << answer[i] << " ";
			}
			cout << endl;
		} else {
			cout << "-1" << endl;
		}
	}

	return 0;
}

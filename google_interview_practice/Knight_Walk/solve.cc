#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int invalid = -1;
	int T;
	for (cin >> T; T > 0; --T) {
		int s1, s2, d1, d2, N, M;
		vector<vector<int> > board;
		queue<pair<int, int> > q;
		cin >> N >> M >> s1 >> s2 >> d1 >> d2;
		for (int i = 0; i < N; ++i) {
			vector<int> vec(M, invalid);
			board.push_back(vec);
		}
		int turn = 0;
		for(q.push(pair<int, int> (s1 - 1, s2 - 1)); !q.empty(); ++turn) {
			for (int size = q.size(); size > 0; --size) {
				int row = q.front().first;
				int col = q.front().second;
				q.pop();

				if (row < 0 || row >= N || col < 0 || col >= M) {
					continue;
				}
				
				if (board[row][col] != invalid) {
					continue;
				}
				board[row][col] = turn;

				q.push(pair<int, int>(row - 2, col - 1));
				q.push(pair<int, int>(row - 2, col + 1));
				q.push(pair<int, int>(row + 2, col - 1));
				q.push(pair<int, int>(row + 2, col + 1));
				q.push(pair<int, int>(row - 1, col - 2));
				q.push(pair<int, int>(row + 1, col - 2));
				q.push(pair<int, int>(row - 1, col + 2));
				q.push(pair<int, int>(row + 1, col + 2));
			}
		}
		cout << board[d1 - 1][d2 - 1] << endl;
	}
	return 0;
}

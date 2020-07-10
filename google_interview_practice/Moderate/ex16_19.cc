#include <vector>
#include <iostream>

using namespace std;

const int water = 0;
const int visit = -1;

int getPondSize(vector<vector<int> > &waters, int row, int col) {
	int ret = 0;
	if (row < 0 || row >= waters.size()) {
		return 0;
	}
	if (col < 0 || col >= waters[row].size()) {
		return 0;
	}
	if (waters[row][col] != water) {
		return 0;
	} else {
		waters[row][col] = visit;
		ret = 1;
	}
	ret += getPondSize(waters, row - 1, col - 1);
	ret += getPondSize(waters, row - 1, col);
	ret += getPondSize(waters, row - 1, col + 1);
	ret += getPondSize(waters, row, col - 1);
	ret += getPondSize(waters, row, col + 1);
	ret += getPondSize(waters, row + 1, col - 1);
	ret += getPondSize(waters, row + 1, col);
	ret += getPondSize(waters, row + 1, col + 1);
	return ret;
}


int main(void) {
	vector<vector <int> > waters;
	waters.push_back(vector<int> {0, 2, 1, 0});
	waters.push_back(vector<int> {0, 1, 0, 1});
	waters.push_back(vector<int> {1, 1, 0, 1});
	waters.push_back(vector<int> {0, 1, 0, 1});
	vector<int> answer;

	for (int i = 0; i < waters.size(); ++i) {
		for (int j = 0; j < waters[i].size(); ++j) {
			if (waters[i][j] == water) {
				answer.push_back(getPondSize(waters, i, j));
			}
		}
	}

	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << ' ';
	}
	cout << endl;
	return 0;
}


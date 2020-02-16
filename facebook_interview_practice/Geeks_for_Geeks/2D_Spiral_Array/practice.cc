#include <vector>
#include <iostream>

using namespace std;

enum direction {
	RIGHT,
	DOWN,
	LEFT,
	UP
};

void get_answer(vector<vector <int > > & map, int row, int col, int size, direction dir, int cnt)
{
	if (map[row][col] == 0) {
		switch(dir) {
		case RIGHT :
			while (col < size && map[row][col] == 0) {
				map[row][col++] = cnt++;
			}
			get_answer(map, row + 1, col - 1, size, DOWN, cnt);
			break;
		case LEFT :
			while (col >= 0 && map[row][col] == 0) {
				map[row][col--] = cnt++;
			}
			get_answer(map, row - 1, col + 1, size, UP, cnt);
			break;
		case UP :
			while (row >= 0 && map[row][col] == 0) {
				map[row--][col] = cnt++;
			}
			get_answer(map, row + 1, col + 1, size, RIGHT, cnt);
			break;
		case DOWN :
			while (row < size && map[row][col] == 0) {
				map[row++][col] = cnt++;
			}
			get_answer(map, row - 1, col - 1, size, LEFT, cnt);
			break;
		}
	}
}

vector<vector <int> > spiral(int n)
{
	vector<vector <int> > answer;

	for (int i = 0; i < n; ++i) {
		vector<int> vec;
		for (int j = 0; j < n; ++j) {
			vec.push_back(0);
		}
		answer.push_back(vec);
	}
	get_answer(answer, 0, 0, n, RIGHT, 1);

	return answer;
}

int main(void)
{
	vector<vector <int> > answer1 = spiral(3);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << answer1[i][j] << " ";
		}
		cout << endl;
	}
	vector<vector <int> > answer2 = spiral(4);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << answer2[i][j] << " ";
		}
		cout << endl;
	}
	vector<vector <int> > answer3 = spiral(8);
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << answer3[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

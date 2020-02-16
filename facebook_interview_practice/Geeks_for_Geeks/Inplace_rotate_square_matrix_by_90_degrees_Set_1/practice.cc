#include <iostream>
#include <vector>

using namespace std;

void get_answer(vector <vector <int> >& square, int N)
{
	for (int n = N - 1, i = 0; n >= 0; --n, ++i) {
		int k = N - i - 1;
		for (int j = 0; j < n; ++j) {
			int tmp = square[i][j];
			square[i][j] = square[N - 1 - j][k];
			square[N - 1 - j][k] = tmp;
		}
	}

	for (int j = 0; j < N / 2; ++j) {
		for (int i = 0; i < N; ++i) {
			int tmp = square[i][j];
			square[i][j] = square[i][N - 1 - j];
			square[i][N - 1 - j] = tmp;
		}
	}

}

void print_result(vector <vector <int> >& square, int N)
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << square[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	int example1[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int example2[4][4] = {
		{1,   2,  3,  4},
		{5,   6,  7,  8},
		{9,  10, 11, 12},
		{13, 14, 15, 16}
	};

	vector < vector <int > > exp1;
	for (int i = 0; i < 3; ++i) {
		vector<int> vec;
		for (int j = 0; j < 3; ++j) {
			vec.push_back(example1[i][j]);
		}
		exp1.push_back(vec);
	}
	vector < vector <int > > exp2;
	for (int i = 0; i < 4; ++i) {
		vector<int> vec;
		for (int j = 0; j < 4; ++j) {
			vec.push_back(example2[i][j]);
		}
		exp2.push_back(vec);
	}

	get_answer(exp1, 3);
	print_result(exp1, 3);
	get_answer(exp2, 4);
	print_result(exp2, 4);
}

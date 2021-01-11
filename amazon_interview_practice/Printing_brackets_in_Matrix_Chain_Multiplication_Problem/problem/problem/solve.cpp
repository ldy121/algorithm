#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class matrix {
	public :
		matrix() {

		}
		int m_row;
		int m_col;
		int m_operations;
};

int solve(int * p, int num)
{
	matrix ** answer;
	int num_of_matrix = num - 1;
	int ret;

	answer = new (matrix *[num_of_matrix]);
	for (int i = 0; i < num_of_matrix; ++i) {
		answer[i] = new (matrix[num_of_matrix]);
		answer[i][i].m_row = p[i];
		answer[i][i].m_col = p[i + 1];
		answer[i][i].m_operations = 0;
	}

	for (int size = 1; size < num_of_matrix; ++size) {
		for (int j = size; j < num_of_matrix; ++j) {
			int i = j - size;
			int min = 1000000000;
			for (int k = i; k < j; ++k) {
				int val = answer[i][k].m_row * answer[i][k].m_col * answer[k + 1][j].m_col +
					answer[i][k].m_operations + answer[k + 1][j].m_operations;
				if (min > val) {
					min = val;
				}
			}
			answer[i][j].m_row = answer[i][i].m_row;
			answer[i][j].m_col = answer[j][j].m_col;
			answer[i][j].m_operations = min;
		}
	}

	ret = answer[0][num_of_matrix - 1].m_operations;

	for (int i = 0; i < num_of_matrix; ++i) {
		delete answer[i];
	}
	cout << ret << endl;
	return ret;
}

struct test {
	int data[5];
	int num;
};

int main(void)
{
	test tests[5] =
	{ {{40, 20, 30, 10, 30}, 5},
	  {{10, 20, 30, 40, 30}, 5},
	  {{10, 20, 30 }, 3} };

	solve(tests[0].data, tests[0].num);
	solve(tests[1].data, tests[1].num);
	solve(tests[2].data, tests[2].num);
}
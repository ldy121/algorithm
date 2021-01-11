#include <iostream>

using namespace std;

const int max_sum = 500;
const int max_n = 100;

long long answer[max_n + 1][max_sum + 1];

void init_answer(void)
{
	for (int i = 0; i <= max_n; ++i) {
		for (int j = 0; j <= max_sum; ++j) {
			answer[i][j] = 0;
		}
	}

	for (int i = 1; i < 10; ++i) {
		answer[1][i] = 1;
	}

	for (int i = 2; i <= max_n; ++i) {
		for (int j = 0; j <= max_sum; ++j) {
			for (int k = 0; k < 10; ++k) {
				if ((j + k) <= max_sum) {
					answer[i][j + k] = answer[i][j + k] + answer[i - 1][j];
				}
			}
		}
	}
}

inline int findCount(int n, int sum)
{
	cout << answer[n][sum] << endl;
	return answer[n][sum];
}

int main() {
	int n = 3;
	int sum = 5;

	init_answer();

	findCount(n, sum);


	return 0;
}
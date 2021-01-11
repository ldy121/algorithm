#include <stdio.h>
#include <iostream>

using namespace std;

#pragma warning(disable : 4996)

int main(void)
{
	int test_case;
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> test_case; test_case > 0; --test_case) {
		int sum = 0;
		int N;
		cin >> N;
		for (int i = 1, j; i < N; ++i) {
			cin >> j;
			sum += j;
		}

		cout << (N * (N + 1)) / 2 - sum << endl;
	}
	
	return 0;
}
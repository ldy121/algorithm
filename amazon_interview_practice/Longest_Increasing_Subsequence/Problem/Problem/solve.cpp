#include <stdio.h>

#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

const int N = 1000;
int A[N];
int answer[N];
int n;

int get_answer(int index)
{
	if (answer[index] == -1) {
		int ans = 1;

		for (int i = index + 1; i < n; ++i) {
			if (A[index] < A[i]) {
				int j = get_answer(i) + 1;
				if (ans < j) {
					ans = j;
				}
			}
		}

		answer[index] = ans;
	}

	return answer[index];
}

int main(void)
{
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int test_case;

	for (cin >> test_case; test_case > 0; --test_case)
	{
		int ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
			answer[i] = -1;
		}

		for (int i = 0; i < n; ++i) {
			int j = get_answer(i);
			if (ans < j) {
				ans = j;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
#include <stdio.h>

#pragma warning(disable : 4996)

#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 10000000;

long long A[MAX_N];
long long S;
long long sum;
int N;

int main(void)
{
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int test_case;

	for (cin >> test_case; test_case > 0; --test_case) {
		queue<int> q;
		int i;

		cin >> N >> S;

		for (i = 0; i < N; ++i) {
			cin >> A[i];
		}

		sum = 0;
		for (i = 0; (i < N); ++i) {
			q.push(i);
			sum += A[i];

			while (sum > S) {
				sum -= A[q.front()];
				q.pop();
			}

			if (sum == S) {
				break;
			}
		}

		if (i == N) {
			cout << "-1" << endl;
		} else {
			cout << (q.front() + 1) << " " << (i + 1) << endl;
		}
	}

	return 0;
}
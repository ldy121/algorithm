#include <stdio.h>
#include <iostream>
#include <queue>

#pragma warning(disable : 4996)

using namespace std;

const int MAX = 1000000;
int A[MAX];
int N;

int solve(int arr[], int n)
{
	int answer = -100000000;
	int j = 0;
	queue<int> q;

	for (int i = 0; i < n; ++i) {
		q.push(arr[i]);
		j += arr[i];
		if (answer < j) answer = j;
		while (j < 0) {
			j -= q.front();
			q.pop();
		}
	}

	return answer;
}

int main(void)
{
	int test_case;
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> test_case; test_case > 0; --test_case) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		cout << solve(A, N) << endl;
	}

	return 0;
}
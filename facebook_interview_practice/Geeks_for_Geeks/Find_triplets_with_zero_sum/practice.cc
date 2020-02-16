#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

bool findTriplets(int arr[], int n)
{
	int sum = 0, idx;
	queue<int> q;


	if (n < 3) return false;

	for (idx = 0; idx < 3; ++idx) {
		sum += arr[idx];
		q.push(arr[idx]);
	}

	while ((sum != 0) && (idx < n)) {
		sum -= q.front();
		q.pop();
		sum += arr[idx];
		q.push(arr[idx]);
		++idx;
	}

	return (sum == 0);
}

int main(void)
{
	int * arr;
	int N, T;
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> T; T > 0; --T) {
		cin >> N;

		arr = new int[N];
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
		}
		
		cout << (findTriplets(arr, N)) << endl;

		delete[] arr;
	}
}

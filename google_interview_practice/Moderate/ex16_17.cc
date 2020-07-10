#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void getAnswer(vector<int> &arr) {
	int start = 0, end = 0;
	int sum = 0;
	int max = arr[0];
	queue<int> q;

	for (int i = 0; i < arr.size(); ++i) {
		while (!q.empty() && sum < 0) {
			sum -= arr[q.front()];
			q.pop();
		}

		sum += arr[i];
		q.push(i);

		if (max < sum) {
			max = sum;
			start = q.front();
			end = i;
		}
	}

	for (int i = start; i <= end; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main(void) {
	int A[] = {2, -8, 3, -2, 4, -10};
	vector<int> arr(A, A + sizeof(A) / sizeof(A[0]));
	getAnswer(arr);
}


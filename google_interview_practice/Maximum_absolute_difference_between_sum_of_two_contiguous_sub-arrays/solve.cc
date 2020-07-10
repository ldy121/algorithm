#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getMax(vector<int> &A, int left, int right) {
	queue<int> q;
	int sum = 0;
	int max = -99999999;
	for (int i = left; i <= right; ++i) {
		q.push(i);
		sum += A[i];
		if (max < sum) {
			max = sum;
		}
		while (sum < 0) {
			int j = q.front();
  		q.pop();
			sum -= A[j];
		}	
	}
	return max;
}

int getMin(vector<int> &A, int left, int right) {
	queue<int> q;
	int sum = 0;
	int min = 9999999;

	for (int i = left; i <= right; ++i) {
		q.push(i);
		sum += A[i];
		if (min > sum) {
			min = sum;
		}
		while (sum > 0) {
			int j = q.front();
			q.pop();
			sum -= A[j];
		}	
	}

	return min;
}

int main() {
	int T;
	
	for (cin >> T; T > 0; --T) {
		int N;
		int answer = -1;
		vector<int> A;

		cin >> N;
		for (int i = 0; i < N; ++i) {
			int val;
			cin >> val;
			A.push_back(val);
		}
		for (int i = 0; i < N - 1; ++i) {
			int minLeft = getMin(A, 0, i);
			int maxLeft = getMax(A, 0, i);
			int minRight = getMin(A, i + 1, N - 1);
			int maxRight = getMax(A, i + 1, N - 1);
			int diff = (maxRight - minLeft > maxLeft - minRight) ?
				(maxRight - minLeft) : (maxLeft - minRight);
			if (answer < diff) {
				answer = diff;
			}
		}		
		cout << answer << endl;
	}
	return 0;
}



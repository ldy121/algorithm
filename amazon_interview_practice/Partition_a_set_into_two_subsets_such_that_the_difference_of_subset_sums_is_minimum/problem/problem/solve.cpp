#include <iostream>
#include <vector>

using namespace std;

int findMin(int arr[], int n)
{
	vector<int> answer(1 << n, 0);
	int ans = 1000000000;

	for (int i = 0; i < answer.size(); ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) > 0) {
				answer[i] += arr[j];
			}
		}
	}

	for (int i = 0; i < answer.size(); ++i) {
		int j = answer[((answer.size() - 1) & (~i))] - answer[i];
		if (j < 0) j *= -1;
		if (ans > j) ans = j;
	}

	return ans;
}

// Driver program to test above function 
int main()
{
	int arr[] = { 3, 1, 4, 2, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The minimum difference between two sets is "
		<< findMin(arr, n);
	return 0;
}
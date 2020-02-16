#include <iostream>
#include <queue>

using namespace std;

int largest_subarray(int arr[], int n, int k)
{
	queue<int> q;
	int sum = 0, max_sum = -99999999;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
		q.push(i);
		if (q.size() >= k) {
			if (max_sum < sum) max_sum = sum;
			while ((k <= q.size()) && (sum < 0)) {
				sum -= arr[q.front()];
				q.pop();
			}
		}
	}

	return max_sum;
}

int main(void)
{
	int arr1[] = {-4, -2, 1, -3};
	int k1 = 2;
	int arr2[] = {1, 1, 1, 1, 1, 1}; 
	int k2 = 2;
	int arr3[] = {1, 2, 3, -10, -3};
	int k3 = 4;

	cout << largest_subarray(arr1, sizeof(arr1) / sizeof(int), k1) << endl;
	cout << largest_subarray(arr2, sizeof(arr2) / sizeof(int), k2) << endl;
	cout << largest_subarray(arr3, sizeof(arr3) / sizeof(int), k3) << endl;
}

#include <iostream>
#include <queue>

using namespace std;

#if 0
void printMaxOfMin(int arr[], int n)
{
	for (int size = 1; size <= n; ++size) {
		int max = 0;
		for (int i = 0; i < n; ++i) {
			int j = i + size;
			int min = 1000000000;
			for (int k = i; k < j; ++k) {
				if (arr[k] < min) {
					min = arr[k];
				}
			}
			if (min > max) {
				max = min;
			}
		}
		cout << max << endl;
	}
}
#else
void printMaxOfMin(int arr[], int n)
{
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		q.push(arr[i]);
	}

	for (int i = 0; i < n; ++i) {
		int max = q.front();
		int prev = q.front();
		q.pop();
		for (int k = q.size(); k > 0; --k) {
			int j = q.front();
			q.pop();
			
			if (j > max)	max = j;
			if (j > prev)	q.push(prev);
			else			q.push(j);
			prev = j;
		}
		cout << max << endl;
	}
}
#endif

// Driver program 
int main()
{
	int arr[] = { 10, 20, 30, 50, 10, 70, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printMaxOfMin(arr, n);
	return 0;
}
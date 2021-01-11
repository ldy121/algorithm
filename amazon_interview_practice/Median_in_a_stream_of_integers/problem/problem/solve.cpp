#include <iostream>
#include <queue>
#include <functional>

using namespace std;

#define ARRAY_SIZE(X) (sizeof(X) / sizeof(X[0]))

void printMedian(int A[], int size)
{
	priority_queue<int, vector<int>, less<int> > max_heap;
//	priority_queue<int, vector<int>, greater<int> > min_heap;

	for (int i = 0; i < size; ++i) {
		max_heap.push(A[i]);
	}

	if ((size % 2) == 0) {
		int i = 0, j = 0;
		for (int k = (size / 2) - 1; k > 0; --k) {
			max_heap.pop();
		}
		i = max_heap.top();
		max_heap.pop();
		j = max_heap.top();
		cout << (i + j) / 2 << endl;
	} else {
		for (int i = size / 2; i > 0; --i) {
			max_heap.pop();
		}
		cout << max_heap.top() << endl;
	}
}

// Driver code 
int main()
{
	int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int size = ARRAY_SIZE(A);

	// In lieu of A, we can also use data read from a stream 
	printMedian(A, size);

	return 0;
}
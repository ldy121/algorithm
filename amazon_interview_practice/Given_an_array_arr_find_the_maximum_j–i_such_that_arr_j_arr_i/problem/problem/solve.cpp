// Driver Code 
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maxIndexDiff(int arr[], int n)
{
	vector<int> vec;
	stack<int> big;
	int answer = -1;
	int min = 0;

	vec.push_back(0);
	for (int i = 1; i < n; ++i) {
		if (arr[i] > arr[min]) {
			big.push(i);
		} else {
			vec.push_back(i);
			min = i;
		}
	}

	for (answer = -1; !big.empty(); big.pop()) {
		int i = big.top();
		int low = 0;
		int high = vec.size();
		for (int middle = (low + high) / 2; low < high; middle = (low + high) / 2) {
			if (arr[vec[middle]] < arr[i]) {
				high = middle;
				break;
			} else {
				low = middle + 1;
			}
		}

		if (answer < (i - vec[high])) {
			for (int j = high; (j >= 0) && (arr[vec[j]] < arr[i]); --j) {
				if (answer < (i - vec[j])) {
					answer = i - vec[j];
				}
			}
		}
	}

	return answer;
}

int main()
{
	int arr1[] = { 9, 2, 3, 4, 5, 6, 7, 8, 18, 0 };
	int arr2[] = { 34, 8, 10, 3, 2, 80, 30, 33, 1 };
	int arr3[] = { 9, 2, 3, 4, 5, 6, 7, 8, 18, 0 };
	int arr4[] = { 1, 2, 3, 4, 5, 6 };
	int arr5[] = { 6, 5, 4, 3, 2, 1 };


	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	int n5 = sizeof(arr5) / sizeof(arr5[0]);

	int maxDiff1 = maxIndexDiff(arr1, n1);
	cout << maxDiff1 << endl;

	int maxDiff2 = maxIndexDiff(arr2, n2);
	cout << maxDiff2 << endl;

	int maxDiff3 = maxIndexDiff(arr3, n3);
	cout << maxDiff3 << endl;

	int maxDiff4 = maxIndexDiff(arr4, n4);
	cout << maxDiff4 << endl;

	int maxDiff5 = maxIndexDiff(arr5, n5);
	cout << maxDiff5 << endl;

	return 0;
}
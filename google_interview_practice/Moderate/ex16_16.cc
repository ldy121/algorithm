#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;

bool comp(int a, int b) {
	return answer[a] < answer[b];
}

void subSort(vector<int> &A) {
	vector<int> arr;
	int min = A.size() + 1;
	int max = -1;
	
	answer.clear();
	for (int i = 0; i < A.size(); ++i) {
		answer.push_back(A[i]);
		arr.push_back(i);
	}

	sort(arr.begin(), arr.end(), comp);
	
	for (int i = 0; i < arr.size(); ++i) {

		if (i != arr[i]) {
			if (max < arr[i]) {
				max = arr[i];
			}
			if (arr[i] < min) {
				min = arr[i];
			}
		}
	}

	cout << min << ", " << max << endl;
}

int main(void) {
	int arr[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
	vector<int> A(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	subSort(A);
	return 0;
}


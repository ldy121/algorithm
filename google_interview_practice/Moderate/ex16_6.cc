#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getAnswer(vector<int> &A, vector<int> &B) {
	int a = 0, b = 0;
	int minDiff;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	minDiff = (A[0] > B[0]) ? (A[0] - B[0]) : (B[0] - A[0]);

	for (int i = 0, j = 0; i < A.size() && j < B.size();) {
		int diff = (A[i] > B[j]) ? A[i] - B[j] : B[j] - A[i];
		if (minDiff > diff) {
			a = i;
			b = j;
			minDiff = diff;
		}

		if (A[i] > B[j]) {
			++j;
		} else {
			++i;
		}
	}

	cout << A[a] << ", " << B[b] << endl;
}

int main(void) {
	int arrA[] = {1, 3, 15, 11, 2};
	int arrB[] = {23, 127, 235, 19, 8};
	vector<int> A(arrA, arrA + (sizeof(arrA) / sizeof(arrA[0])));
  vector<int> B(arrB, arrB + (sizeof(arrB) / sizeof(arrB[0])));
	
	getAnswer(A, B);
	return 0;
}


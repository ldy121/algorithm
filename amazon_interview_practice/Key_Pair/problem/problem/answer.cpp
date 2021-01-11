#include <stdio.h>

#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

const int MAX_N = 10000;
int N, X;
int A[MAX_N];

void qsort(int left, int right)
{
	if (left < right) {
		int j, k, i;

		for (i = left + 1, j = left; i <= right; ++i) {
			if (A[i] < A[left]) {
				++j;
				k = A[j];
				A[j] = A[i];
				A[i] = k;
			}
		}

		k = A[left];
		A[left] = A[j];
		A[j] = k;

		qsort(left, j - 1);
		qsort(j + 1, right);
	}
}

bool find(int low, int high, int num)
{
	int mid;

	for (mid = (low + high) / 2; low < high; mid = (low + high) / 2) {
		if (A[mid] < num) low = mid + 1;
		else if (A[mid] > num) high = mid;
		else return true;
	}

	return false;
}

int main(void)
{
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int test_case;

	for (cin >> test_case; test_case > 0; --test_case) {
		bool answer = false;

		cin >> N >> X;
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		
		qsort(0, N - 1);

		for (int i = 0; (A[i] < X) && (i < N); ++i) {
			if (A[i] < (X - A[i])) {
				answer = find(i, N, X - A[i]);
			} else {
				answer = find(0, i, X - A[i]);
			}

			if (answer) break;
		}

		cout << ((answer) ? ("YES") : ("NO")) << endl;
	}

	return 0;
}
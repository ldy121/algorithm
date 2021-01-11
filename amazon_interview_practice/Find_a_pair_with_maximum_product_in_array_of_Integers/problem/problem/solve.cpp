#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void qsort(int * arr, int left, int right)
{
	int i, j, k;
	if (left < right) {
		for (j = left, i = left + 1; i <= right; ++i) {
			if (arr[i] < arr[left]) {
				++j;
				k = arr[i];
				arr[i] = arr[j];
				arr[j] = k;
			}
		}

		k = arr[left];
		arr[left] = arr[j];
		arr[j] = k;

		qsort(arr, left, j - 1);
		qsort(arr, j + 1, right);
	}
}

int get_answer(int * num, int size)
{
	int i, j;

	qsort(num, 0, size - 1);

	i = num[size - 1] * num[size - 2];
	j = num[0] * num[1];

	if (i > j) {
		cout << num[size - 2] << ", " << num[size - 1] << endl;
	} else {
		cout << num[0] << ", " << num[1] << endl;
	}

	return 0;
}

int main(void)
{
	int problem1[] = { 1, 4, 3, 6, 7, 0 };
	int problem2[] = { -1, -3, -4, 2, 0, -5 };

	get_answer(problem1, 6);
	get_answer(problem2, 6);
}
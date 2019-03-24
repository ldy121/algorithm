#include <stdio.h>

#define INPUT_SIZE (100000)
#define invalid (-1)

int input[INPUT_SIZE];
int answer[INPUT_SIZE];

void qsort(int arr[], int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (arr[left] > arr[i]) {
				++j;
				k = arr[j];
				arr[j] = arr[i];
				arr[i] = k;
			}
		}

		k = arr[j];
		arr[j] = arr[left];
		arr[left] = k;

		qsort(arr, left, j - 1);
		qsort(arr, j + 1, right);
	}
}

int find_less_equal(int arr[], int val, int length)
{
	int mid, left, right;

	for (left = 0, right = length; left < right;) {
		mid = (left + right) / 2;
		if (arr[mid] == val) {
			return mid;
		} else if (arr[mid] < val) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	return (right == length) ? (length - 1) : (right);
}

int get_answer(int arr[], int index)
{
	int i, j, longest;
	if (answer[index] == invalid) {
		for (i = find_less_equal(arr, arr[index] / 2, index), longest = 1; i >= 0; --i) {
			if ((arr[index] % arr[i]) == 0)	 {
				j = get_answer(arr, i);
				if ((j + 1) > longest) {
					longest = j + 1;
				}
			}
		}
		answer[index] = longest;
	}
	return answer[index];
}

int main(void)
{
	int ans;
	int N, t, T;
	int i;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (t = 1; t <= T; ++t) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &input[i]);
			answer[i] = invalid;
		}

		qsort(input, 0, N - 1);

		for (i = N - 1, ans = 0; i >= 0; --i) {
			if (answer[i] == invalid) {
				get_answer(input, i);
			}
			if (ans < answer[i]) {
				ans = answer[i];
			}

		}

		printf ("#%d %d\n", t, ans);
	}

	return 0;
}

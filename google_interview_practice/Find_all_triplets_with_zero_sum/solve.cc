#include <iostream>

using namespace std;

void qsort(int arr[], int left, int right)
{
  if (left < right) {
    int i, j, k;
    for (i = left + 1, j = left; i <= right; ++i) {
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

bool findTriplets(int arr[], int n) {
	qsort(arr, 0, n - 1);
	for (int mid = 1; mid + 1 < n; ++mid) {
		for (int left = mid - 1, right = mid + 1; left >= 0 && right < n;) {
			int val = arr[mid] + arr[left] + arr[right];
			if (val == 0) {
				return true;
			} else if (val > 0) {
				--left;
			} else {
				++right;
			}
		}
	}

	return false;
}

int main(void) {
//	int input[] = {0, -1, 2, -3, 1};
	int input[] = {97, -27, 2, -34, 61, -39};
  cout << findTriplets(input, sizeof(input) / sizeof(int)) << endl;
	return 0;
}

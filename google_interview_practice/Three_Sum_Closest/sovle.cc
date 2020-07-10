#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> arr, int target) {
	int answer = arr[0] + arr[1] + arr[2];
	int minGap = (target > answer) ? (target - answer) : (answer - target);

	sort(arr.begin(), arr.end());

	for (int mid = 1; mid < arr.size(); ++mid) {
		for (int left = mid - 1, right = mid + 1; left >= 0 && right < arr.size();) {
			int val = arr[mid] + arr[left] + arr[right];
			if (target < val) {
				if (minGap >= val - target) {
					minGap = val - target;
					answer = val;
				}
				--left;
			} else if (target > val) {
				if (minGap > target - val) {
					minGap = target - val;
					answer = val;
				}
				++right;
			} else {
				return val;
			}
		}
	}
  return answer;
}

int main(void)
{
	int A[] = {1, 7, -21, -30, -2, 83, 85, 66, 10, 9, -50, 14, 11, 89, 51, 100, -33, 17, 97, 36, -4, 73, -9, 5, -44, 73, 82, 51, 54};
  vector<int> vec(A, A + sizeof(A) / sizeof(A[0]));
	cout << threeSumClosest(vec, 39) << endl;
	return 0;
}

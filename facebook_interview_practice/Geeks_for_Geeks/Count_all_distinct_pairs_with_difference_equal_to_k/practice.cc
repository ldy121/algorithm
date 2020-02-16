#include <iostream>
#include <unordered_set>

using namespace std;

void get_pair(int arr[], int n, int k)
{
	unordered_set<int> difference;

	for (int i = 0; i < n; ++i) {
		difference.insert(arr[i]);
	}

	for (int i = 0; i < n; ++i) {
		if (difference.find(arr[i] + k) != difference.end()) {
			cout << "{" << arr[i] << ", " << arr[i] + k << "} ";
		}
	}
	cout << endl;
}

int main(void)
{
	int arr1[] = {1, 5, 3, 4, 2};
	int k1 = 3;
	int arr2[] = {8, 12, 16, 4, 0, 20};
	int k2 = 4;

	get_pair(arr1, sizeof(arr1) / sizeof(int), k1);
	get_pair(arr2, sizeof(arr2) / sizeof(int), k2);

	return 0;
}

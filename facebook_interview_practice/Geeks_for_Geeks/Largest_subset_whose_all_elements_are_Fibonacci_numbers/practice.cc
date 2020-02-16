#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> get_subset(set<int>& fib_number, vector<int>& fib_mem, int arr[], int n)
{
	vector<int> ret;

	for (int i = 0; i < n; ++i) {
		while (arr[i] > fib_mem[fib_number.size() - 1]) {
			int val = fib_mem[fib_mem.size() - 1] + fib_mem[fib_mem.size() - 2];
			fib_mem.push_back(val);
			fib_number.insert(val);
		}

		if (fib_number.find(arr[i]) != fib_number.end()) {
			ret.push_back(arr[i]);
		}
	}

	return ret;
}

int main(void)
{
	vector<int> fib_mem;
	set<int> fib_number;

	int arr1[] = {1, 4, 3, 9, 10, 13, 7};
	int arr2[] = {0, 2, 8, 5, 2, 1, 4, 13, 23};

	fib_mem.push_back(0);
	fib_mem.push_back(1);
	fib_number.insert(0);
	fib_number.insert(1);

	vector<int> ans1 = get_subset(fib_number, fib_mem, arr1, sizeof(arr1) / sizeof(int));
	for (int i = 0; i < ans1.size(); ++i) {
		cout << ans1[i] << " ";
	}
	cout << endl;
	vector<int> ans2 = get_subset(fib_number, fib_mem, arr2, sizeof(arr2) / sizeof(int));
	for (int i = 0; i < ans2.size(); ++i) {
		cout << ans2[i] << " ";
	}
	cout << endl;
}

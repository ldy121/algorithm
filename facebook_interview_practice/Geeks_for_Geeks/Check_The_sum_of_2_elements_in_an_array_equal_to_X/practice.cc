#include <unordered_map>
#include <iostream>

using namespace std;

bool get_answer(int arr[], int N, int sum)
{
	unordered_map<int, int> hash;

	for (int i = 0; i < N; ++i) {
		if (hash.find(arr[i]) == hash.end()) {
			hash[arr[i]] = 1;
		} else {
			hash[arr[i]]++;
		}
	}

	for (int i = 0; i < N; ++i) {
		int val = sum - arr[i];
		--hash[arr[i]];
		if ((hash.find(val) != hash.end()) && (hash[val] > 0)) {
			return true;
		}
		++hash[arr[i]];
	}
	return false;
}

int main(void)
{
	int example1[] = {1, 23, 23, 512, 23, 30};
	int example2[] = {989, 231, 525, 123, 2, 300};

	cout << get_answer(example1, sizeof(example1) / sizeof(int), example1[2] + example1[4]) << endl;
	cout << get_answer(example1, sizeof(example1) / sizeof(int), example1[2] + 9898) << endl;
}

// Driver program to test above functions 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std;

int strcmp(string &a, string &b)
{
	int i;

	for (i = 0; (i < a.size()) && (i < b.size()); ++i) {
		if (a[i] < b[i]) {
			return -1;
		} else if (a[i] > b[i]) {
			return 1;
		}
	}

	if (i == a.size()) {
		if (a[0] > b[i]) return 1;
		else			 return -1;
	} else {
		if (a[i] > b[0]) return 1;
		else			 return -1;
	}
}

void qsort(vector<string>& str, vector<int>& vec, int left, int right)
{
	if (left < right) {
		int i, j, k;

		for (i = left + 1, j = left; i <= right; ++i) {
			if (strcmp(str[vec[left]], str[vec[i]]) < 0) {
				++j;
				k = vec[j];
				vec[j] = vec[i];
				vec[i] = k;
			}
		}

		k = vec[j];
		vec[j] = vec[left];
		vec[left] = k;

		qsort(str, vec, left, j - 1);
		qsort(str, vec, j + 1, right);
	}
}

void printLargest(vector<string>& arr)
{
	vector<int> vec(arr.size());

	for (int i = 0; i < vec.size(); ++i) {
		vec[i] = i;
	}

	qsort(arr, vec, 0, vec.size() - 1);

	for (int i = 0; i < vec.size(); ++i) {
		cout << arr[vec[i]];
	}
	cout << endl;
}

int main()
{
	vector<string> arr;

	//output should be 6054854654 
	arr.push_back("54");
	arr.push_back("546");
	arr.push_back("548");
	arr.push_back("60");
	printLargest(arr);

	return 0;
}
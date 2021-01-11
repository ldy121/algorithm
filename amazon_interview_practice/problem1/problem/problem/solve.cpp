#include <iostream>

using namespace std;

#pragma warning(disable : 4996)

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION 
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include <unordered_map>

const int finish_before = 30;

vector<int> IDsOfSongs(int rideDuration, vector<int> songDurations)
{
	int available = rideDuration - finish_before;
	vector<int> ret;
	unordered_multimap<int, int> hash;
	bool found = false;
	int first, second;

	for (int i = 0; i < songDurations.size(); ++i) {
		hash.insert(pair<int, int>(songDurations[i], i));
	}

	for (int i = 0; i < songDurations.size(); ++i) {
		if (hash.find(available - songDurations[i]) != hash.end()) {
			int j;
			for (unordered_multimap<int, int>::iterator iter = hash.find(available - songDurations[i]);
				iter != hash.end(); ++iter) {
				if (iter->second != i) {
					j = iter->second;
					break;
				}
			}

			int tmp1 = i;
			int tmp2 = j;

			if (songDurations[tmp1] < songDurations[tmp2]) {
				int  k = tmp2;
				tmp2 = tmp1;
				tmp2 = k;
			}

			if ((found == false) || (songDurations[first] < songDurations[tmp1])) {
				first = tmp1;
				second = tmp2;
			}
			found = true;
		}
	}

	if (first > second) {
		int k = first;
		first = second;
		second = k;
	}

	ret.push_back(first);
	ret.push_back(second);

	return ret;
}

// FUNCTION SIGNATURE ENDS


// FUNCTION SIGNATURE ENDS

int main(void)
{
	//int arr[] = {1, 10, 25, 35, 60};
	//int arr[] = { 100, 180, 40, 120, 10 };
	int arr[] = { 20, 70, 90, 30, 60, 110 };
	vector<int> v;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		v.push_back(arr[i]);
	}

	//vector<int> ret = IDsOfSongs(250, v);
	vector<int> ret = IDsOfSongs(110, v);
	cout << ret[0] << " " << ret[1] << endl;

	return 0;
}

#if 0
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION 
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

const int finish_before = 30;

struct PAIR {
	int first;
	int second;
};

vector<int> IDsOfSongs(int rideDuration, vector<int> songDurations)
{
	int first, second, max = -1;
	int available = rideDuration - finish_before;
	vector<int> ret;

	for (int i = 0; i < songDurations.size(); ++i) {
		for (int j = i + 1; j < songDurations.size(); ++j) {
			int k = songDurations[i] + songDurations[j];
			if ((k <= available) && (k > max)) {
				first = i;
				second = j;
				max = k;
			}

		}
	}

	ret.push_back(first);
	ret.push_back(second);
	return ret;
}

// FUNCTION SIGNATURE ENDS
#endif

#if 0
struct PAIR {
	int first;
	int second;
};

void sort(vector<int>& songs, vector<int>& arr, int left, int right)
{
	if (left < right) {
		int i, j, k;
		for (i = left + 1, j = left; i <= right; ++i) {
			if (songs[arr[i]] < songs[arr[left]]) {
				++j;

				k = arr[i];
				arr[i] = arr[j];
				arr[j] = k;
			}
		}

		k = arr[left];
		arr[left] = arr[j];
		arr[j] = k;

		qsort(songs, arr, left, j - 1);
		qsort(songs, arr, j + 1, right);
	}
}

vector<int> IDsOfSongs(int rideDuration, vector<int> songDurations)
{
	int first, second, max = -1;
	int available = rideDuration - finish_before;
	vector<int> arr;
	vector<int> ret;

	for (int i = 0; i < songDurations.size(); ++i) {
		arr.push_back(i);
	}

	sort(songDurations, arr, 0, songDurations.size() - 1);

	for (int i = 0; i < arr.size(); ++i) {
		int idx = arr[i];
		int val = available - songDurations[idx];

		int low = 0;
		int high = arr.size();

		for (int middle = (low + high) / 2; low <= high; middle = (low + high) / 2) {
			int k = songDurations[arr[middle]];

		}
	}

	ret.push_back(first);
	ret.push_back(second);
	return ret;
}

#endif
#include <cstdio>

#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

#pragma warning(disable : 4996)

int main(void)
{
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int test_case;

	for (cin >> test_case; test_case > 0; --test_case) {
		unordered_map<int, int> count_map;
		int N;
		bool is_major = false;
		cin >> N;

		for (int _ = 0; _ < N; ++_) {
			int i;
			cin >> i;
			if (count_map.find(i) == count_map.end()) {
				count_map[i] = 0;
			}
			++count_map[i];
		}

		for (unordered_map<int, int>::iterator iter = count_map.begin(); iter != count_map.end(); ++iter) {
			if (iter->second > (N / 2)) {
				cout << iter->first << endl;
				is_major = true;
			}
		}

		if (is_major == false) cout << "-1" << endl;
	}

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	int N;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> N; N > 0; --N) {
		string s1, s2;
		vector<int> result(103, 0);

		cin >> s1 >> s2;

		for (int i = s1.length() - 1, carry_idx = 0; i >= 0; --i, ++carry_idx) {
			for (int j = s2.length() - 1, k = carry_idx; j >= 0; --j, ++k) {
				int val = (s1[i] - '0') * (s2[j] - '0');
				result[k] 	= result[k] + (val % 10);
				result[k + 1]	= result[k + 1] + (val / 10);
			}
		}

		int start_idx;
		for (int i = s1.length() * s2.length() + 1; i >= 0; --i) {
			if (result[i] > 0) {
				start_idx = i;
				break;
			}
		}

		for (int i = start_idx; i >= 0; --i) {
			cout << result[i];
		}

		cout << endl;
	}

	return 0;
}

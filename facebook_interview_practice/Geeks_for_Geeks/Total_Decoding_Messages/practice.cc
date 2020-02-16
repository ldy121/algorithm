#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int get_answer(string &str, vector<int> &answer, int idx)
{
	if (idx == str.length()) {
		return 1;
	} else if (answer[idx] == -1) {
		answer[idx] = get_answer(str, answer, idx + 1);
		if ((idx + 1) < str.length()) {
			int val = (str[idx] - '0') * 10 + (str[idx + 1] - '0');
			if (val <= 26) {
				answer[idx] += get_answer(str, answer, idx + 2);
			}
		}
	}

	return answer[idx];
}

int main(void)
{
	int T, N;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> T; T > 0; --T) {
		string str;
		cin >> N >> str;

		vector<int> vec(N, -1);
		cout << get_answer(str, vec, 0) << endl;
	}
}

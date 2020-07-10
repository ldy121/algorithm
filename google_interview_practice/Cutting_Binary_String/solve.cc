#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

const int invalid = 99999999;

unordered_map<int64_t, bool> table;

int getAnswer(vector<int> &answer, string &str, int idx) {
	if (str.length() == idx) {
		return 0;
	}

	if (answer[idx] != invalid) {
		return answer[idx];
	}

	if (str[idx] == ‘0’) {
		answer[idx] = -1;
		return answer[idx];
	}

	int64_t val = 0;
	int ans= invalid;
	for (int i = idx; i < str.length(); ++i) {
		val = (str[i] == ‘1’) ? (val << 1) | 0x1 : (val << 1);
		if (table.find(val) != table.end()) {
			int ret = getAnswer(answer, str, i + 1);
			if (ret > 0 && ans > 1 + ret) {
				ans = 1 + ret;
			}
		}
	}

	if (table.find(val) != table.end()) {
		ans = 1;
	}
	
	if (ans  == invalid) {
		ans = -1;
	}

	answer[idx] = ans ;
	return answer[idx];
}
int main(void) {
	
	int64_t power = 1;
	int T;
	for (int i = 0; i < 20; ++i) {
		table[power] = true;
		power *= 5;
	}

	for (cin >> T; T > 0; --T) {
		string str;
		vector answer(str.size(), invalid);

		cin >> str;
		cout << getAnswer(answer, str, 0) << endl;
	}
}


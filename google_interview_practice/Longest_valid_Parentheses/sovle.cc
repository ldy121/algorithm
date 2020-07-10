#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getAnswer(string &str) {
	stack<int> sp;
	const char valid = '^';
	int answer = 0;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(') {
			sp.push(i);
		} else if (!sp.empty()) {
			int idx = sp.top();
			sp.pop();
			str[idx] = valid;
			str[i] = valid;
		}
	}

	for (int i = 0; i < str.length(); ++i) {
		int j;
		for (j = i; j < str.length(); ++j) {
			if (str[j] != valid) {
				break;
			}
			if (answer < j - i + 1) {
				answer = j - i + 1;
			}
		}
		i = j;
	}

	return answer;
}


int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		string str;
		cin >> str;
		cout << getAnswer(str) << endl;
	}
	return 0;
}

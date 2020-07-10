#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		string str;
		stack<int> sp;
		int min = 1;

		cin >> str;
		vector<int> answer(str.size() + 1, 0);
		
		sp.push(0);

		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == 'I') {
				while (!sp.empty()) {
					answer[sp.top()] = min++;
					sp.pop();
				}
			}
			sp.push(i + 1);
		}
		while (!sp.empty()) {
			answer[sp.top()] = min++;
			sp.pop();
		}
		for (int i = 0; i < answer.size(); ++i) {
			cout << answer[i];
		}
		cout << endl;
	}
	return 0;

}

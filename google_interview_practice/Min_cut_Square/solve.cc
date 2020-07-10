#include <iostream>
#include <unordered_map>

using namespace std;
int getAnswer(unordered_map<int, unordered_map<int, int> > &answer, int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (answer.find(a) != answer.end() && answer[a].find(b) != answer[a].end()) {
		return answer[a][b];
	}

	if (answer.find(a) == answer.end()) {
		answer[a] = unordered_map<int, int>();
	}

	if (a == b) {
		answer[a][b] = 1;
	} else if (b == 1) {
		answer[a][b] = a;
	} else {
		int min = 99999999;
		for (int i = 1; i <= b; ++i) {
			int val = getAnswer(answer, i, b) + getAnswer(answer, a - i, b);
			if (val < min) {
				min = val;
			}
		}
		answer[a][b] = min;
	}

	return answer[a][b];
}
int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		int A, B;
		unordered_map<int, unordered_map<int, int> > answer;
		cin >> A >> B;
		cout << getAnswer(answer, A, B) << endl;
	}
	return 0;
}


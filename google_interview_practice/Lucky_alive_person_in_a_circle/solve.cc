#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		int N;
		queue<int> q;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			q.push(i);
		}

		while (q.size() > 1) {
			int val = q.front();
			q.pop();
			q.pop();
			q.push(val);
		}

		cout << q.front() << endl;
	}
	return 0;
}

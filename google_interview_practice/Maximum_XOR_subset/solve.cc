#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

int main() {
int T;
	for (cin >> T; T > 0; --T) {
		int N, answer = 0;
		unordered_map<int, int> hash;
		queue<int> q;
		vector<int> vec;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int val;
			cin >> val;
			hash[1 << i] = val;
			q.push(1 << i);
			vec.push_back(val);
			if (answer < val) {
				answer = val;
			}
		}
		while (!q.empty()) {
			int key = q.front();
			int val = hash[key];
			q.pop();
			for (int i = 0; i < N; ++i) {
				if (key & (1 << i)) {
					continue;
				}
				if (hash.find(key | (1 << i)) != hash.end()) {
					continue;
				}
				if ((val ^ vec[i]) > val) {
					int newKey = key | (1 << i);
					hash[newKey] = val ^ vec[i];
					q.push(newKey);
				}
			}
			if (answer < val) {
				answer = val;
			}
		}
		cout << answer << endl;
	}
  return 0;
}

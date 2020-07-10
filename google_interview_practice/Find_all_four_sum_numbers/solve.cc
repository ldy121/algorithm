#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

void getAnswer(vector<int> &key, unordered_map<int, int> &hash, 
	vector<vector <int> > &answer, vector <int> &ans, int idx, int k, int count) {
	if (count == 4) {
		if (k == 0) {
			answer.push_back(ans);
		}
		return;
	}
	for (int i = idx; i < key.size(); ++i) {
		if (hash[key[i]] == 0) {
			continue;
		}
		if (k < key[i]) {
			break;
		}
		--hash[key[i]];
		ans.push_back(key[i]);
		getAnswer(key, hash, answer, ans, i, k - key[i], count + 1);
		ans.pop_back();
		++hash[key[i]];
	}
}

int main() {
	int T;

	for (cin >> T; T > 0; --T) {
		int N, K;
		vector<int> A;
		vector<int> key;
		unordered_map<int, int> hash;
		vector<vector <int> > answer;
		vector <int>  ans;

		cin >> N >> K;
		for (int i = 0; i < N; ++i) {
			int val;
			cin >> val;
			A.push_back(val);
			if (hash.find(val) == hash.end()) {
				hash[val] = 0;
				key.push_back(val);
			}
			hash[val]++;
		}

		sort(key.begin(), key.end());

		for (int i = 0; i < key.size(); ++i) {
			if (K < key[i]) {
				break;
			} else {
				getAnswer(key, hash, answer, ans, i, K, 0);	
			}
		}

		for (int i = 0; i < answer.size(); ++i) {
			for (int j = 0; j < answer[i].size(); ++j) {
				cout << answer[i][j] << ' ';
			}
			cout << '$';
		}
		cout << endl;
	}
	return 0;
}



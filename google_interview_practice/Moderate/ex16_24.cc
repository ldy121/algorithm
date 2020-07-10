#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int PairWithSums(vector<int> &a, int sum) {
	unordered_map<int, int> hash;
	int answer = 0;

	for (int i = 0; i < a.size(); ++i) {
		if (hash.find(a[i]) == hash.end()) {
			hash[a[i]] = 0;		
		}
		++hash[a[i]];
	}

	for (int i = 0; i < a.size(); ++i) {
		if (hash.find (sum - a[i]) != hash.end()) {
			int val = (sum - a[i] == a[i]) ?
			    hash[a[i]] * (hash[a[i]] - 1) / 2 : hash[a[i]] * hash[sum - a[i]];
    		answer += val;
			hash[a[i]] = 0;
			hash[sum - a[i]] = 0;
		}
	}

	return answer;
}


int main() {
	int T;
	for (cin >> T; T > 0; --T) {
        vector<int> a;
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            a.push_back(val);
        }
	    cout << PairWithSums(a, K) << endl;
	}
	return 0;
}

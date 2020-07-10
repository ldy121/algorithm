#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> A;

bool comp(int a, int b) {
	return (A[a] < A[b]) || (A[a] == A[b] && a < b);
}

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		int N. answer = 0;
		vector<int> vec;
		priority_queue<int, vector<int>, greater <int> > q;
		
		
		A.clear();
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int val;
			cin >> val;
			A.push_back(val);
			vec.push_back(i);
		}

		sort(vec.begin(), vec.end(), comp);
		q.push(vec[0]);
		for (int i = 1; i < vec.size(); ++i) {
			int dist = vec[i] - q.front();
			if (answer < dist) {
				answer = dist;
			}
    } 
    cout << answer << endl;
	}
	return 0;
}


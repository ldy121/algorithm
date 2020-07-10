#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int, vector<int>, less<int> > maxHeap;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (minHeap.size() == maxHeap.size()) {
			minHeap.push(x);
            int val = minHeap.top();
            minHeap.pop();
			maxHeap.push(val);            

			cout << maxHeap.top() << endl;
		} else {
		    maxHeap.push(x);
		    int val = maxHeap.top();
		    maxHeap.pop();
            minHeap.push(val);

			cout << (minHeap.top() + maxHeap.top()) / 2 << endl;
		}
	}

	return 0;
}



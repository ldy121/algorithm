#include <queue>
#include <iostream>
#include <stdio.h>

using namespace std;

void get_answer(void)
{
	int N;
	priority_queue<int, vector<int>, less<int> > max_heap; 
	priority_queue<int, vector<int>, greater<int> > min_heap;

	for (cin >> N; N > 0; --N) {
		int input;
		cin >> input;

		if (max_heap.size() > min_heap.size()) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}

		if ((!min_heap.empty()) && (min_heap.top() < input)) {
			max_heap.push(min_heap.top());
			min_heap.pop();
			min_heap.push(input);
		} else {
			max_heap.push(input);
		}

		if (min_heap.size() == max_heap.size()) {
			cout << (min_heap.top() + max_heap.top()) / 2 << endl;
		} else {
			cout << max_heap.top() << endl;
		}
	}
}

int main(void)
{
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	get_answer();
}

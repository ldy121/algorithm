// Driver program to test above functions 
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int minCost(int len[], int size)
{
	int answer;
	priority_queue< int, vector<int>, greater<int> > q;
	for (int i = 0; i < size; ++i) {
		q.push(len[i]);
	}

	for (answer = 0; (q.size() > 1);) {
		int i = q.top();
		q.pop();
		int j = q.top();
		q.pop();
		answer += (i + j);
		q.push(i + j);
	}

	return answer;
}


int main()
{
	int len[] = { 4, 3, 2, 6 };
	int size = sizeof(len) / sizeof(len[0]);
	cout << "Total cost for connecting ropes is " << minCost(len, size);
	return 0;
}
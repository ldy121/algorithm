// Driver Code  
#include <iostream>
#include <stack>

using namespace std;

const int V = 5;

bool get_answer(bool visit[V], bool graph[][V], stack<int> &answer, int index, int size)
{
	visit[index] = true;

	if (size == V) {
		if (graph[index][0] == true) {
			answer.push(index);
			return true;
		}
	} else {
		for (int i = 0; i < V; ++i) {
			if ((graph[index][i] == true) && (visit[i] == false)) {
				if (get_answer(visit, graph, answer, i, size + 1)) {
					answer.push(index);
					return true;
				}
			}
		}
	}

	visit[index] = false;
	return false;
}

void hamCycle(bool graph[][V])
{
	bool visit[V];
	stack<int> answer;

	for (int i = 0; i < V; ++i) {
		visit[i] = false;
	}

	if (get_answer(visit, graph, answer, 0, 1)) {
		while (!answer.empty()) {
			int i = answer.top();
			answer.pop();
			cout << i << " ";
		}
		cout << "0" << endl;
	} else {
		cout << "Solution does not exist" << endl;
	}
}

int main()
{
	/* Let us create the following graph
	(0)--(1)--(2)
	| / \ |
	| / \ |
	| / \ |
	(3)-------(4) */
	bool graph1[V][V] = { { 0, 1, 0, 1, 0 },
	{ 1, 0, 1, 1, 1 },
	{ 0, 1, 0, 0, 1 },
	{ 1, 1, 0, 0, 1 },
	{ 0, 1, 1, 1, 0 } };

	// Print the solution  
	hamCycle(graph1);

	/* Let us create the following graph
	(0)--(1)--(2)
	| / \ |
	| / \ |
	| / \ |
	(3) (4) */
	bool graph2[V][V] = { { 0, 1, 0, 1, 0 },
	{ 1, 0, 1, 1, 1 },
	{ 0, 1, 0, 0, 1 },
	{ 1, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 0 } };

	// Print the solution  
	hamCycle(graph2);

	return 0;
}
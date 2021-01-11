#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

void make_graph(vector<vector<bool > > &graph, vector<string> vec, int index)
{
	vector<string> v;

	if (vec[0].length() > (index + 1)) {
		v.push_back(vec[0]);
	}

	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i - 1][index] != vec[i][index]) {
			graph[vec[i - 1][index] - 'a'][vec[i][index] - 'a'] = true;
			if (v.size() > 0) {
				make_graph(graph, v, index + 1);
			}
			v.clear();
		}
		if (vec[i].length() > (index + 1)) {
			v.push_back(vec[i]);
		}
	}

	if (v.size() > 0) {
		make_graph(graph, v, index + 1);
	}
}

bool find_path(vector<vector <bool> >&graph, vector<bool>&visit, stack<int> &answer, int index, int count)
{
	if (count == 0) {
		answer.push(index);
		return true;
	} else {
		visit[index] = true;
		for (int i = 0; i < visit.size(); ++i) {
			if (graph[index][i] && (visit[i] == false)) {
				if (find_path(graph, visit, answer, i, count - 1)) {
					answer.push(index);
					return true;
				}
			}
		}
		visit[index] = false;
	}
	return false;
}

// Driver program to test above functions 
void printOrder(string words[], int n, int alpha)
{
	vector<vector<bool> > graph(alpha, vector<bool>(alpha, false));
	vector<bool> visit(alpha, false);
	stack<int> answer;
	vector<string> vec;
	int i, j;

	for (i = 0; i < n; ++i) {
		vec.push_back(words[i]);
	}

	make_graph(graph, vec, 0);

	for (i = 0; i < alpha; ++i) {
		int k = 0;
		for (j = 0; j < alpha; ++j) {
			k += graph[j][i];
		}
		if (k == 0) {
			break;
		}
	}

	find_path(graph, visit, answer, i, alpha - 1);

	while (answer.size() > 0) {
		i = answer.top();
		answer.pop();
		cout << static_cast<char> ('a' + i);
		if (!answer.empty()) cout << " -> ";
	}
	cout << endl;
}

int main()
{
//	string words[] = { "caa", "aaa", "aab" };
	string words[] = { "baa", "abcd", "abca", "cab", "cad" };

//	printOrder(words, 3, 3);
	printOrder(words, 5, 4);
	return 0;
}
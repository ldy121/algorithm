#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int FindMaximumDepth(string str) {
	stack<int> sp;
	int answer = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(') {
			sp.push(i);
		} else if (str[i] == ')') {
			if (sp.empty()) {
				return -1;
			} else {
				sp.pop();
			}
		}

		if (answer < sp.size()) {
			answer = sp.size();
		}
	}
	return (sp.empty()) ? answer : -1;
}

int main(void) {
	cout << FindMaximumDepth(string("( ((X)) (((Y))) )")) << endl;
	cout << FindMaximumDepth(string("( a(b) (c) (d(e(f)g)h) I (j(k)l)m)")) << endl;
	cout << FindMaximumDepth(string("( p((q)) ((s)t) )")) << endl;
	cout << FindMaximumDepth(string("")) << endl;
	cout << FindMaximumDepth(string("b) (c) ()")) << endl;
	cout << FindMaximumDepth(string("(b) ((c) ()")) << endl;
}


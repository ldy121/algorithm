#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int TC, tc;
	int i, j, K;
	stack<int> book;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		cin >> K;
		for (i = 0; i < K; ++i) {
			cin >> j;
			if (j > 0) 	book.push(j);
			else		book.pop();
		}
		for (i = 0; !book.empty(); book.pop()) {
			i += book.top();
		}
		cout << "#" << tc << " " << i << endl;
	}
	return 0;
}

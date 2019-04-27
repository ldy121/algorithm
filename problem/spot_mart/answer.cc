#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int TC, tc;
	int N, M;
	int i, j, k, answer;
	vector<int> weight;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		cin >> N >> M;
		answer = -1;
		weight.resize(N);
		for (i = 0; i < N; ++i) {
			cin >> weight[i];
			for (j = 0; (answer <  M) && (j < i); ++j) {
				k = weight[i] + weight[j];
				if ((k <= M) && (answer < k)) {
					answer = k;
				}
			}
		}
		cout << "#" << tc << " " << answer << endl;
	}

	return 0;
}

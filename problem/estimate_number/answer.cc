#include <unordered_map>
#include <string>
#include <cstdio>
#include <iostream>
#include <iterator>

using namespace std;

#define MAX (4)

enum state {
	YES,
	NO
};

int main(void)
{
	int TC, tc;
	int N, i, j;
	int input[MAX];
	string think;

	unordered_map<unsigned int, enum state> answer;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		cin >> N;
		answer.clear();

		for (i = 0; i < N; ++i) {
			for (j = 0; j < 4; ++j) {
				cin >> input[j];
			}
			cin >> think;
			if (think == "NO") {
				for (j = 0; j < 4; ++j) {
					answer[input[j]] = NO;
				}
			} else {
				for (j = 0; j < 4; ++j) {
					if (answer[input[j]] != NO) {
						answer[input[j]] = YES;
					}
				}
			}
		}

		for (unordered_map<unsigned int, enum state>::iterator
			iter = answer.begin(); iter != answer.end(); ++iter) {
			if (iter->second == YES) {
				cout << "#" << TC << " " << iter->first << endl;
				break;
			}
		}
	}

	return 0;
}

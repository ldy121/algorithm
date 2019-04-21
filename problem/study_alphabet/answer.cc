#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

#define set_mask ((1 << 26) - 1)

using namespace std;
int answer;
int N;

void get_answer(vector<int> &vec, int index, int mask)
{
	if (index < N) {
		get_answer(vec, index + 1, mask);
		get_answer(vec, index + 1, mask | vec[index]);
	} else if (mask == set_mask) {
		++answer;
	}
}

int main(void)
{
	int TC;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	cin >> TC;

	for (int tc = 1; tc <= TC; ++tc) {
		cin >> N;
		vector<int> vec;

		for (int i = 0; i < N; ++i) {
			string str;
			int mask = 0;

			cin >> str;
			for (int j = 0; j < str.length(); ++j)
				mask |= (1 << (str[j] - 'a'));
			vec.push_back(mask);
		}
		answer = 0;
		get_answer(vec, 0, 0);
		cout << "#" << tc << " " << answer << endl;
		vec.clear();
	}

	return 0;
}

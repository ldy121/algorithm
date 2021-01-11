#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get_answer(string str)
{
	vector<int> num_bc(str.length());

	int answer = 0;

	for (int i = str.length() - 1, count_c = 0, count_bc = 0; i >= 0; --i) {
		if (str[i] == 'c') {
			++count_c;
		} else if (str[i] == 'b') {
			count_bc += count_bc;				// except current b
			count_bc += ((1 << count_c) - 1);	// directly next to c
		}

		num_bc[i] = count_bc;
	}

	for (int i = 0, count_a = 0; i < str.length(); ++i) {
		if (str[i] == 'a') {
			int val = ((1 << count_a) * num_bc[i]);
			answer += val;
			++count_a;
		}
	}

	return answer;
}

int main(void)
{
	cout << get_answer("abbc") << endl;
	cout << get_answer("abcabc") << endl;
}
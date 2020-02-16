#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function*/
bool get_answer(string &str, int low_to_high, int high_to_low, int k)
{
	while (low_to_high < high_to_low) {
		if (str[low_to_high] != str[high_to_low]) {
			break;
		}
		++low_to_high;
		--high_to_low;
	}
	if (low_to_high < high_to_low) {
		if (k > 0) {
			return get_answer(str, low_to_high + 1, high_to_low, k - 1) ||
			       get_answer(str, low_to_high, high_to_low - 1, k - 1);
		} else {
			return false;
		}
	} else {
		return true;
	}
}

bool is_k_palin(string s,int k) {
	return get_answer(s, 0, s.length() - 1, k);
}

int main(void)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> T; T > 0; --T) {
		string str;
		int N;
		cin >> str >> N;
		cout << is_k_palin(str, N) << endl;
	}
}

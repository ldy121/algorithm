#include <iostream>
#include <vector>

using namespace std;

const int max_bit = 10;
int answer[max_bit];

void init_answer(void)
{
	answer[0] = 1;
	for (int i = 1; i < max_bit; ++i) {
		answer[i] = (1 << i);
		for (int j = 0; j < i; ++j) {
			answer[i] += answer[j];
		}
	}
}

int get_answer(int n, int msb_bit)
{
	int ret = 0;
	for (int i = msb_bit; i >= 0; --i) {
		if ((n & (1 << i)) > 0) {
			int val = ((n & ~(1 << i)) + 1);
			ret = val + get_answer((n & ~(1 << i)), i - 1);
			for (int j = i - 1; j >= 0; --j) {
				ret += answer[j];
			}
			break;
		}
	}
	return ret;
}

int main(void)
{
	init_answer();
	cout << get_answer(3, max_bit) << endl;
	cout << get_answer(6, max_bit) << endl;
	cout << get_answer(7, max_bit) << endl;
	cout << get_answer(8, max_bit) << endl;
	cout << get_answer(17, max_bit) << endl;
	return 0;
}
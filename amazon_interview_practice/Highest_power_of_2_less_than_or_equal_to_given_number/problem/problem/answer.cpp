#include <iostream>

using namespace std;

int get_answer(int n)
{
	int low = 0, high = 31, mid;
	int ret;

	for (mid = (high + low) / 2; low < high; mid = (high + low) / 2) {
		ret = (1 << mid);
		
		if (n > ret)		low = mid + 1;
		else if (n < ret)	high = mid;
		else break;
	}

	return (ret > n) ? (ret >> 1) : (ret);
}

int main(void)
{
	cout << get_answer(15) << endl;
	cout << get_answer(19) << endl;
	cout << get_answer(32) << endl;
}
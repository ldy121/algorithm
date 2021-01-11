#include <iostream>

using namespace std;

int convert0To5(int num)
{
	int j = 0;
	int ret = 0;

	if (num == 0) {
		return 5;
	}

	while (num > 0) {
		int k = num % 10;
		if (k == 0) {
			k = 5;
		}
		j = (j * 10) + k;
		num /= 10;
	}

	while (j > 0) {
		ret = ret * 10 + (j % 10);
		j /= 10;
	}

	return ret;
}

// Driver code 
int main()
{
	int num = 10120;
	cout << convert0To5(num);
	return 0;
}
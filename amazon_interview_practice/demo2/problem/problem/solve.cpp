#include <iostream>

using namespace std;

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
int calc_gcd(int a, int b)
{
	int c;

	if (a < b) {
		c = a;
		a = b;
		b = c;
	}

	while (b > 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int generalizedGCD(int num, int* arr)
{
	int gcd = calc_gcd(arr[0], arr[1]);
	for (int i = 2; i < num; ++i) {
		gcd = calc_gcd(gcd, arr[i]);
	}
	return gcd;
}
// FUNCTION SIGNATURE ENDS

struct problem {
	int number[5];
	int count;
};

int main(void) {
	problem problems[] = {
		{{2, 3, 4, 5, 6}, 5},
		{{2, 4, 6, 8, 10}, 5}
	};

	for (int i = 0; i < sizeof(problems) / sizeof(problem); ++i) {
		cout << generalizedGCD(problems[i].count, problems[i].number) << endl;
	}

	return 0;
}
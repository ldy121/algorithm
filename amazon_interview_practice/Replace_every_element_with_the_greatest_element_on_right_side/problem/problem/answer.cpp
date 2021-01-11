#include <iostream>

using namespace std;

#define MAX(A,B) (((A) > (B)) ? (A) : (B))

void get_answer(int * data, int num)
{
	int j = MAX(data[num - 1], data[num - 2]);

	data[num - 2] = data[num - 1];

	for (int i = num - 3; i >= 0; --i) {
		int k = MAX(data[i], j);
		data[i] = j;
		j = k;
	}

	data[num - 1] = -1;
}

int main(void)
{
	int data[] = { 16, 17, 4, 3, 5, 2 };
	get_answer(data, 6);
	for (int i = 0; i < 6; ++i) {
		cout << data[i] << " ";
	}
	return 0;
}
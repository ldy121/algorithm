#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

#pragma warning(disable : 4996)

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
const int max_house = 8;

bool init_answer = false;
int answer[(1 << max_house)];

void generage_answer_table(void)
{
	int max = 1 << max_house;

	for (int i = 0; i < max; ++i) {
		int left_mask = 1;
		int right_mask = 1 << 2;
		int input = (i << 1);

		int output = 0;
		for (int j = 0; j < max_house; ++j) {
			if (((input & left_mask) > 0) != ((input & right_mask) > 0)) {
				output |= (1 << j);
			}
			left_mask <<= 1;
			right_mask <<= 1;
		}
		answer[i] = output;
	}
}

vector<int> cellCompete(int* states, int days)
{
	vector<int>* ret = new vector<int>;
	int input = 0;

	if (init_answer == false) {
		generage_answer_table();
		init_answer = true;
	}

	for (int i = 0; i < max_house; ++i) {
		input |= (states[i] << (max_house - 1 - i));
	}

	for (int i = 0; i < days; ++i) {
		input = answer[input];
	}

	ret->clear();
	for (int i = (1 << (max_house - 1)); i > 0; i >>= 1) {
		ret->push_back((input & i) > 0);
	}

	return *ret;
}

// FUNCTION SIGNATURE ENDS
struct problem {
	int state[8];
	int days;
};


int main(void)
{
	struct problem problems[2] = {
		{{ 1, 0, 0, 0, 0, 1, 0, 0}, 1},
		{{ 1, 1, 1, 0, 1, 1, 1, 1}, 2}
	};

	for (int i = 0; i < sizeof(problems) / sizeof(problem); ++i) {
		vector<int> answer = cellCompete(problems[i].state, problems[i].days);
		for (vector<int>::iterator iter = answer.begin(); iter != answer.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
	}

	return 0;
}
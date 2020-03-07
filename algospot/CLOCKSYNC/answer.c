#include <stdio.h>

#define CLOCK_NUMBER (16)
#define SIZE_INDEX (0)
#define SWITCH_SIZE (5)
#define SWITCH_NUMBER (10)
#define INIT (2 << 22)

unsigned int clock_switch[SWITCH_NUMBER + 1][SWITCH_SIZE + 1] = {
	{3, 0, 1,	2},
	{4, 3, 7,	9, 11},
	{4, 4, 10, 14, 15},
	{5, 0,	4,	5,	6,	7},
	{5,	6,	7,	8,	10, 12},
	{4,	0,	2,	14,	15},
	{3,	3,	14,	15},
	{5,	4,	5,	7,	14,	15},
	{5,	1,	2,	3,	4,	5},
	{5,	3,	4,	5,	9,	13}
};

int clock[CLOCK_NUMBER + 1];
int click[SWITCH_NUMBER + 1];

int answer;

void get_answer(int count, int switch_index)
{
	int i;

	++click[switch_index];

	for (i = 1; i <= clock_switch[switch_index][SIZE_INDEX]; ++i) {
		clock[clock_switch[switch_index][i]] = (clock[clock_switch[switch_index][i]] + 3) % 12;
	}

	for (i = 0; i < CLOCK_NUMBER; ++i) {
		if (clock[i] != 0)
			break;
	}

	if ((answer > count)) {
		if (i != CLOCK_NUMBER) {
			for (i = switch_index; i < SWITCH_NUMBER; ++i) {
				if (click[i] < 4) {
					get_answer(count + 1, i);
				}
			}
		} else {
			answer = count;
		}
	}

	for (i = 1; i <= clock_switch[switch_index][SIZE_INDEX]; ++i) {
		clock[clock_switch[switch_index][i]] = (clock[clock_switch[switch_index][i]] + 9) % 12;
	}


	--click[switch_index];
}

int main(void)
{
	int tc, T;
	int i, j;
	unsigned int val, sum, carry, tmp, time, count, visit;
	int queue_size, pop_queue;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		for (i = 0; i < CLOCK_NUMBER; ++i) {
			scanf("%d", &clock[i]);
			clock[i] = clock[i] % 12;
		}

		for (i = 0; i < SWITCH_NUMBER; ++i) {
			click[i] = 0;
		}

		for (i = 0; i < CLOCK_NUMBER; ++i) {
			if (clock[i] != 0)
				break;
		}

		if (i != CLOCK_NUMBER) {
			answer = INIT;
			for (i = 0; i < SWITCH_NUMBER; ++i) {
				get_answer(1, i);
			}

			if (answer == INIT)
				answer = -1;
		} else {
			answer = 0;
		}

		printf("%d\n", answer);
	}

	return 0;
}

#include <stdio.h>

#define MAX_INPUT (1000000)
#define invalid (-1)
#define available (1)
#define unavailable (-1)

int N;

int input[MAX_INPUT];
int answer[MAX_INPUT];
int index[MAX_INPUT];
int city_stack[MAX_INPUT];
int mask_city[MAX_INPUT];
int stack_point;

void stack_push(int idx)
{
	int i, j, k;

	mask_city[idx] = unavailable;
	city_stack[stack_point++] = idx;
	for (k = stack_point - 1, j = 1; k >= 0; --k, ++j) {
		i = city_stack[k];
		if ((i + j) <  N) mask_city[i + j] = unavailable;
		if ((i - j) >= 0) mask_city[i - j] = unavailable;
	}
}

void stack_pop(int idx)
{
	int i, j, k;

	for (k = stack_point - 1, j = 1; k >= 0; --k, ++j) {
		i = city_stack[k];
		if ((i + j) <  N) mask_city[i + j] = available;
		if ((i - j) >= 0) mask_city[i - j] = available;
	}
	mask_city[idx] = available;
	--stack_point;
}

int get_answer(int idx)
{
	int i, max, ret;
	if (answer[index[idx]] == invalid) {
		stack_push(index[idx]);
		for (i = idx + 1, max = 0; i < N; ++i) {
			if (mask_city[index[i]] == available) {
				ret = get_answer(i);
				if (max < ret) {
					max = ret;
				}	
			}
		}
		stack_pop(index[idx]);
		answer[index[idx]] = input[index[idx]] + max;
	}
	return answer[index[idx]];
}

void qsort(int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (input[index[left]] < input[index[i]]) {
				++j;
				k = index[j];
				index[j] = index[i];
				index[i] = k;
			}
		}
		k = index[j];
		index[j] = index[left];
		index[left] = k;
		qsort(left, j - 1);
		qsort(j + 1, right);
	}
}

int main(void)
{
	int TC, T;
	int i, ans, ret;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &input[i]);
			answer[i] = invalid;
			mask_city[i] = available;
			index[i] = i;
		}
		qsort(0, N - 1);

		stack_point = 0;
		for (ans = 0, i = 0; i < N; ++i) {
			ret = get_answer(i);
			if (ans < ret) {
				ans = ret;
			}
		}
		printf("#%d %d\n", T, ans);
	}
}

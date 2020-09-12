#include <stdio.h>

#define MAX (200000)
#define get_min_heap_root()	min_heap[1]
#define get_max_heap_root()	max_heap[1]
#define MODULE ((long long)20090711)

long long A[MAX + 1];
long long max_heap[MAX + 1];
long long min_heap[MAX + 1];
int a, b, N;
int max_cnt, min_cnt;

void generate() {
	int i;

	A[0] = (long long)1983;

	for (i = 1; i <= N; ++i) {
		A[i] = (long long)((long long)(A[i - 1] * a + b) % MODULE);
	}
}

void push_max_heap(long long val)
{
	int i;
	long long j;

	max_heap[++max_cnt] = val;
	for (i = max_cnt; i > 1; i /= 2) {
		if (max_heap[i] > max_heap[i / 2]) {
			j = max_heap[i];
			max_heap[i] = max_heap[i / 2];
			max_heap[i / 2] = j;
		} else {
			break;
		}
	}
}

long long pop_max_heap()
{
	int i, j;
	long long ret, k;

	ret = max_heap[1];
	for (max_heap[1] = max_heap[max_cnt--], i = 1; (i * 2) <= max_cnt;) {
		if (((i * 2 + 1) <= max_cnt) && (max_heap[i * 2] < max_heap[i * 2 + 1])) j = i * 2 + 1;
		else																	j = i * 2;

		if (max_heap[j] > max_heap[i]) {
			k = max_heap[j];
			max_heap[j] = max_heap[i];
			max_heap[i] = k;

			i = j;
		} else {
			break;
		}
	}

	return ret;
}

void push_min_heap(long long val)
{
	int i;
	long long j;

	min_heap[++min_cnt] = val;
	for (i = min_cnt; i > 1; i /= 2) {
		if (min_heap[i] < min_heap[i / 2]) {
			j = min_heap[i];
			min_heap[i] = min_heap[i / 2];
			min_heap[i / 2] = j;
		} else {
			break;
		}
	}
}

long long pop_min_heap(void)
{
	int i, j;
	long long k, ret;

	ret = min_heap[1];
	for (min_heap[1] = min_heap[min_cnt--], i = 1; (i * 2) <= min_cnt;) {
		if (((i * 2 + 1) <= min_cnt) && (min_heap[i * 2] > min_heap[i * 2 + 1])) j = i * 2 + 1;
		else																	j = i * 2;

		if (min_heap[j] < min_heap[i]) {
			k = min_heap[j];
			min_heap[j] = min_heap[i];
			min_heap[i] = k;

			i = j;
		} else {
			break;
		}
	}

	return ret;
}

int main(void)
{
	int tc, T;
	int i;
	long long answer, j;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %ld %ld", &N, &a, &b);
		generate();

		answer = 0;
		max_cnt = 0;
		min_cnt = 0;
		for (i = 0; i < N; ++i) {
			if ((min_cnt > 0) && (A[i] > get_min_heap_root())) {
				push_min_heap(A[i]);	
			} else {
				push_max_heap(A[i]);
			}

			if (min_cnt > max_cnt) {
				j = pop_min_heap();
				push_max_heap(j);
			} else if (max_cnt > (min_cnt + 1)) {
				j = pop_max_heap();
				push_min_heap(j);
			}

			while ((max_cnt > 0) && (min_cnt > 0) && (get_min_heap_root() < get_max_heap_root())) {
				j = pop_min_heap();
				push_max_heap(j);

				j = pop_max_heap();
				push_min_heap(j);
			}

			answer = (answer + get_max_heap_root()) % MODULE;
		}

		printf("%lld\n", answer % MODULE);
	}

	return 0;
}

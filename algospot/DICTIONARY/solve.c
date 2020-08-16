#include <stdio.h>

#define MAX (26)
#define TRUE (1)
#define FALSE (0)
#define INVALID (-1)

int queue[2][(MAX + 1) * (MAX + 1)];

int push_queue, queue_index;

int prev_length[MAX + 1];
int prev[MAX + 1][MAX + 1];
int next[MAX + 1][MAX + 1];

int visit[MAX + 1];
int N;
char answer[MAX + 1];
char buffer[2][MAX + 1];

#define push(X) do { \
		queue[push_queue][queue_index] = (X);\
		++queue_index;\
	} while(0)

int main(void)
{
	int tc, T;
	int i, j, k;
	int input_buffer;
	int before_buffer;
	int pop_queue, queue_size;
	int answer_index;
	int t;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);
		input_buffer = 0;

		for (i = 0; i <= MAX; ++i) {
			for (j = 0; j <= MAX; ++j) {
				prev[i][j] = FALSE;
				next[i][j] = FALSE;
			}
			prev_length[i] = 0;

			answer[i] = 'a' + i;
			visit[i] = FALSE;
		}

		scanf("%s\n", &buffer[input_buffer][0]);
		if (N > 1) {
			answer_index = 0;
			push_queue = 0;
			queue_index = 0;

			for (k = 1; k < N; ++k) {
				before_buffer = input_buffer;
				input_buffer = !input_buffer;

				scanf("%s\n", &buffer[input_buffer][0]);

				for (i = 0; (buffer[input_buffer][i] != '\0') && (buffer[before_buffer][i] != '\0') && (buffer[input_buffer][i] == buffer[before_buffer][i]); ++i);

				if ((buffer[before_buffer][i] != '\0') && (buffer[input_buffer][i] == '\0')) {
					answer_index = INVALID;
				} else if ((buffer[before_buffer][i] != '\0') && (buffer[input_buffer][i] != '\0'))  {
					if (prev[buffer[input_buffer][i] - 'a'][buffer[before_buffer][i] - 'a'] == FALSE) {
						prev[buffer[input_buffer][i] - 'a'][buffer[before_buffer][i] - 'a'] = TRUE;
						++prev_length[buffer[input_buffer][i] - 'a'];
					}

					next[buffer[before_buffer][i] - 'a'][buffer[input_buffer][i] - 'a'] = TRUE;
				}
			}

			if (answer_index == 0) {
				for (i = 0; i < MAX; ++i) {
					if ((prev_length[i] == 0) && (visit[i] == FALSE))
						push(i);
				}

				for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
					pop_queue = push_queue;
					push_queue = !push_queue;
					queue_index = 0;

					for (i = 0; i < queue_size; ++i) {
						t = queue[pop_queue][i];
						if (visit[t] == FALSE) {
							visit[t] = TRUE;
							answer[answer_index++] = 'a' + t;

							if (t == 14)
								t = 14;

							for (j = 0; j < MAX; ++j) {
								if (next[t][j] == TRUE) {
									prev[j][t] = FALSE;
									--prev_length[j];
								}
							}
						}
					}

					for (i = 0; i < MAX; ++i) {
						if ((prev_length[i] == 0) && (visit[i] == FALSE))
							push(i);
					}
				}
			}
		} else {
			answer_index = MAX;
		}

		if (answer_index < MAX) {
			printf("INVALID HYPOTHESIS");
		} else {
			for (i = 0; i < MAX; ++i)
				printf("%c", answer[i]);
		}
		printf("\n");
	}

	return 0;
}

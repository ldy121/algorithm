#include <stdio.h>

#define MAX (15)
#define MAX_LEN (40)
#define push(X) do {\
	if (answer[(X)].valid == FALSE) {\
		(queue[push_queue][queue_index++]=(X));\
		answer[(X)].valid = TRUE; \
	} } while(0);
#define TRUE (1)
#define FALSE (0)
#define INVALID (-1)

struct TABLE {
	char buffer[(MAX + 1) * (MAX_LEN + 1)];
	int valid;
	int len;
};

struct TABLE answer[(1 << (MAX + 1)) + 1];
int queue[2][(1 << (MAX + 1) ) + 1];
int K;
int push_queue, queue_index;

int my_strlen(char *buf)
{
	int i;
	for (i = 0; buf[i] != '\0'; ++i);
	return i;
}

void get_answer(int src, int dst)
{
	int tmp, i, j, k;
	int id, front_len, end_len, len;
	char *pt;
	char front[(MAX + 1) * (MAX_LEN + 1)];
	char end[(MAX + 1) * (MAX_LEN + 1)];

	id = src | dst;

	if (answer[src].len > answer[dst].len) {
		tmp = src;
		src = dst;
		dst = tmp;
	}

	end_len = INVALID;
	for (i = 0; i < answer[dst].len; ++i) {
		if (answer[dst].buffer[i] == answer[src].buffer[0]) {
			for (j = 0, k = i; (k < answer[dst].len) && (j < answer[src].len); ++k, ++j) {
				if (answer[src].buffer[j] != answer[dst].buffer[k])
					break;
			}

			if (j == answer[src].len) {		//	dst can include src
				for (end_len = 0; end_len < answer[dst].len; ++end_len) {
					end[end_len] = answer[dst].buffer[end_len];
				}

				end[end_len] = '\0';
				i = end_len;	// for get out of the loop
			} else if (k == answer[dst].len) {
				for (end_len = 0; end_len < i; ++end_len) {
					end[end_len] = answer[dst].buffer[end_len];
				}
				for (k = 0; k < answer[src].len; ++k) {
					end[end_len++] = answer[src].buffer[k];
				}
				
				end[end_len] = '\0';
				i = end_len;	// for finish ending loop
			} else {
				i = k;
			}
		}
	}

	if (end_len == INVALID) {
		for (end_len = 0; end_len < answer[dst].len; ++end_len) {
			end[end_len] = answer[dst].buffer[end_len];
		}
		for (i = 0; i < answer[src].len; ++i) {
			end[end_len++] = answer[src].buffer[i];
		}
		end[end_len] = '\0';
	}

	front_len = end_len;
	if (end_len > answer[dst].len) {

		for (i = answer[dst].len - 1; i >= 0; --i) {
			if (answer[dst].buffer[i] == answer[src].buffer[answer[src].len - 1]) {
				for (j = answer[src].len - 1, k = i; (j >= 0) && (k >= 0); --j, --k) {
					if (answer[src].buffer[j] != answer[dst].buffer[k]) {
						break;
					}
				}

				if (k < 0) {
					for (front_len = 0; front_len <= j; ++front_len) {
						front[front_len] = answer[src].buffer[front_len];
					}
					for (k = 0; k < answer[dst].len; ++k) {
						front[front_len++] = answer[dst].buffer[k];
					}

					front[front_len] = '\0';
					i = -1;	// for end loop
				} else if (j < 0) { // dst can include src
					for (front_len = 0; front_len < answer[dst].len; ++front_len) {
						front[front_len] = answer[dst].buffer[front_len];
					}

					front[front_len] = '\0';
					i = -1;	// for end loop
				} else {
					i = k;
				}
			}
		}
	}

	if (front_len < end_len) {
		len = front_len;
		pt = front;		
	} else {
		len = end_len;
		pt = end;
	}
	if ((answer[id].valid == FALSE) || ((answer[id].valid == TRUE) && (len < answer[id].len))) {
		answer[id].len = len;
		for (i = 0; i < len; ++i) {
			answer[id].buffer[i] = pt[i];
		}
		answer[id].buffer[i] = '\0';
	}
}

int main(void)
{
	int tc, T;
	int i, j, id;
	int pop_queue, queue_size;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		push_queue = 0;
		queue_index = 0;

		scanf("%d\n", &K);
		for (i = 0; i < (1 << K); ++i)
			answer[i].valid = FALSE;

		for (i = 0; i < K; ++i) {
			scanf("%s\n", answer[(1 << i)].buffer);
			answer[(1 << i)].len = my_strlen(answer[(1 << i)].buffer);
			push((1 << i));
		}

		for (queue_size = queue_index; queue_size > 0; queue_size = queue_index) {
			pop_queue = push_queue;
			push_queue = !push_queue;
			queue_index = 0;

			for (i = 0; i < queue_size; ++i) {
				id = queue[pop_queue][i];
				for (j = 0; j < K; ++j) {
					if ((id & (1 << j)) == 0) {
						get_answer(id, (1 << j));
						push(id | (1 << j));
					}
				}
			}
		}

		printf("%s\n", answer[(1 << K) - 1].buffer);
	}

	return 0;
}

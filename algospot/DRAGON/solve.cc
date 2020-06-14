#include <stdio.h>

#define MAX (50)
#define INVALID (-1)
#define TRUE (1)
#define FALSE (0)

long long length[MAX + 1];
char buffer[MAX + 1];
int n;
long long buffer_len;
long long p, l;

int generation;

void get_answer(char *input, int current)
{
	int i;
	if (p <= 0)
		p = p;
	if (generation > current) {
		for (i = 0; (input[i] != '\0') && (buffer_len < l); ++i) {
			if (input[i] == 'X') {
				if (length[generation - current] <= p)	
					p -= length[generation - current];
				else									get_answer("X+YF", current + 1);
			} else if (input[i] == 'Y') {
				if (length[generation - current] <= p)	p -= length[generation - current];
				else									get_answer("FX-Y", current + 1);
			} else if (p <= 0) {
				buffer[buffer_len++] = input[i];
			} else {
				--p;
			}
		}
	} else {
		for (i = 0; (input[i] != '\0') && (buffer_len < l); ++i) {
			if (p <= 0) {
				buffer[buffer_len++] = input[i];
			} else {
				--p;
			}
		}
	}
}

int main(void)
{
	int tc, T, i;

	length[0] = 1;
	for (i = 1; i <= MAX; ++i)
		length[i] = (length[i - 1] * 2) + 2;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %lld %lld\n", &n, &p, &l);
		++n;
		for (i = n; length[i] < (p + l); --i);

		buffer_len = 0;
		generation = i - 1;
		if (--p == 0) buffer[buffer_len++] = 'F';
		--p;
		get_answer("X+YF", 1);

		buffer[l] = '\0';
		printf("%s\n", buffer);
	}

	return 0;
}


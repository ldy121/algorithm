#include <stdio.h>

#define MAX (5)
#define FALSE (0)
#define TRUE (1)
#define INVALID (-1)

int blocks[(MAX + 1) * (MAX + 1) * 7];
int block_len;

char answer[1 << (MAX * MAX)];
char map[MAX + 2][MAX + 2];

void add_block(int block)
{
	blocks[block_len++] = block;
}

void gen_blocks(void)
{
	int i, j;
	int tmp1, tmp2, tmp3, tmp4;

	for (i = 0; i < 4; ++i) {
		tmp1 = (0x23 << (i * 5));
		tmp2 = (0x43 << (i * 5));
		tmp3 = (0x61 << (i * 5));
		tmp4 = (0x62 << (i * 5));
		for (j = 0; j < 4; ++j) {
			add_block(tmp1 << j);
			add_block(tmp2 << j);
			add_block(tmp3 << j);
			add_block(tmp4 << j);
		}
	}

	for (i = 0; i < 5; ++i) {
		tmp1 = ((0x3) << (i * 5));
		for (j = 0; j < 4; ++j) {
			add_block(tmp1 << j);
		}
	}

	for (i = 0; i < 4; ++i) {
		tmp1 = ((0x21) << (i * 5));
		for (j = 0; j < 5; ++j) {
			add_block(tmp1 << j);
		}
	}
}

char get_answer(int block)
{
	int i;
	char ret = FALSE;

	if (answer[block] != INVALID) return answer[block];

	for (i = 0; (i < block_len) && (ret == FALSE); ++i) {
		if ((block & blocks[i]) == 0) {
			ret = !get_answer(block | blocks[i]);
		}
	}

	answer[block] = ret;
	return ret;
}

int main(void)
{
	int tc, T;
	int block;
	int i, j, k;
	char ans;

	block_len = 0;
	gen_blocks();

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		block = 0;
		for (i = 0; i < (1 << (MAX * MAX)); ++i)
			answer[i] = INVALID;

		for (i = 0; i < MAX; ++i) {
			scanf("%s\n", map[i]);
			k = 0;
			for (j = 0; j < MAX; ++j) {
				if (map[i][j] == '#') k = ((k << 1) | 1);
				else				  k = k << 1;
			}
			block <<= 5;
			block = block | k;
		}

		ans = get_answer(block);
		if (ans == FALSE) printf("LOSING\n");
		else printf("WINNING\n");
	}

	return 0;
}


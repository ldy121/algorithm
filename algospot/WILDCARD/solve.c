#include <stdio.h>

#define MAX (100)
#define TRUE (1)
#define FALSE (0)
#define INVALID (-1)

char dp[MAX + 1][MAX + 1];

char wild[MAX + 1];
char str[MAX + 1][MAX + 1];
char *input;
char * answer[MAX + 1];

int wild_len, input_len, ans, N;

void insert_sort(char *in)
{
	int i, j;
	char *tmp;

	for (i = 0; i < ans; ++i) {
		for (j = 0; answer[i][j] != '\0' && in[j] != '\0'; ++j) {
			if (answer[i][j] != in[j])
				break;
		}

		if (answer[i][j] > in[j]) {
			tmp = answer[i];
			answer[i] = in;
			in = tmp;
			break;
		}
	}

	while (++i < ans) {
		tmp = answer[i];
		answer[i] = in;
		in = tmp;
	}

	answer[ans++] = in;
}

int my_len(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

char get_answer(int wild_index, int input_index)
{
	char ret;
	if (dp[wild_index][input_index] != INVALID) return dp[wild_index][input_index];

	if (wild[wild_index] == '*') {
		if ((get_answer(wild_index + 1, input_index)) || 
			((input_index < input_len) && (get_answer(wild_index, input_index + 1))))
			ret = TRUE;
		else
			ret = FALSE;
	} else if (wild[wild_index] == '\0') {
		ret = (input[input_index] == '\0');
	} else if ((wild_index < wild_len) && (input_index < input_len) && ((wild[wild_index] == '?') || (wild[wild_index] == input[input_index]))) {
		ret = get_answer(wild_index + 1, input_index + 1);
	} else {
		ret = FALSE;
	}

	dp[wild_index][input_index] = ret;
	return ret;
}

int main(void)
{
	int tc, T;
	int i, j, k;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%s\n", wild);
		scanf("%d\n", &N);
		ans = 0;

		wild_len = my_len(wild);
		for (k = 0; k < N; ++k) {
			scanf("%s\n", str[k]);
			input_len = my_len(str[k]);
			input = str[k];

			for (i = 0; i <= wild_len; ++i) {
				for (j = 0; j <= input_len; ++j) {
					dp[i][j] = INVALID;
				}
			}

			for (i = 0; (i < wild_len) && (i < input_len) && ((wild[i] == '?') || (wild[i] == str[k][i])); ++i);

			if ((i == input_len) && (i == wild_len))
				insert_sort(str[k]);
			else if ((i < input_len) && (i < wild_len))			
				if (get_answer(i, i))
					insert_sort(str[k]);
		}

		for (i = 0; i < ans; ++i)
			printf("%s\n", answer[i]);
	}

	return 0;
}

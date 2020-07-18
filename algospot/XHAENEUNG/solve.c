#include <stdio.h>

#define MAX (26)
#define INVALID (-1)
#define MAX_BUFFER (1024)

char* map[] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten"
};

int map_table[sizeof(map) / sizeof(char *)][MAX + 1];
int num_table[MAX + 1];
char num1[MAX_BUFFER];
char num2[MAX_BUFFER];
char ans[MAX_BUFFER];

int get_number(char *num) {
	int i, j;

	for (i = 0; i < MAX; ++i)
		num_table[i] = 0;

	for (i = 0; num[i] != '\0'; ++i)
		++num_table[num[i] - 'a'];

	for (i = 0; i < (sizeof(map) / sizeof(char *)); ++i) {
		for (j = 0; (j < MAX) && (map_table[i][j] == num_table[j]); ++j);
		if (j == MAX)
			return i;
	}

	return INVALID;
}

int main(void)
{
	int tc, T;
	int i, j, k, answer;
	char op;

	for (i = 0; i < (sizeof(map) / sizeof(char *)); ++i) {
		for (j = 0; j < MAX; ++j)
			map_table[i][j] = 0;
		for (j = 0; map[i][j] != '\0'; ++j)
			++map_table[i][map[i][j] - 'a'];
	}

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%s %c %s = %s\n", num1, &op, num2, &ans);
		j = get_number(num1);
		k = get_number(num2);
		answer = get_number(ans);

		if ((answer < 0) || (answer > 10)) {
			printf("No\n");
		} else {
			switch (op) {
			case '+' :
				i = j + k;
				break;
			case '/' :
				i = j / k;
				break;
			case '*' :
				i = j * k;
				break;
			case '-' :
				i = j - k;
				break;
			}

			if (i == answer)	printf("Yes\n");
			else				printf("No\n");
		}
	}

	return 0;
}


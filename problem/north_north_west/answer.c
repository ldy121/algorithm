#include <stdio.h>

#define MAX (200)

enum direction {
	west,
	north,
	init_dir
};

int get_operand_angle(int * upper, int * down, int n)
{
	int ret;
	if ((1 << n) > *down) {
		*upper *= (1 << n) / *down;
		*down  *= (1 << n) / *down;
		ret = 90;
	} else {
		ret = 90 * *down / (1 << n);
	}
	return ret;
}

int get_gcd(int a, int b)
{
	int c;
	if (b > a) {
		c = a;
		a = b;
		b = c;
	}
	while (b > 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void)
{
	int TC, tc;
	int answer_upper, answer_down, len, n, tmp;
	enum direction prev;
	char str[MAX + 1];

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%s\n", str);
		for (len = 0; str[len] != '\0'; ++len);
		if (str[--len] == 't') {
			answer_upper = 90;
			prev = west;
			len -= 4;
		} else {
			answer_upper = 0;
			prev = north;
			len -= 5;
		}
		for (n = 1, answer_down = 1; len > 0;) {
			if (str[len] == 't') {
				if (prev == west) ++n;
				else		  n = 1;
				prev = west;
				len -= 4;
				tmp = get_operand_angle(&answer_upper, &answer_down, n);
				answer_upper += tmp;
			} else {
				if (prev == north) ++n;
				else		  n = 1;
				prev = north;
				len -= 5;
				tmp = get_operand_angle(&answer_upper, &answer_down, n);
				answer_upper -= tmp;
			}
		}
		
		if ((answer_upper % answer_down) == 0) {
			printf("#%d %d\n", tc, answer_upper / answer_down);
		} else {
			tmp = get_gcd(answer_upper, answer_down);
			printf("#%d %d/%d\n", tc, answer_upper / tmp, answer_down / tmp);
		}
	}

	return 0;
}

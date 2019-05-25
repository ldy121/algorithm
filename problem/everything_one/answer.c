#include <stdio.h>

#define MAX (30)

int predefined[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
	int TC, tc;
	int year, month, day, hour, min, sec;
	int carry, binary, i;
	char binary_time[MAX + 1];

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (tc = 1; tc <= TC; ++tc) {
		scanf("%d/%d/%d %d:%d:%d\n", &year, &month, &day, &hour, &min, &sec);
		scanf("%s\n", binary_time);
		for (i = 0, binary = 0; binary_time[i] != '\0'; ++i) {
			binary = (binary << 1) | (binary_time[i] - '0');
		}
		carry = (binary + sec) / 60;
		sec = (binary + sec) % 60;
		i = (carry + min) / 60;
		min = (carry + min) % 60;
		carry = i;

		i = (carry + hour) / 24;
		hour = (carry + hour) % 24;
		carry = i;

		i = (365 * year) + ((month - 1) * 30) + day + (month / 2);
		if (month > 2) i -= 2;
		if ((month == 9) || (month == 11)) i += 1;

		year = (carry + i) / 365;
		day = (carry + i) % 365;

		for (i = 0; i < sizeof(predefined) / sizeof(int); ++i) {
			if (day <= predefined[i]) {
				break;
			}
			day -= predefined[i];
		}
		month = i + 1;
		day = day;

		printf("#%d %d/%d/%d %02d:%02d:%02d\n", tc, year, month, day, hour, min, sec);
	}

	return 0;
}

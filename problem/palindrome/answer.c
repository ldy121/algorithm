#include <stdio.h>

#define MAX (100000)
#define get_max(A,B) (((A)>(B)) ? (A) : (B))
#define get_min(A,B) (((A)<(B)) ? (A) : (B))

int main(void)
{
	int TC, tc, a, b, c;
	int min, max, i;
	char input[MAX + 1];

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		scanf("%s", input);
		for (a = b = c = i = 0; input[i] != '\0'; ++i) {
			switch(input[i]) {
			case 'a' :
				++a;
				break;
			case 'b' :
				++b;
				break;
			case 'c' :
				++c;
				break;
			}
		}

		printf("#%d %s\n", tc, (((get_max(get_max(a,b),c) - get_min(get_min(a,b),c)) <=1) ? ("YES") : ("NO")));
	}
}

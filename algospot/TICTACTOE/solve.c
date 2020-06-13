#include <stdio.h>

#define MAX (3)
#define INVALID (-1)
#define FALSE (0)
#define TRUE (1)

#define DRAW (4)
#define O (2)
#define X (1)

int answer[MAX + 1][MAX + 1];
char map[MAX + 1][MAX + 1];

int check(void)
{
	if ((map[0][0] != '.') && (map[0][0] == map[1][1]) && (map[0][0] == map[2][2])) {
		return ((map[0][0] == 'X') ? X  : O);
	} else if ((map[0][2] != '.') && (map[0][2] == map[1][1]) && (map[0][2] == map[2][0])) {
		return ((map[0][2] == 'X') ? X  : O);
	} 
	else if ((map[0][0] != '.') && (map[0][0] == map[0][1]) && (map[0][0] == map[0][2])) {
		return ((map[0][0] == 'X') ? X  : O);
	} else if ((map[1][0] != '.') && (map[1][0] == map[1][1]) && (map[1][0] == map[1][2])) {
		return ((map[1][0] == 'X') ? X  : O);
	} else if ((map[2][0] != '.') && (map[2][0] == map[2][1]) && (map[2][0] == map[2][2])) {
		return ((map[2][0] == 'X') ? X  : O);
	} 
	else if ((map[0][0] != '.') && (map[0][0] == map[1][0]) && (map[0][0] == map[2][0])) {
		return ((map[0][0] == 'X') ? X  : O);
	} else if ((map[0][1] != '.') && (map[0][1] == map[1][1]) && (map[0][1] == map[2][1])) {
		return ((map[0][1] == 'X') ? X  : O);
	} else if ((map[0][2] != '.') && (map[0][2] == map[1][2]) && (map[0][2] == map[2][2])) {
		return ((map[0][2] == 'X') ? X  : O);
	} else {
		return DRAW;
	}
}

int get_answer(int turn)
{
	int ret, i, j, tmp, did;

	ret = check();
	if (ret != DRAW) return ret;
	else			 ret = ((turn == X) ? O : X);

	did = FALSE;
	for (i = 0; (ret != turn) && (i < MAX); ++i) {
		for (j = 0; (ret != turn) && (j < MAX); ++j) {
			if (map[i][j] == '.') {
				did = TRUE;

				if (turn == X) {
					map[i][j] = 'X';
					tmp = get_answer(O);
				} else {
					map[i][j] = 'O';
					tmp = get_answer(X);
				}
				map[i][j] = '.';

				if (tmp == turn)
					return turn;
				else if (tmp == DRAW)
					ret = tmp;
			}
		}
	}

	if (did == FALSE) return DRAW;
	else return ret;
}

int main(void)
{
	int tc, T;
	int i, j;
	int O_count, X_count, ret;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%s\n", map[0]);
		scanf("%s\n", map[1]);
		scanf("%s\n", map[2]);

		O_count = X_count = 0;
		for (i = 0; i < MAX; ++i) {
			for (j = 0; j < MAX; ++j) {
				switch (map[i][j]) {
				case 'o' :
					map[i][j] = 'O';
					++O_count;
					break;
				case 'x' :
					map[i][j] = 'X';
					++X_count;
					break;
				}
			}
		}

		if (O_count == X_count) 
			ret = get_answer(X);
		else 
			ret = get_answer(O);


		switch (ret) {
		case O :
			printf("o\n");
			break;
		case X :
			printf("x\n");
			break;
		default :
			printf("TIE\n");
			break;
		}
	}

	return 0;
}


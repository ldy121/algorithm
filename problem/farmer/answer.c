#include <stdio.h>

#define MAX (500000)
#define get_distance(x,y) (((x) > (y)) ? ((x) - (y)) : ((y) - (x)))

int zi[MAX];
int zj[MAX];

void qsort(int arr[], int left, int right)
{
	int i, j, k;

	if (left < right) {
		for (i = left + 1, j = left; i <= right; ++i) {
			if (arr[i] < arr[left]) {
				++j;
				k = arr[i];
				arr[i] = arr[j];
				arr[j] = k;
			}
		}
		k = arr[left];
		arr[left] = arr[j];
		arr[j] = k;
		qsort(arr, left, j - 1);
		qsort(arr, j + 1, right);
	}
}

int main(void)
{
	int TC, T;
	int min, count, i, j, k;
	int n, m, c, dist, prev, tmp;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &TC);
	for (T = 1; T <= TC; ++T) {
		scanf("%d %d\n", &n, &m);
		scanf("%d %d\n", &i, &j);
		c = ((i > j) ? (i - j) : (j - i));
		for (i = 0; i < n; ++i) {
			scanf("%d", &zi[i]);
		}
		for (i = 0; i < m; ++i) {
			scanf("%d", &zj[i]);
		}

		qsort(zi, 0, n - 1);
		qsort(zj, 0, m - 1);
		for (min = MAX * 2, count = 0, i = 0, k = 0; i < n; ++i) {
			dist = get_distance(zi[i], zj[k]) + c;
			if (dist < min) {
				min = dist;
				count = 1;
			} else if (dist == min) {
				++count;
			}

			for (j = k - 1, prev = dist; j >= 0; --j) {
				tmp = get_distance(zi[i], zj[j]) + c;
				if (tmp < min) {
					min = tmp;
					count = 1;
				} else if (tmp == min) {
					++count;
				} else if (tmp > prev) {
					break;
				}
				prev = tmp;
			}
			for (j = k + 1, prev = dist; j < m; ++j) {
				tmp = get_distance(zi[i], zj[j]) + c;
				if (tmp < min) {
					min = tmp;
					count = 1;
				} else if (tmp == min) {
					++count;
				} else if (tmp > prev) {
					break;
				}
				prev = tmp;
			}
		}

		printf("#%d %d %d\n", T, min, count);
	}
}

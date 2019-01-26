/*
 *  
 *  Original Problem Website :
 *    http://placementsindia.blogspot.com/2007/12/solutions-to-few-google-top-interview.html
 *
 *
 *  Problem :
 *  There is an array A[N] of N numbers.
 *  You have to compose an array Output[N] such that Output[i] will be equal to
 *  multiplication of all the elements of A[N] except A[i].
 *  For example Output[0] will be multiplication of A[1] to A[N-1] and Output[1]
 *  will be multiplication of A[0] and from A[2] to A[N-1].
 */

#include <stdio.h>

void init_A(int A[], int N)
{
	int i;

	for (i = 0; i < N; ++i) {
		A[i] = i + 1;
	}	
}

void solve_with_divide(int A[], long long Output[], int N)
{
	int i;
	long long j;

	for (i = 0, j = 1; i < N; ++i) {
		j *= A[i];
	}
	for (i = 0; i < N; ++i) {
		Output[i] = j / A[i];
	}
}

void solve_without_divide(int A[], long long Output[], int N)
{
	int i;
	long long j;

	for (i = 1, j = A[0]; i < N; ++i) {
		Output[i] = j;
		j *= A[i];
	}

	Output[0] = 1;
	for (i = N - 2, j = A[N - 1]; i >= 0; --i) {
		Output[i] *= j;
		j *= A[i];
	}
}

void print_output(char tag[], long long Output[], int N)
{
	printf("%s : ", tag);
	for (int i = 0; i < N; ++i) {
		printf("%lld ", Output[i]);
	}
	printf("\n");
}

int main(void)
{
	const int N = 10;

	int A[N];
	long long Output[N];

	init_A(A, N);
	solve_with_divide(A, Output, N);
	print_output("with_divide    : ", Output, N);
	solve_without_divide(A, Output, N);
	print_output("without_divide : ", Output, N);

	return 0;
}

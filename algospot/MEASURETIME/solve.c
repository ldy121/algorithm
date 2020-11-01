#include <stdio.h>

#define MAX (1000000)

struct NODE {
	int left;
	int right;
	struct NODE *left_node;
	struct NODE *right_node;

	long long count;
};

struct NODE node[(MAX + 1) * 2 + 1];
struct NODE *root;
int A[50001];
int node_size;
int N;

struct NODE * init_node(int left, int right)
{
	struct NODE *pt;

	pt = &node[node_size++];
	pt->left = left;
	pt->right = right;
	pt->left_node = NULL;
	pt->right_node = NULL;

	if (left != right) {
		pt->left_node = init_node(left, (left + right) / 2);
		pt->right_node = init_node((left + right) / 2 + 1, right);
	}

	return pt;
}

void insert(struct NODE *nd, int val)
{
	++nd->count;
	if ((nd->left != val) || (nd->right != val)) {
		if ((nd->left_node != NULL) && (nd->left_node->left <= val) && (val <= nd->left_node->right))			insert(nd->left_node, val);
		else if ((nd->right_node != NULL) && (nd->right_node->left <= val) && (val <= nd->right_node->right))	insert(nd->right_node, val);
	}
}

long long get_answer(struct NODE *nd, int val)
{
	long long ret;
	ret = 0;

	if ((nd->left != val || nd->right != val)) {
		if ((nd->left_node != NULL) && (nd->left_node->left <= val) && (val <= nd->left_node->right)) {
			ret = get_answer(nd->left_node, val);
			if (nd->right_node != NULL) ret += nd->right_node->count;
		} else if ((nd->right_node != NULL) && (nd->right_node->left <= val) && (val <= nd->right_node->right)) {
			ret = get_answer(nd->right_node, val);
		}
	}

	--nd->count;
	return ret;
}

int main(void)
{
	int tc, T;
	int i;
	long long answer;

	node_size = 0;
	root = init_node(0, MAX);

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d\n", &N);

		for (i = 0; i <= node_size; ++i) {
			node[i].count = 0;
		}

		for (i = 0; i < N; ++i) {
			scanf("%d", &A[i]);
			insert(root, A[i]);
		}

		for (answer = 0, i = N - 1; i >= 0; --i) {
			answer += get_answer(root, A[i]);
		}

		printf("%lld\n", answer);
	}

	return 0;
}


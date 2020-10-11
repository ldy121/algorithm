#include <stdio.h>

#define MAX (100000)
#define INVALID (-1)

struct NODE {
	int left;
	int right;
	int value;

	struct NODE *left_node;
	struct NODE *right_node;
};

struct NODE max_tree[(MAX + 1) * 2 + 1];
struct NODE min_tree[(MAX + 1) * 2 + 1];

int N, Q;
int index;
int buffer[MAX + 1];

struct NODE * init(struct NODE tree[], int left, int right)
{
	struct NODE *ret;

	ret = &tree[index++];
	ret->left = left;
	ret->right = right;
	ret->value = INVALID;

	if (left < right) {
		ret->left_node = init(tree, left, (left + right) / 2);
		ret->right_node = init(tree, (left + right) / 2 + 1, right);
	} else {
		ret->left_node = NULL;
		ret->right_node = NULL;
	}

	return ret;
}

int insert_max_tree(struct NODE *nd)
{
	int val, ret;

	if (nd->left_node != NULL)	val = insert_max_tree(nd->left_node);
	else						val = INVALID;

	if (nd->right_node != NULL)	{
		ret = insert_max_tree(nd->right_node);
		if ((val == INVALID) || (val < ret)) val = ret;
	}

	if (val == INVALID)	nd->value = buffer[nd->left];
	else				nd->value = val;

	return nd->value;
}

int insert_min_tree(struct NODE *nd)
{
	int val, ret;

	if (nd->left_node != NULL)	val = insert_min_tree(nd->left_node);
	else						val = INVALID;

	if (nd->right_node != NULL)	{
		ret = insert_min_tree(nd->right_node);
		if ((val == INVALID) || (val > ret)) val = ret;
	}

	if (val == INVALID)	nd->value = buffer[nd->left];
	else				nd->value = val;

	return nd->value;

	return nd->value;
}

int find_max_tree(struct NODE *nd, int left, int right)
{
	int ret1, ret2;

	if ((nd->left == left) && (nd->right == right))	{
		return nd->value;
	} else {
		ret1 = INVALID;
		ret2 = INVALID;

		if ((nd->left_node != NULL) && (left <= nd->left_node->right)) {
			ret1 = find_max_tree(nd->left_node, left, ((right < nd->left_node->right) ? (right) : (nd->left_node->right)));
		}

		if ((nd->right_node != NULL) && (right >= nd->right_node->left)) {
			ret2 = find_max_tree(nd->right_node, ((left > nd->right_node->left) ? (left) : (nd->right_node->left)), right);
		}
	}

	if (ret1 == INVALID)		return ret2;
	else if (ret2 == INVALID)	return ret1;
	else						return ((ret1 > ret2) ? ret1 : ret2);
}

int find_min_tree(struct NODE *nd, int left, int right)
{
	int ret1, ret2;

	if ((nd->left == left) && (nd->right == right))	{
		return nd->value;
	} else {
		ret1 = INVALID;
		ret2 = INVALID;

		if ((nd->left_node != NULL) && (left <= nd->left_node->right)) {
			ret1 = find_min_tree(nd->left_node, left, ((right < nd->left_node->right) ? (right) : (nd->left_node->right)));
		}

		if ((nd->right_node != NULL) && (right >= nd->right_node->left)) {
			ret2 = find_min_tree(nd->right_node, ((left > nd->right_node->left) ? (left) : (nd->right_node->left)), right);
		}
	}

	if (ret1 == INVALID)		return ret2;
	else if (ret2 == INVALID)	return ret1;
	else						return ((ret1 < ret2) ? ret1 : ret2);
}

int main(void)
{
	int tc, T;
	int i, a, b;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%d %d\n", &N, &Q);

		index = 0;
		init(min_tree, 0, N - 1);
		index = 0;
		init(max_tree, 0, N - 1);

		for (i = 0; i < N; ++i) {
			scanf("%d", &buffer[i]);
		}

		insert_max_tree(&max_tree[0]);
		insert_min_tree(&min_tree[0]);

		for (i = 0; i < Q; ++i) {
			scanf("%d %d\n", &a, &b);
			printf("%d\n", find_max_tree(&max_tree[0], a, b) - find_min_tree(&min_tree[0], a, b));
		}
	}

	return 0;
}

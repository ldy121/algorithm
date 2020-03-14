#include <stdio.h>

#define MAX (1000)

struct NODE {
	struct NODE *first;
	struct NODE *second;
	struct NODE *third;
	struct NODE *forth;
	int start;
	int end;
};

struct NODE node[MAX * 2];

int node_index;
char tree[MAX + 1];

struct NODE *traversal(int index)
{
	struct NODE * ret;
	ret = &node[node_index++];

	if (tree[index] == 'x') {
		ret->first = traversal(index + 1);
		ret->second = traversal(ret->first->end + 1);
		ret->third = traversal(ret->second->end + 1);
		ret->forth = traversal(ret->third->end + 1);

		ret->start = index;
		ret->end = ret->forth->end;
	} else {
		ret->first = NULL;
		ret->second = NULL;
		ret->third = NULL;
		ret->forth = NULL;

		ret->start = index;
		ret->end = index;
	}

	return ret;
}

void get_answer(struct NODE * root)
{
	printf("%c", tree[root->start]);
	if (tree[root->start] == 'x') {
		get_answer(root->third);
		get_answer(root->forth);

		get_answer(root->first);
		get_answer(root->second);
	}
}

int main(void)
{
	int tc, T;
	struct NODE * root;

//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (tc = 0; tc < T; ++tc) {
		scanf("%s\n", tree);
		node_index = 0;
		root = traversal(0);
		get_answer(root);
		printf("\n");
	}

	return 0;
}

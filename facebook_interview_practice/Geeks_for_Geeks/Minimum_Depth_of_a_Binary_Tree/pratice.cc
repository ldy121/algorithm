#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
/*You are required to complete this method*/
int minDepth(Node *node)
{
	queue<Node *> q;
	int answer = 0;
	q.push(node);
	for (++answer; !q.empty(); ++answer) {
		for (int size = q.size(); size > 0; --size) {
			Node * nd = q.front();
			q.pop();
			if ((nd->left == NULL) && (nd->right == NULL)) {
				return answer;
			}
			if (nd->left != NULL)  q.push(nd->left);
			if (nd->right != NULL) q.push(nd->right);
		}
	}
	return answer;
}
 

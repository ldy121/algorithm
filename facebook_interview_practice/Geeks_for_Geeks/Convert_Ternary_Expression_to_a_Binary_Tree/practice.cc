#include <iostream>
#include <string>
#include <stack>

using namespace std;

class node {
	public :
		node(char val) : m_val(val), m_left(NULL), m_right(NULL){};
		char m_val;
		node * m_left;
		node * m_right;
};

node * get_answer(string& str, int &idx)
{
	node * nd = NULL;
	char val = str[idx++];

	if ('a' <= val && val <= 'z') {
		nd = new node(val);
		if ((idx < str.length()) && (str[idx++] == '?')) {
			nd->m_left  = get_answer(str, idx);
			nd->m_right = get_answer(str, idx);
		}
	}


	return nd;
}

void print_node(node * nd)
{
	if (nd != NULL) {
		cout << nd->m_val << endl;
		if (nd->m_left != NULL) {
			cout << nd->m_val << " left : ";
			print_node(nd->m_left);
		}
		if (nd->m_right != NULL) {
			cout << nd->m_val << " right : ";
			print_node(nd->m_right);
		}
	}
}

int main(void)
{
	int idx = 0;
	string test1 = string("a?b:c");
	string test2 = string("a?b?c:d:e");

	node * root1 = get_answer(test1, idx);
	print_node(root1);
	idx = 0;
	node * root2 = get_answer(test2, idx);
	print_node(root2);
}

#include <iostream>
#include <queue>

using namespace std;

class point {
	public :
		point(int row, int col) : m_row(row), m_col(col) {}
		int m_row;
		int m_col;
};

int get_answer(int m, int n) {
	queue<point> q[2];
	int push_queue = 0, pop_queue = 1;
	int answer = 0;

	q[push_queue].push(point(1, 1));
	for (pop_queue = push_queue; !q[pop_queue].empty(); pop_queue = push_queue) {
		push_queue = !push_queue;
		while (!q[pop_queue].empty()) {
			int row = q[pop_queue].front().m_row;
			int col = q[pop_queue].front().m_col;

			q[pop_queue].pop();

			if ((row == m) && (col == n)) {
				++answer;
			} else {
				if (row < m) q[push_queue].push(point(row + 1, col));
				if (col < n) q[push_queue].push(point(row, col + 1));
			}
		}
	}

	return answer;
}

int main(void)
{
	cout << get_answer(2, 3) << endl;
	cout << get_answer(3, 3) << endl;
}
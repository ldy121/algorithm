#include <iostream>
#include <vector>
using namespace std;
const int N = 9;

class point {
public :
  point(int row, int col) : m_row(row), m_col(col) {};
  int m_row;
  int m_col;
};
bool getAnswer(vector<vector<int > > &small, vector<int> &rows, vector<int> &cols, 
    vector<point> &empty,int idx) {

  if (idx == empty.size()) {
    return true;
  }

  int row = empty[idx].m_row;
  int col = empty[idx].m_col;

  for (int i = 1; i <= N; ++i) {
    int mask = 1 << i;
    if ((small[row / 3][col / 3] & mask) > 0) {
      continue;
    }
    if ((rows[row] & mask) > 0) {
      continue;
    }
    if ((cols[col] & mask) > 0) {
      continue;
    }
    small[row / 3][col / 3] |= mask;
    rows[row] |= mask;
    cols[col] |= mask;
    if (getAnswer(small, rows, cols, empty, idx + 1)) {
      return true;
    }
    small[row / 3][col / 3] &= ~mask;
    rows[row] &= ~mask;
    cols[col] &= ~mask;
  }

  return false;
}

int main() {
  int T;

  for (cin >> T; T > 0; --T) {
    vector<vector<int > > small;
    vector<point> empty;
    vector<int> rows(9, 0);
    vector<int> cols(9, 0);
    bool answer = true;

    for (int i = 0; i < 3; ++i) {
      vector<int> vec(3, 0);
      small.push_back(vec);
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        int val;
        cin >> val;
        if (val > 0) {
          int mask = 1 << val;
          rows[i] |= mask;
          cols[j] |= mask;
          small[i / 3][j / 3] |= mask;
        } else {
          empty.push_back(point(i, j));
        }
      }
    }

    bool result = getAnswer(small, rows, cols, empty, 0);
    cout << result << endl;
  }
  return 0;
}

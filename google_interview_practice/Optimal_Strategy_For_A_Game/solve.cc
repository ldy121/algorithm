#include <iostream>
#include <vector>

using namespace std;

const int init = -1;

int getAnswer(vector<int> &A, vector<vector<int> > &answer, int left, int right) {
  if (left > right) {
    return 0;
  }
  if (answer[left][right] != init) {
    return answer[left][right];
  }
  int leftleft = getAnswer(A, answer, left + 2, right);
  int leftright = getAnswer(A, answer, left + 1, right - 1);
  int l = (leftleft < leftright) ? (A[left] + leftleft) : (A[left] + leftright);
 
  int rightleft = getAnswer(A, answer, left + 1, right - 1);
  int rightright = getAnswer(A, answer, left, right - 2);
  int r = (rightleft < rightright) ? (A[right] + rightleft) : (A[right] + rightright);

  answer[left][right] = (l > r) ? l : r;
  return answer[left][right];
}

int main(void) {
  int T;
  for (cin >> T; T > 0; --T) {
    int N;
    vector<int> A;
    vector<vector <int> > answer;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      int val;
      vector<int> vec(N, init);
      cin >> val;
      A.push_back(val);
      answer.push_back(vec);
    }
    cout << getAnswer(A, answer, 0, A.size() - 1) << endl;
  }
}

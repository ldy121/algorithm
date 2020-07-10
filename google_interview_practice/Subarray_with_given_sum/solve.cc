#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
  int T;
  for (cin >> T; T > 0; --T) {
    vector<int> A;
    queue<int> q;
    int N, S, s = 0;
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
      int val;
      cin >> val;
      A.push_back(val);
    }

    for (int i = 0; i < N; ++i) {
      s += A[i];
      q.push(i);
      while (s > S) {
        s -= A[q.front()];
        q.pop();
      }
      if (s == S) {
        cout << (q.front() + 1 ) << " " << (i + 1) << endl;
        break;
      }
    }
    if (s != S) {
      cout << -1 << endl;
    }
  }
  return 0;
}

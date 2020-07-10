#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
  for (cin >> T; T > 0; --T) {
    int N, W;
    cin >> N >> W;
    vector<int> answer(W + 1, 0);
    vector<int> wt, val;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int j;
      cin >> j;
      val.push_back(j);
    }
    for (int i = 0; i < N; ++i) {
      int j;
      cin >> j;
      wt.push_back(j);
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < W; ++j) {
         int weight = wt[i] + j;
         int value = val[i] + answer[j];
         if (weight <= W && answer[weight] < value) {
           answer[weight] = value;
           if (ans < value) {
             ans = value;
           }
         }
      }
    }
    cout << ans << endl;
  }
	return 0;
}

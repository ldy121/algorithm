#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void getJumpNumber(vector<int> &jumpNumber, int val, int N)
{
  if (val > N) {
    return;
  } else {
    jumpNumber.push_back(val);
  }

  int last = val % 10;
  if (last + 1 < 10) {
    getJumpNumber(jumpNumber, val * 10 + last + 1, N);
  }

  if (last - 1 >= 0) {
    getJumpNumber(jumpNumber, val * 10 + last - 1, N);
  }
}

int main() {
  int T;
  for (cin >> T; T > 0; --T) {
    int N;
    cin >> N;
    if (N > 10) {
      vector<int> jumpNumber;
      int prev = -1;
      jumpNumber.push_back(0);
      for (int i = 1; i < 10; ++i) {
        getJumpNumber(jumpNumber, i, N);
      }
      sort(jumpNumber.begin(), jumpNumber.end());

      for (int i = 0; i < jumpNumber.size(); ++i) {
        if (prev != jumpNumber[i]) {
          cout << jumpNumber[i] << " ";
          prev = jumpNumber[i];
        }
      }
    } else {
      for (int i = 0; i <= N; ++i) {
        cout << i << " ";
      } 
    }
    cout << endl;
  }
	return 0;
}

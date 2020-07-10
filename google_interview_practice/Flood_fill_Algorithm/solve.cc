#include <iostream>
#include <vector>

using namespace std;

void getAnswer(vector<vector<int> > &screen, int y, int x, int srcColor, int dstColor) {
  if (x < 0 || y < 0 || y >= screen.size() || x >= screen[0].size() || screen[y][x] != srcColor)  {
    return;
  }
  screen[y][x] = dstColor;

  getAnswer(screen, y, x - 1, srcColor, dstColor);
  getAnswer(screen, y, x + 1, srcColor, dstColor);
  getAnswer(screen, y - 1, x, srcColor, dstColor);
  getAnswer(screen, y + 1, x, srcColor, dstColor);
}

int main() {
  int T;
  for (cin >> T; T > 0; --T) {
    vector<vector<int> > screen;
    int x, y, n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      vector<int> vec;
      for (int j = 0; j < m; ++j) {
        int val;
        cin >> val;
        vec.push_back(val);
      }
      screen.push_back(vec);
    }
    cin >> y >> x >> k;
    getAnswer(screen, y, x, screen[y][x], k);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << screen[i][j] << " ";
      }
    }
    cout << endl;
  }
	return 0;
}

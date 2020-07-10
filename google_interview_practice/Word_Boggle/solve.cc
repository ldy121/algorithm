#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const char visit = '^';

bool isBoggle(string& str, int idx, vector<vector<char> > &boggle, int row, int col) {
  if (idx == str.length()) {
    return true;
  }
  if (row < 0 || col < 0 || row >= boggle.size() || col >= boggle[0].size() || str[idx] != boggle[row][col]) {
    return false;
  } else {
    boggle[row][col] = visit;
  }

  bool ret = isBoggle(str, idx + 1, boggle, row - 1, col - 1) ||
							isBoggle(str, idx + 1, boggle, row - 1, col + 1) ||
							isBoggle(str, idx + 1, boggle, row - 1, col) ||
							isBoggle(str, idx + 1, boggle, row + 1, col - 1) ||
							isBoggle(str, idx + 1, boggle, row + 1, col + 1) ||
							isBoggle(str, idx + 1, boggle, row + 1, col) ||
							isBoggle(str, idx + 1, boggle, row, col - 1) ||
							isBoggle(str, idx + 1, boggle, row, col + 1);

  boggle[row][col] = str[idx];
  return ret;
}


int main(void) {
  int T;

  for (cin >> T; T > 0; --T) {
    vector<string> dictionary;
    vector<vector <char> > boggle;
		vector<string> answer;
		string prev;
    int n, m, x;
    cin >> x;
    for (int i = 0; i < x; ++i) {
      string str;
      cin >> str;
      dictionary.push_back(str);
    }
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
      vector<char> vec;
      for (int j = 0; j < m; ++j) {
        char ch;
        cin >> ch;
        vec.push_back(ch);
      }
      boggle.push_back(vec);
    }
    for (int k = 0; k < x; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (isBoggle(dictionary[k], 0, boggle, i, j)) {
						answer.push_back(dictionary[k]);
            i = n;
            break;
          }
        }
      }
    }
		sort(answer.begin(), answer.end());
		if (answer.size() > 0) {
			for (int i = 0; i < answer.size(); ++i) {
				if (prev != answer[i]) {
				  cout << answer[i] << " ";
					prev = answer[i];
				}
			}
			cout << endl;
		} else {
      cout << -1 << endl;
		}
  }

  return 0;
}


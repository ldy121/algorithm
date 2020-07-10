#include <string>

using namespace std;
/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/
string findOrder(string dict[], int N, int K) {
  vector<vector <int > > answer;
  vector<int> visit(K, 0);
  string ret;

  for (int i = 0; i < K; ++i) {
    vector<int> vec(K, 0);
    answer.push_back(vec);
  }

  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < dict[i].length() && j < dict[i - 1].length(); ++j) {
      if (dict[i][j] != dict[i - 1][j]) {
        answer[dict[i][j] - 'a'][dict[i - 1][j] - 'a'] = 1;
        break;
      }
    }
  }

  for (int k = 0; k < K; ++k) {
    int i;
    for (int j = 0; j < K; ++j) {
      int l;
      if (visit[j]) {
        continue;
      }
      for (l = 0; l < K; ++l) {
        if (answer[j][l]) {
           break;
        }
      }
      if (l == K) {
        i = j;
      }
    }
    for (int j = 0; j < K; ++j) {
      answer[j][i] = 0;
    }
    visit[i] = 1;
    ret += ('a' + i);
  }
  return ret;
}



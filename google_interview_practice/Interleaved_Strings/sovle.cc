/*You are required to complete this method */

const int init = -1;
int interleave(vector<vector<int> > &answer, string &A, string &B, string &C, int a, int b, int c)
{
  if (a == A.length() && b == B.length() && c == C.length()) {
    return 1;
  }

  if (c == C.length()) {
    return 0;
  }

  if (answer[a][b] != init) {
    return answer[a][b];
  }

  answer[a][b] = (a < A.length() && A[a] == C[c] && interleave(answer, A, B, C, a + 1, b, c + 1))
        || (b < B.length() && B[b] == C[c] && interleave(answer, A, B, C, a, b+ 1, c + 1));
  return answer[a][b];
}

bool isInterleave(string A, string B, string C) {
  vector<vector <int> > answer;
  for (int i = 0; i <= A.length(); ++i) {
    vector<int> vec(B.length() + 1, init);
    answer.push_back(vec);
  }
  return interleave(answer, A, B, C, 0, 0, 0) > 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solution1() {
	int T;
  for (cin >> T; T > 0; --T) {
    unordered_map<int, int> hash;
    vector<int> key;
    int N, a = -1, b = -1;
    cin >> N;
    for (N = N * 2 + 2; N > 0; --N) {
      int val;
      cin >> val;
      if (hash.find(val) == hash.end()) {
        key.push_back(val);
        hash[val] = 0;
      }
      ++hash[val];
    }
    for (int i = 0; i < key.size(); ++i) {
      if (hash[key[i]] % 2 == 1) {
        if (a == -1) {
          a = key[i];
        } else {
          b = key[i];
        }
      }
    }
    if (a < b) {
      cout << a << " " << b << endl;
    } else {
      cout << b << " " << a << endl;
    }
  }
}

void solution2() {
	int T;
  for (cin >> T; T > 0; --T) {
    int N, a = 0, b = 0, x = 0, lsb;
    vector<int> vec;
    cin >> N;
    for (N = N * 2 + 2; N > 0; --N) {
      int val;
      cin >> val;
      vec.push_back(val);
      x ^= val;
    }
    lsb = x & ~(x - 1);
    for (int i = 0; i < vec.size(); ++i) {
      if (lsb & vec[i]) {
        a ^= vec[i];
      } else {
        b ^= vec[i];
      }
    }
    if (a < b) {
      cout << a << " " << b << endl;
    } else {
      cout << b << " " << a << endl;
    }
  }
}

int main() {
  solution2();
  return 0;
}

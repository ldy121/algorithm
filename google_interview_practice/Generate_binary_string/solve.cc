#include <iostream>
#include <string>

using namespace std;
int count = 0;
void getAnswer(string &str, int idx) {
  if (idx < str.length()) {
    if (str[idx] == '?') {
      str[idx] = '0';
      getAnswer(str, idx + 1);
      str[idx] = '1';
      getAnswer(str, idx + 1);
      str[idx] = '?';
    } else {
      getAnswer(str, idx + 1);
    }
  } else {
		++count;
    cout << str << " ";
  }
}

int main() {
  int T;
  for (cin >> T; T > 0; --T) {
    string str;
    getAnswer(str, 0);
		cout << endl;
  }
	return 0;
}

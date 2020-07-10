#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string s;
	cin >> T;
	getline(cin,s);
	for (; T > 0; --T) {
	    int left, right;
	    string str;
	    getline(cin,str);
	    for (left = 0, right = str.length() - 1;
	        left < str.length() && right >= 0; ++left, --right) {
			while(left < str.length()) {
				if ('a' <= str[left] && str[left] <= 'z') {
					break;
				}
				if ('0' <= str[left] && str[left] <= '9') {
				    break;
				}
				if ('A' <= str[left] && str[left] <= 'Z') {
					str[left] = str[left] - 'A' + 'a';
					break;
				} else {
					++left;
				}
			}
			while(right >= 0) {
				if ('a' <= str[right] && str[right] <= 'z') {
					break;
				}
				if ('0' <= str[right] && str[right] <= '9') {
				    break;
				}
				if ('A' <= str[right] && str[right] <= 'Z') {
					str[right] = str[right] - 'A' + 'a';
					break;
				} else {
					--right;
				}
			}
			if (left >= str.length()) {
				break;
			}
			if (right < 0) {
				break;
			}
			if (str[left] != str[right]) {
				break;
			}
	    }
		cout << ((left == str.length() && right < 0) ? "YES" : "NO") << endl;
	}
	return 0;
}


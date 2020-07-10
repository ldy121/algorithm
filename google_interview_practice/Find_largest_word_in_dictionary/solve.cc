#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
	    vector<string> dict;
	    vector<int> idx;
	    string str;
	    int N;
	    int answer = -1;
	    int max = 0;
	    cin >> N;
	    for (int i = 0; i < N; ++i) {
	        string s;
	        cin >> s;
	        dict.push_back(s);
	        idx.push_back(0);
	    }
	    cin >> str;
	    for (int i = 0; i < str.length(); ++i) {
	        for (int j = 0; j < dict.size(); ++j) {
	            if (idx[j] == dict[j].length()) {
	                continue;
	            }
	            if (str[i] == dict[j][idx[j]]) {
	                ++idx[j];
	            }
	            if (idx[j] == dict[j].length() && max < dict[j].length()) {
	                max = dict[j].length();
	                answer = j;
	            }
	        }
	    }
	    cout << dict[answer] << endl;
	}
	return 0;
}
